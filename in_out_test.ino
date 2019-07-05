#include "Arduino.h"

#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/

Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morse::w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}


Morse morse(13); 

int numdata=0;//for incoming serial data

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  while(Serial.read()>= 0){ }//clear serial port
}

void loop() {
  // put your main code here, to run repeatedly:
   // read data from serial port
 
  while(Serial.available()>0){
    delay(3000);
    numdata = Serial.read();//读串口第一个字节
    switch(numdata){
      case 'a' :{
      morse.dot();
      morse.dash();
      break;
      }
      
      
      case 'b' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dot();
      break;
      }

      case 'c' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dot();
      break;
      }

      case 'd' :{
      morse.dash();
      morse.dot();
      morse.dot();
      break;
      }
      
      case 'e':{
      morse.dot();
      break;
      }

      case 'f' :{
      morse.dot();
      morse.dot();
      morse.dash();
      morse.dot();
      break;
      }

      case 'g' :{
      morse.dash();
      morse.dot();
      morse.dot();
      break;
      }

      case 'h' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dot();
      break;
      }
      case 'i' :{
      morse.dot();
      morse.dot();
      break;
      }

      case 'j' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dash(); 
      break;
      }

      case 'k' :{
      morse.dash();
      morse.dot();
      morse.dash();
      break;
      }

      case 'l' :{
      morse.dot();
      morse.dash();
      morse.dot();
      break;
      }

      case 'm' :{
      morse.dash();
      morse.dash();
      break;
      }

      case 'n' :{
      morse.dash();
      morse.dot();
      break;
      }

      case 'o' :{
      morse.dash();
      morse.dash();
      morse.dash();
      break;
      }

      case 'p' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dot();
      break;
      }

      case 'q' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dash();
      break;
      }


      case 'r' :{
      morse.dot();
      morse.dash();
      morse.dot();
      break;
      }

      case 's' :{
      morse.dot();
      morse.dot();
      morse.dot();
      break;
      }

      case 't' :{
      morse.dash();
      break;
      }

      case 'u' :{
      morse.dot();
      morse.dot();
      morse.dash();
      break;
      }
      case 'v' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dash();
      break;
      }
      
      case 'w' :{
      morse.dot();
      morse.dash();
      morse.dash();
      break;
      }
      
      case 'x' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dash();
      break;
      }
      
      case 'y' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dash();
      break;
      }
      
      case 'z' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dot();
      break;
      }

      case ' ' :{
      morse.c_space();
      break;
      }
      
      case '/' :{
      morse.w_space();
      break;
      }

      default:{
      Serial.print("Please input lowercase letters, or' ', or'\\'");
      break;
      }
    }
  }
}