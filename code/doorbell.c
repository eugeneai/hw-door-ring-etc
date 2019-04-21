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
#include <stdint.h>

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

#define _DP 0x80
#define _G  0x01
#define _F  0x02
#define _E  0x04
#define _D  0x08
#define _C  0x10
#define _B  0x20
#define _A  0x40

const uint8_t SevenSegmentASCII[96] = {
	 0                              , /* (space) */
	 _DP                |_C |_B     , /* ! */
	         _F             |_B     , /* " */
	     _G |_F |_E |_D |_C |_B     , /* # */
	     _G |_F     |_D |_C     |_A , /* $ */
	 _DP|_G     |_E         |_B     , /* % */
	     _G             |_C |_B     , /* & */
	         _F                     , /* ' */
	         _F     |_D         |_A , /* ( */
	                 _D     |_B |_A , /* ) */
	         _F                 |_A , /* * */
	     _G |_F |_E                 , /* + */
	             _E                 , /* , */
	     _G                         , /* - */
	 _DP                            , /* . */
	     _G     |_E         |_B     , /* / */
	         _F |_E |_D |_C |_B |_A , /* 0 */
	                     _C |_B     , /* 1 */
	     _G     |_E |_D     |_B |_A , /* 2 */
	     _G         |_D |_C |_B |_A , /* 3 */
	     _G |_F         |_C |_B     , /* 4 */
	     _G |_F     |_D |_C     |_A , /* 5 */
	     _G |_F |_E |_D |_C     |_A , /* 6 */
	                     _C |_B |_A , /* 7 */
	     _G |_F |_E |_D |_C |_B |_A , /* 8 */
	     _G |_F     |_D |_C |_B |_A , /* 9 */
	                 _D         |_A , /* : */
	                 _D |_C     |_A , /* ; */
	     _G |_F                 |_A , /* < */
	     _G         |_D             , /* = */
	     _G                 |_B |_A , /* > */
	 _DP|_G     |_E         |_B |_A , /* ? */
	     _G     |_E |_D |_C |_B |_A , /* @ */
	     _G |_F |_E     |_C |_B |_A , /* A */
	     _G |_F |_E |_D |_C         , /* B */
	         _F |_E |_D         |_A , /* C */
	     _G     |_E |_D |_C |_B     , /* D */
	     _G |_F |_E |_D         |_A , /* E */
	     _G |_F |_E             |_A , /* F */
	         _F |_E |_D |_C     |_A , /* G */
	     _G |_F |_E     |_C |_B     , /* H */
	         _F |_E                 , /* I */
	             _E |_D |_C |_B     , /* J */
	     _G |_F |_E     |_C     |_A , /* K */
	         _F |_E |_D             , /* L */
	             _E     |_C     |_A , /* M */
	         _F |_E     |_C |_B |_A , /* N */
	         _F |_E |_D |_C |_B |_A , /* O */
	     _G |_F |_E         |_B |_A , /* P */
	     _G |_F     |_D     |_B |_A , /* Q */
	         _F |_E         |_B |_A , /* R */
	     _G |_F     |_D |_C     |_A , /* S */
	     _G |_F |_E |_D             , /* T */
	         _F |_E |_D |_C |_B     , /* U */
	         _F |_E |_D |_C |_B     , /* V */
	         _F     |_D     |_B     , /* W */
	     _G |_F |_E     |_C |_B     , /* X */
	     _G |_F     |_D |_C |_B     , /* Y */
	     _G     |_E |_D     |_B |_A , /* Z */
	         _F |_E |_D         |_A , /* [ */
	     _G |_F         |_C         , /* \ */
	                 _D |_C |_B |_A , /* ] */
	         _F             |_B |_A , /* ^ */
	                 _D             , /* _ */
	                         _B     , /* ` */
	     _G     |_E |_D |_C |_B |_A , /* a */
	     _G |_F |_E |_D |_C         , /* b */
	     _G     |_E |_D             , /* c */
	     _G     |_E |_D |_C |_B     , /* d */
	     _G |_F |_E |_D     |_B |_A , /* e */
	     _G |_F |_E             |_A , /* f */
	     _G |_F     |_D |_C |_B |_A , /* g */
	     _G |_F |_E     |_C         , /* h */
	             _E                 , /* i */
	                 _D |_C         , /* j */
	     _G |_F |_E     |_C     |_A , /* k */
	         _F |_E                 , /* l */
	             _E     |_C         , /* m */
	     _G     |_E     |_C         , /* n */
	     _G     |_E |_D |_C         , /* o */
	     _G |_F |_E         |_B |_A , /* p */
	     _G |_F         |_C |_B |_A , /* q */
	     _G     |_E                 , /* r */
	     _G |_F     |_D |_C     |_A , /* s */
	     _G |_F |_E |_D             , /* t */
	             _E |_D |_C         , /* u */
	             _E |_D |_C         , /* v */
	             _E     |_C         , /* w */
	     _G |_F |_E     |_C |_B     , /* x */
	     _G |_F     |_D |_C |_B     , /* y */
	     _G     |_E |_D     |_B |_A , /* z */
	     _G             |_C |_B     , /* { */
	         _F |_E                 , /* | */
	     _G |_F |_E                 , /* } */
	                             _A , /* ~ */
	 0                              , /* (del) */
};


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
  for(char i; i<8; i++) {
    D[i]=0;
    MAX7219_writeData(i, 0);
  };
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

void LED7_init() {
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
}

void LED7_done() {
  SPCR &= ~(1 << SPE);
}

int LED7test(void)
{
  LED7_init();
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
  LED7_done();
}


int LED7_writeChar(const char c, uint8_t digit) {
  char c1 = SevenSegmentASCII[c];
  D[digit] = (uint8_t) c1;
  MAX7219_displayDigits(digitsInUse);
  return 0;
}

uint8_t LED7_POS = 0;
int LED7_putchar(const char c, struct __file * unused) {
  // c &=0x7f; // Remove 7-th bit;
  char c1 = c - 32;
  if (LED7_POS>=digitsInUse) LED7_POS=0;
  LED7_writeChar(c1, LED7_POS++);
  // loop_until_bit_is_set(UCSRA, TXC); /* Wait until transmission ready. */
  return 0;
}

FILE LED7_output = FDEV_SETUP_STREAM(LED7_putchar, NULL, _FDEV_SETUP_WRITE);


void LED7_stdioTest(void) {
  LED7_init();
  MAX7219_clearDisplay0();
  printf("test5678");
  char c=0;
  /* while(1) { */
  /*   for (char d=0; d<8; d++) { */
  /*     LED7_writeChar(c, d); */
  /*   } */
  /*   c++; */
  /*   _delay_ms(300); */
  /* } */
  LED7_done();
}


void LED7_s_test() {
  LED7_init();
  char c=1;
  while(1) {
    for (char d=0; d<8; d++) {
      MAX7219_writeData(MAX7219_DIGIT0+d, c);
      c<<=1;
      if (c==0) c=1;
    }
    _delay_ms(2000);
  }
  LED7_done();
}


#define STEPS 5000
#define DELAY 1000

int main() {

  uart_init();
  timer_init();

  // stdout = &uart_output;
  stdout = &LED7_output;


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

  LED7_stdioTest();
  // LED7_s_test();

  _delay_ms(5000);

  // printf("Starting:\n");

  for (;;)  {
    /* pulses.p.low = get_part(); */
    /* // printf("Count: o:%u %lu (+%lu / sec) time: %u ", pulses.p.high, pulses.all, (pulses.all-pp), ticks); */
    /* printf("Count: o:%u %lu (pp =%lu) time: %u ", pulses.p.high, pulses.all, pp, ticks); */
    /* printf("\n"); */
    /* pp=pulses.all; */
    /* _delay_ms(DELAY); */
    if (! playing)
      // LED7test();

    sleep_mode();
  }
  return 0;
}
