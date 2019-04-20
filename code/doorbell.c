#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 5

#define BAUD 9600

#include <util/setbaud.h>

#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <string.h>

#define LED 5
#define BUSY 0

char mystr[]="Atmega8 UART ready!\n";
char rc;
unsigned int playing = 0, intensity=0;

int LED7test(void);

/* void lampOFF() */
/* { */
/*     PORTB.0=0; */
/* } */

/* void lampON() */
/* { */
/*     PORTB.0=1; */
/* } */


int uart_putchar(char c, struct __file * unused) {
    loop_until_bit_is_set(UCSR0A, UDRE0); /* Wait until data register empty. */
    UDR0 = c;
    // loop_until_bit_is_set(UCSRA, TXC); /* Wait until transmission ready. */
    return 0;
}

int uart_getchar(struct __file * unused) {
    loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
    return UDR0;
}

int prints(char s[]) {
  int i=0;
  while (s[i]) {
    uart_putchar(s[i++], NULL);
  }
  return 0;
}

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);
//FILE uart_io FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);


void uart_init()
{
    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
    UCSR0A &= ~(_BV(U2X0));
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;
}

union pulses_u {
  struct {
    unsigned int low, high;
  } p;
  unsigned long int all;
} pulses;

unsigned int time=0, ticks = 0;

// unsigned long period=0; // TODO: store it in PROGMEM

#define PERIOD 61

unsigned int get_part() {
  unsigned int val;
  unsigned char sreg;
  sreg=SREG;
  val = TCNT1;
  SREG=sreg;
  return val;
}

void timer_tick() {
  if ((PINB & (1<<BUSY)) == 0) {
    PORTB ^= 1 << LED;
    playing = 1;
  } else {
    PORTB &=~(1<<LED);
    playing = 0;
    //LED7test();
  }
}

ISR(TIMER0_OVF_vect) { // Time1 overflow

  TIFR0 |= (1<<TOV0); // clear overflow flag

  time++;
  if (PERIOD!=0) {
    if (time>=PERIOD) {
      timer_tick();
      time = 0;
    }
  } else {
      timer_tick();
      time = 0;
  }
}

void timer_init() {
  // TCCR1B = (1<<CS12)|(1<<CS11);
  // TIMSK |= (1<<TOIE1); // Enable Overflow interrupt for Counter5.

  TCCR0B |= (1<<CS02)|(1<<CS00);
  //0B
  TIMSK0 |= (1<<TOIE0); // Enable Overflow interrupt for Counter0 (8bit).
  //TIFR0
  sei();
};

#define STEPS 5000
#define DELAY 1000

int main() {

  uart_init();
  timer_init();

  // stdout = &uart_output;
  // stdin  = &uart_input;

  // TEST
  //DDRL  = 0x00;
  //PORTL = 0x00;
  //DDRD |= 1<<6;

  DDRB |= 1<<LED;
  DDRB &= ~(1<<BUSY);
  PORTB &= ~(1<<LED);


  // unsigned long int pp = 0;

  // _delay_ms(DELAY);

  // printf("Starting:\n");

  for (;;)  {
    /* pulses.p.low = get_part(); */
    /* // printf("Count: o:%u %lu (+%lu / sec) time: %u ", pulses.p.high, pulses.all, (pulses.all-pp), ticks); */
    /* printf("Count: o:%u %lu (pp =%lu) time: %u ", pulses.p.high, pulses.all, pp, ticks); */
    /* printf("\n"); */
    /* pp=pulses.all; */
    /* _delay_ms(DELAY); */
    if (! playing)
      LED7test();

    sleep_mode();
  }
  return 0;
}


// Taken from https://gist.githubusercontent.com/adnbr/2352797/raw/b5e33d85167e6b562a6b4720921a2955eb3cc631/max7219-basic.c

/* MAX7219 Interaction Code
 * ---------------------------
 * For more information see
 * http://www.adnbr.co.uk/articles/max7219-and-7-segment-displays
 *
 * 668 bytes - ATmega168 - 16MHz
 */

// 16MHz clock
// #define F_CPU 16000000UL

// Outputs, pin definitions
#define PIN_SCK                   PORTB5
#define PIN_MOSI                  PORTB3
#define PIN_SS                    PORTB2

#define ON                        1
#define OFF                       0

#define MAX7219_LOAD1             PORTB |= (1<<PIN_SS)
#define MAX7219_LOAD0             PORTB &= ~(1<<PIN_SS)

#define MAX7219_MODE_DECODE       0x09
#define MAX7219_MODE_INTENSITY    0x0A
#define MAX7219_MODE_SCAN_LIMIT   0x0B
#define MAX7219_MODE_POWER        0x0C
#define MAX7219_MODE_TEST         0x0F
#define MAX7219_MODE_NOOP         0x00

// I only have 3 digits, no point having the
// rest. You could use more though.
#define MAX7219_DIGIT0            0x01
#define MAX7219_DIGIT1            0x02
#define MAX7219_DIGIT2            0x03

#define MAX7219_CHAR_BLANK        0xF
#define MAX7219_CHAR_NEGATIVE     0xA

// #include <avr/io.h>
// #include <util/delay.h>

char digitsInUse = 8;

unsigned int D[8] = {0,1,2,3,4,5,6,7};

void spiSendByte (char databyte)
{
    // Copy data into the SPI data register
    SPDR = databyte;
    // Wait until transfer is complete
    while (!(SPSR & (1 << SPIF)));
}

void MAX7219_writeData(char data_register, char data)
{
    MAX7219_LOAD0;
        // Send the register where the data will be stored
        spiSendByte(data_register);
        // Send the data to be stored
        spiSendByte(data);
    MAX7219_LOAD1;
}

void MAX7219_clearDisplay()
{
    char i = digitsInUse;
    // Loop until 0, but don't run for zero
    do {
        // Set each display in use to blank
        MAX7219_writeData(i, MAX7219_CHAR_BLANK);
    } while (--i);
}

void MAX7219_clearDisplay0()
{
    char i = digitsInUse;
    // Loop until 0, but don't run for zero
    do {
        // Set each display in use to blank
        MAX7219_writeData(i, 0);
    } while (--i);
}

void MAX7219_displayDigits(unsigned int num) {
  for (int i=0; i<num; i++) {
    MAX7219_writeData(i+MAX7219_DIGIT0, D[i]);
  }
}

void MAX7219_displayNumber(volatile long number)
{
    char negative = 0;

    // Convert negative to positive.
    // Keep a record that it was negative so we can
    // sign it again on the display.
    if (number < 0) {
        negative = 1;
        number *= -1;
    }

    MAX7219_clearDisplay();

    // If number = 0, only show one zero then exit
    if (number == 0) {
        MAX7219_writeData(MAX7219_DIGIT0, 0);
        return;
    }

    // Initialization to 0 required in this case,
    // does not work without it. Not sure why.
    char i = MAX7219_DIGIT0;

    // Loop until number is 0.
    do {
        MAX7219_writeData(++i, number % 10);
        // Actually divide by 10 now.
        number /= 10;
    } while (number);

    // Bear in mind that if you only have three digits, and
    // try to display something like "-256" all that will display
    // will be "256" because it needs an extra fourth digit to
    // display the sign.
    if (negative) {
        MAX7219_writeData(i, MAX7219_CHAR_NEGATIVE);
    }
}

int LED7test(void)
{
    // SCK MOSI CS/LOAD/SS
    DDRB |= (1 << PIN_SCK) | (1 << PIN_MOSI) | (1 << PIN_SS);

    // SPI Enable, Master mode
    SPCR |= (1 << SPE) | (1 << MSTR) | (1<<SPI2X) ;  // | (1<<SPR1) | (1<<SPR0);;

    MAX7219_writeData(MAX7219_MODE_TEST, OFF);
    MAX7219_writeData(MAX7219_MODE_POWER, ON);

    // Decode mode to "Font Code-B"
    // MAX7219_writeData(MAX7219_MODE_DECODE, 0xFF);
    MAX7219_writeData(MAX7219_MODE_DECODE, 0x00);

    // Scan limit runs from 0.
    MAX7219_writeData(MAX7219_MODE_SCAN_LIMIT, digitsInUse - 1);
    MAX7219_writeData(MAX7219_MODE_INTENSITY, intensity);

    /* int i = 99999999; */
    /* while(1) */
    /* { */
    /*     MAX7219_displayNumber(--i); */
    /*     // _delay_ms(10); */

    /*     if (i == 0) { */
    /*       //i = 999; */
    /*       break; */
    /*     } */
    /* } */
    for (int i = 0; i<10; i++) {
      _delay_ms(30);
      MAX7219_displayDigits(digitsInUse);
      int i;
      for (i=0; i<digitsInUse-1; i++) {
        D[i]=D[i+1];
      }
      // D[digitsInUse-1]++;
      D[digitsInUse-1] = ~(D[0] ^ D[5]);
    }
    intensity++;
    SPCR &= ~(1 << SPE);
}
