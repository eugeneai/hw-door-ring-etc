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
  } else {
    PORTB &=~(1<<LED);
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

  stdout = &uart_output;
  stdin  = &uart_input;
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
    sleep_mode();
  }
  return 0;
}
