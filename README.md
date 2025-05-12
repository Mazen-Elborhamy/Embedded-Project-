<p>
  <img src="https://github.com/Mazen-Elborhamy/Embedded-Project-/raw/main/Report%20%26%20Video/download.png" alt="Download Icon" width="400" align="left"/>
</p>
<br clear="all"/>


<table style="width: 100%; text-align: center; border: 2px solid black; border-collapse: collapse;">
  <tr style="height: 40px;">
    <th style="border: 2px solid black; padding: 15px;">Name</th>
    <th style="border: 2px solid black; padding: 15px;">ID</th>
  </tr>
  <tr style="height: 40px;">
    <td style="border: 2px solid black; padding: 15px;">Mazen Ashraf Mohamed</td>
    <td style="border: 2px solid black; padding: 15px;">2200822</td>
  </tr>
  <tr style="height: 40px;">
    <td style="border: 2px solid black; padding: 15px;">Yasser Mohamed Abdallah</td>
    <td style="border: 2px solid black; padding: 15px;">2200732</td>
  </tr>
</table>



# Embedded Project: Real-Time Clock and Voltage Display

This project uses the **STM32 Nucleo F401RE** board along with the **Arduino Multifunction Shield** to display a **real-time clock** (RTC) and **voltage readings** on a **4-digit 7-segment display**. The voltage is read through a **potentiometer** and displayed when the **S3 switch** is pressed. The program continuously counts time in the background.


## Features:
- **Real-Time Clock** displayed on a 4-digit 7-segment display.
- **Voltage** display from a potentiometer when **S3** is pressed.
- **Reset** functionality when **S1** is pressed, or when the time reaches 100 minutes.

## Components:
- **STM32 Nucleo F401RE** board
- **Arduino Multifunction Shield**
  - **4-digit 7-segment display**
  - **Potentiometer**
  - **3 switches (S1, S2, S3)**

## Pin Setup:
- **Shift Register Pins** for controlling the 7-segment display:
  - `DigitalOut serPin(D8)`  - Serial Data
  - `DigitalOut clkPin(D7)`  - Clock
  - `DigitalOut latchPin(D4)` - Latch
- **Inputs:**
  - `AnalogIn voltagePin(A0)`  - Potentiometer
  - `DigitalIn s1Switch(A1)`   - Reset
  - `DigitalIn s3Switch(A3)`   - Show Voltage

## Application Functionality:
The program runs in a **single-threaded** loop, with the **real-time clock** being updated every second. When the **S3 switch** is pressed, it will display the voltage read from the potentiometer. When **S1** is pressed or after **100 minutes**, the timer resets to `00:00`.

## Build Instructions:

1. **Install Mbed OS**:
   Ensure you have the **Mbed OS** installed on your machine. You can follow the [official installation guide](https://os.mbed.com/studio/) to set up the necessary tools.

2. **Import the Project**:
   Clone the repository or download the project files. Open a terminal and navigate to your project directory.

3. **Build the Project**:
   To build and flash the project onto your **STM32 Nucleo F401RE** board, follow these steps:
   - Connect your **Nucleo F401RE** board via USB to your computer.
   - Open a terminal and run the following command to build the project:

   ```bash
   mbed compile -m NUCLEO_F401RE -t GCC_ARM --flash

# Embedded Project: Real-Time Clock and Voltage Display

This project uses the **STM32 Nucleo F401RE** board along with the **Arduino Multifunction Shield** to display a **real-time clock** (RTC) and **voltage readings** on a **4-digit 7-segment display**. The voltage is read through a **potentiometer** and displayed when the **S3 switch** is pressed. The program continuously counts time in the background.

## Features:
- **Real-Time Clock** displayed on a 4-digit 7-segment display.
- **Voltage** display from a potentiometer when **S3** is pressed.
- **Reset** functionality when **S1** is pressed, or when the time reaches 100 minutes.

## Components:
- **STM32 Nucleo F401RE** board
- **Arduino Multifunction Shield**
  - **4-digit 7-segment display**
  - **Potentiometer**
  - **3 switches (S1, S2, S3)**

## Pin Setup:
- **Shift Register Pins** for controlling the 7-segment display:
  - `DigitalOut serPin(D8)`  - Serial Data
  - `DigitalOut clkPin(D7)`  - Clock
  - `DigitalOut latchPin(D4)` - Latch
- **Inputs:**
  - `AnalogIn voltagePin(A0)`  - Potentiometer
  - `DigitalIn s1Switch(A1)`   - Reset
  - `DigitalIn s3Switch(A3)`   - Show Voltage

## Application Functionality:
The program runs in a **single-threaded** loop, with the **real-time clock** being updated every second. When the **S3 switch** is pressed, it will display the voltage read from the potentiometer. When **S1** is pressed or after **100 minutes**, the timer resets to `00:00`.

## Build Instructions:

1. **Install Mbed OS**:
   Ensure you have the **Mbed OS** installed on your machine. You can follow the [official installation guide](https://os.mbed.com/studio/) to set up the necessary tools.

2. **Import the Project**:
   Clone the repository or download the project files. Open a terminal and navigate to your project directory.

3. **Build the Project**:
   To build and flash the project onto your **STM32 Nucleo F401RE** board, follow these steps:
   - Connect your **Nucleo F401RE** board via USB to your computer.
   - Open a terminal and run the following command to build the project:

   ```bash
   mbed compile -m NUCLEO_F401RE -t GCC_ARM --flash

<h2>📹 Project Video </h2>

<a href="https://drive.google.com/file/d/1s7I7npO2QUiUPna9hscxqAzC01U5uYPd/view?usp=drive_link" target="_blank">
  <img src="https://github.com/Mazen-Elborhamy/Embedded-Project-/raw/main/Report%20%26%20Video/Screenshot%202025-05-12%20150740.jpg" alt="Watch the video" width="300"/>
</a>

<h2>📄 Project Report</h2>

<a href="https://github.com/Mazen-Elborhamy/Embedded-Project-/blob/main/Report%20%26%20Video/Embedded%20Project%20report.pdf" target="_blank">
  <img src="https://github.com/Mazen-Elborhamy/Embedded-Project-/raw/main/Report%20%26%20Video/Screenshot%202025-05-12%20171725.png" alt="Open Project Report" width="300"/>
</a>


