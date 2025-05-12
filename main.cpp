#include "mbed.h"

// Shift register pins
DigitalOut serPin(D8);    // Serial data
DigitalOut clkPin(D7);    // Clock
DigitalOut latchPin(D4);  // Latch

// Inputs
AnalogIn voltagePin(A0);
DigitalIn s1Switch(A1);  // Reset
DigitalIn s3Switch(A3);  // Show voltage

// Common anode: segment ON = 0, OFF = 1
// Segment values for 0-9 (common anode, active LOW)
const uint8_t seg_digits[] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};

// Digit selector masks (active HIGH)
const uint8_t digit_sel[4] = {
    0b00000001,  // Enable digit 1 (D0, leftmost)
    0b00000010,  // Enable digit 2 (D1)
    0b00000100,  // Enable digit 3 (D2)
    0b00001000   // Enable digit 4 (D3, rightmost)
};

// Send 16 bits: first 8 for segments, then 8 for digit select (MSB first)
void shiftOut16(uint8_t seg_data, uint8_t digit_mask) {
    latchPin = 0;

    // Shift segment data first (MSB to LSB)
    for (int i = 7; i >= 0; i--) {
        serPin = (seg_data >> i) & 0x01;
        clkPin = 1;
        clkPin = 0;
    }

    // Then shift digit select (MSB to LSB)
    for (int i = 7; i >= 0; i--) {
        serPin = (digit_mask >> i) & 0x01;
        clkPin = 1;
        clkPin = 0;
    }

    latchPin = 1;
}

void displayVoltPot(int volt_pot) {
    int d[4] = {
        (volt_pot / 1000) % 10,  // Thousands place (D3)
        (volt_pot / 100) % 10,   // Hundreds place (D2)
        (volt_pot / 10) % 10,    // Tens place (D1)
        volt_pot % 10            // Ones place (D0)
    };

    // Reverse the digit selection order to display from D0 to D3
    for (int i = 0; i < 4; i++) {
        uint8_t seg = seg_digits[d[i]];
        if (i == 1) seg &= ~(1 << 7);  // Add decimal point to D3 for voltage display
        shiftOut16(seg, digit_sel[i]);  // Send the corresponding digit selection
        wait_us(2000);  // Small delay for stability
    }
}

// Read and average the voltage over multiple samples to increase stability
float getStableVoltage() {
    const int sampleCount = 50; // Number of samples to average
    float sum = 0;

    for (int i = 0; i < sampleCount; i++) {
        sum += voltagePin.read();  // Read voltage value (0.0 to 1.0)
        wait_us(100);  // Small delay between readings
    }

    return (sum / sampleCount) * 5.0f;  // Convert to voltage (0.0V to 5.0V)
}

void displayTime(int min, int sec) {
    int d[4] = {
        (min / 10) % 10,  // Tens place of minutes (D3)
        min % 10,          // Ones place of minutes (D2)
        (sec / 10) % 10,   // Tens place of seconds (D1)
        sec % 10           // Ones place of seconds (D0)
    };

    // Reverse the digit selection order to display from D0 to D3
    for (int i = 0; i < 4; i++) {
        uint8_t seg = seg_digits[d[i]];
        shiftOut16(seg, digit_sel[i]);  // Send the corresponding digit selection
        wait_us(2000);  // Small delay for stability
    }
}

// Global variables
long long start_time = 0;
int timesec = 0;
int timemin = 0;

int main() {
    start_time = get_ms_count();

    while (true) {
        long long now = get_ms_count();

        // Update time every second
        if (now - start_time >= 1000) {
            start_time = now;
            timesec++;
            if (timesec >= 60) {
                timesec = 0;
                timemin++;
            }
        }

        // Show voltage when S3 is pressed
        if (s3Switch == 0) {
            float voltage = getStableVoltage();  // Read stable voltage
            int volt_int = (int)(voltage * 100);  // Convert to integer for display
            displayVoltPot(volt_int);  // Display voltage with decimal point
        } else {
            displayTime(timemin, timesec);  // Display time without decimal point
        }

        // Reset on S1 or 100 minutes
        if (s1Switch == 0 || timemin >= 100) {
            timemin = 0;
            timesec = 0;
        }
    }
}
