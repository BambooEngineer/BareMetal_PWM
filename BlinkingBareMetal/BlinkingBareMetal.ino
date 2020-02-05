#include <avr/io.h>
//#include <util/delay.h>
#include <util/delay_basic.h>

#define MS_DELAY 3000

uint16_t x;

void setup() {
  
  DDRB |= _BV(DDB5); // pin 13 as output
  
  DDRC = 0b00000000; // analog 0 as input 
  ADMUX = 0b01100000; // Multiplexer configuration
  
  ADCSRA = 0b10000111;  // Prescaler configuration
  

}

void loop() {

  
  ADCSRA = ADCSRA | (1 << ADSC); // Start ADC Conversion

  
  while(ADCSRA & (1<<ADSC)); // Wait till bit is cleared

  x = ADCH; // x as potentiometer value 

  PWM(x); // PWM function

}

void PWM(uint16_t x){
  
  PORTB |= _BV(PORTB5); // turn on pin 13

  
  _delay_loop_2(x); // delay according to potentiometer value 
 

  PORTB &= ~_BV(PORTB5); // turn off pin 13
  
  _delay_loop_2(x); // another delay
}
