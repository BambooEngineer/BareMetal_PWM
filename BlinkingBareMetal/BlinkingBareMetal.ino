#include <avr/io.h>
//#include <util/delay.h>
#include <util/delay_basic.h>

#define MS_DELAY 3000

uint16_t x;

void setup() {
  
  DDRB |= _BV(DDB5);
  
  DDRC = 0b00000000; 
  ADMUX = 0b01100000; 
  
  ADCSRA = 0b10000111;  
  

}

void loop() {

  
  ADCSRA = ADCSRA | (1 << ADSC);

  
  while(ADCSRA & (1<<ADSC));

  x = ADCH;

  PWM(x);

}

void PWM(uint16_t x){
  
  PORTB |= _BV(PORTB5);

  
  _delay_loop_2(x);
 

  PORTB &= ~_BV(PORTB5);
  
  _delay_loop_2(x);
}
