#include <reg51.h>
#include <math.h>
#define BAUDRATE 4800 // INTILAISE BAUD RATE

void UART_Init()
{
  TMOD = 0x20; // TIMER 1 MODE 2
  TH1 = 0xFA;  // 256 CLOCKS NEEDED TO PRODUCE REQUIRED DELAY
  TR1 = 1;     // START TIMER
  SCON = 0x50; // SRIAL MODE SELECTION
}

void UART_SendChar(char c)
{ // SEND CHARS SERIALLY TO SBUF
  SBUF = c;
  while (!TI)
    ;
  TI = 0;
}

char UART_ReceiveChar()
{ // RECEIVE CHARS SERIALLY FROM SBUF
  while (!RI)
    ;
  RI = 0;
  return SBUF;
}

void printDigits(unsigned char num)
{ // PRINTS DIGITS FROM NUMBER SERIALLY
  int divisor = 1;
  while (num / divisor >= 10)
  {
    divisor *= 10;
  }

  while (divisor != 0)
  {
    // printf("%d ", num / divisor);
    UART_SendChar(((unsigned char)(num / divisor) + '0')); // SBUF PRINTS CHAR WE HAVE INT ->TYPE CAST IT TO CHAR
    num %= divisor;
    divisor /= 10;
  }
}

void displayOptionMenu(unsigned char a, unsigned char b)
{ // UI MENU FOR USER TO TAKE USER INPUT

  unsigned char c = a;
  unsigned char d = b;
  unsigned char operand3;

  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('\n');

  operand3 = c;
  printDigits(c); // WHAT USER ENTERED OPERAND

  UART_SendChar(' ');
  operand3 = d;

  printDigits(d); // WHAT USER ENTERD OPERAND
  UART_SendChar('\n');
  UART_SendChar('A');
  UART_SendChar(':');
  UART_SendChar(' ');
  UART_SendChar('A');
  UART_SendChar('D');
  UART_SendChar('D');
  UART_SendChar('I');
  UART_SendChar('T');
  UART_SendChar('I');
  UART_SendChar('0');
  UART_SendChar('N');
  UART_SendChar('\n');

  UART_SendChar('B');
  UART_SendChar(':');
  UART_SendChar(' ');
  UART_SendChar('S');
  UART_SendChar('U');
  UART_SendChar('B');
  UART_SendChar('T');
  UART_SendChar('R');
  UART_SendChar('A');
  UART_SendChar('C');
  UART_SendChar('T');
  UART_SendChar('I');
  UART_SendChar('O');
  UART_SendChar('N');
  UART_SendChar('\n');

  UART_SendChar('C');
  UART_SendChar(':');
  UART_SendChar(' ');
  UART_SendChar('D');
  UART_SendChar('I');
  UART_SendChar('V');
  UART_SendChar('I');
  UART_SendChar('S');
  UART_SendChar('I');
  UART_SendChar('O');
  UART_SendChar('N');
  UART_SendChar('\n');

  UART_SendChar('D');
  UART_SendChar(':');
  UART_SendChar('S');
  UART_SendChar('Q');
  UART_SendChar('R');
  UART_SendChar('T');
  UART_SendChar('\n');

  UART_SendChar('E');
  UART_SendChar(':');
  UART_SendChar('M');
  UART_SendChar('U');
  UART_SendChar('L');
  UART_SendChar('\n');

  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('.');
  UART_SendChar('\n');
}

void take_input(unsigned char *a)
{ // TAKE USER INPUT

  *a = UART_ReceiveChar() - '0'; // SERIAL SBUF TAKES AND RETURNS CHAR; WE HAVE TO TYPE CAST IT TO INT
}

void main()
{
  unsigned char operand1;
  unsigned char operand2;

  UART_Init(); // INITLAISE UART FUNCTION FOR SERIAL INPUT
  UART_SendChar('E');
  UART_SendChar('N');
  UART_SendChar('T');
  UART_SendChar('E');
  UART_SendChar('R');
  UART_SendChar(' ');
  UART_SendChar('T');
  UART_SendChar('W');
  UART_SendChar('0');
  UART_SendChar(' ');
  UART_SendChar('3');
  UART_SendChar('B');
  UART_SendChar('I');
  UART_SendChar('T');
  UART_SendChar(' ');
  UART_SendChar('N');
  UART_SendChar('U');
  UART_SendChar('M');
  UART_SendChar('B');
  UART_SendChar('E');
  UART_SendChar('R');
  UART_SendChar('S');
  UART_SendChar('[');
  UART_SendChar('0');
  UART_SendChar('-');
  UART_SendChar('9');
  UART_SendChar(']');

  UART_SendChar(' ');

  UART_SendChar('W');
  UART_SendChar('I');
  UART_SendChar('T');
  UART_SendChar('H');
  UART_SendChar('O');
  UART_SendChar('U');
  UART_SendChar('T');
  UART_SendChar(' ');
  UART_SendChar('S');
  UART_SendChar('P');
  UART_SendChar('A');
  UART_SendChar('C');
  UART_SendChar('E');
  UART_SendChar('\n');
  UART_SendChar('\n');
  take_input(&operand1); // TAKE USER INPUT
  UART_SendChar('\n');

  take_input(&operand2); // TAKE USER INPUT
  while (1)
  {

    char receivedChar;

    displayOptionMenu(operand1, operand2); // DISPLAY THE OPTIONS MENU

    receivedChar = UART_ReceiveChar();

    if (receivedChar == 'A')
    { // SUPPORTED OPTION : addttion

      operand1 = operand1 + operand2;
      // operand3=operand1;
    }
    else if (receivedChar == 'B')
    { // supported operation: subtraction

      if (operand1 < operand2)
        operand1 = operand2 - operand1;
      else
        operand1 = operand1 - operand2;
    }
    else if (receivedChar == 'C')
    { // supported operation : division

      if (operand2 > operand1)
        operand2 = (unsigned char)(operand2 / operand1);
      else
        operand1 = (unsigned char)(operand1 / operand2);
    }
    else if (receivedChar == 'D')
    { // supported operation sqrt

      operand2 = sqrt(operand2);
    }
    else if (receivedChar == 'E')
    { // supported operation: multiplicaton
      operand2 = operand2 * operand1;
    }

    // END OF PRORAMME.
  }
}