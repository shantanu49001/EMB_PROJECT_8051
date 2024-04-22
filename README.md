**Overview**
This project is a simple calculator implemented on the 8051 microcontroller using C programming language. The calculator supports basic arithmetic operations such as addition, subtraction, multiplication, and division. UART (Universal Asynchronous Receiver-Transmitter) communication is utilized for interfacing with external devices like a computer or another microcontroller.

**Features**
- Basic arithmetic operations: Addition, subtraction, multiplication, and division.
- UART communication for input and output.
- TMod register usage for setting UART baud rate.

**Requirements**
- 8051 microcontroller development board (e.g., AT89S52).
- Terminal emulator software (e.g., PuTTY, Tera Term) for UART communication with the microcontroller.
- 8051 development environment (e.g., Keil uVision, SDCC).
- Serial cable or USB-to-serial converter for connecting the microcontroller to the computer.

**Flow Diagram**
![Flow Diagram](flow_diagram.png)

**Output Screenshots**
![Screenshot 1](output1.png)
![Screenshot 2](output2.png)

**Usage**
1. Power on the 8051 microcontroller.
2. Open the terminal emulator software on your computer.
3. Set the baud rate of the terminal emulator to match the baud rate configured in the code.
4. The calculator will display a prompt indicating that it is ready to receive input.
5. Enter arithmetic expressions in the format: `<operand1> <operator> <operand2>`.
   - For example: `12 + 5`, `8 * 3`, `20 / 4`.
6. Press Enter to submit the expression.
7. The result of the calculation will be displayed on the terminal emulator.
