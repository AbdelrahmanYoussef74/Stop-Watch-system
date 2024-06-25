# Stop Watch System using ATmega32

This GitHub repository contains the code and documentation for a Stop Watch system implemented on an ATmega32 Microcontroller. The system incorporates the following specifications:

## Specifications

1. **Microcontroller**: ATmega32 with a clock frequency of 1 MHz.
2. **Timer Configuration**: Timer1 in ATmega32 is configured with CTC mode to measure the Stop Watch time.
3. **Display**: Six Common Anode 7-segment displays are employed.
4. **Multiplexing**: Multiplexing is employed to control all 7-segments using a single 7447 decoder and NPN BJT transistors for enable/disable control.
5. **Decoder Connection**: The 7447 decoder is connected to the first 4 pins of PORTC.
6. **Enable/Disable Pins**: The first 6 pins in PORTA are used for enabling/disabling the six 7-segments.
7. **Start**: The Stop Watch starts counting as soon as power is connected to the MCU.
8. **Reset**: An External Interrupt (INT0) with a falling edge is configured. A push button with an internal pull-up resistor can be used to reset the Stop Watch time.
9. **Pause**: External Interrupt (INT1) is configured with a rising edge. A push button with an external pull-down resistor can be used to pause the Stop Watch time.
10. **Resume**: External Interrupt (INT2) is configured with a falling edge. A push button with an internal pull-up resistor can be used to resume the Stop Watch time.
11. **Stop LED Indicators**: Added LED indicators to visually indicate the state of the stopwatch (running, paused, or stopped).
12. **Count Up and Count Down Enables**: Implemented count-up and count-down functionality to allow the user to choose the stopwatch mode.

## Usage

To simulate an ELF file in Proteus, follow these steps:
1. **Clone the Repository**: Clone this repository to your local machine:
    ```bash
   
2. **Compile ELF File**: Compile your code and generate an ELF file using your preferred AVR programming software (e.g., Atmel Studio).
3. **Create Proteus Project**: Open Proteus and create a new project for your simulation.
4. **Add Microcontroller**: Add the ATmega32 microcontroller to your Proteus project.
5. **Upload ELF File**: In Proteus, navigate to the microcontroller properties and upload the generated ELF file to the microcontroller. This will load your code into the virtual ATmega32.
6. **Hardware Connections**: Ensure that you have made the necessary hardware connections as specified in the project documentation, both in Proteus and in your real-world setup if applicable.
7. **Power On**: In the Proteus simulation, connect power to the virtual ATmega32. The Stop Watch will start counting automatically in the virtual environment.
8. **Reset**: To reset the Stop Watch in the simulation, trigger the button connected to the INT0 pin in Proteus.
9. **Pause/Resume**: To pause the Stop Watch in the simulation, trigger the button connected to the INT1 pin in Proteus. To resume, trigger the button connected to the INT2 pin.
10. **Choose Stopwatch Mode**: Use the count-up and count-down enables in the Proteus simulation to select the desired stopwatch mode for testing and evaluation.






