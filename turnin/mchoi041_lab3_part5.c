/*	Author: abeng001
 *  Partner(s) Name: Matthew Choi
 *	Lab Section: 23
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {

  DDRD = 0x00; PORTD = 0xFF;
  DDRB = 0xFE; PORTB = 0x01;

  unsigned char tmpD = 0x00;
  unsigned char tmpB = 0x00;
  unsigned char shiftBits = 0x00;
  //unsigned char pd7 = 0x00;

    while (1) {
      tmpD = 0x00;
      tmpB = 0x00;
      tmpD = PIND;
      tmpB = PINB & 0x01;
      shiftBits = (tmpD << 1) | tmpB;
      //pd7 = tmpD & 0x80;

      if((shiftBits > 69) || (PD7 == 0x80)) {
	tmpB = tmpB | 0x02;
      }
      else if(( shiftBits> 5) && ( shiftBits< 70)) {
	tmpB = tmpB & 0xFD;
	tmpB = tmpB | 0x04;
      }
      else if( shiftBits< 5) {
	tmpB = tmpB & 0xF9;
      }
      PORTB = tmpB;


    }
    return 1;
}
