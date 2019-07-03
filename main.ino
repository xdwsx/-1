#include "Morse.h"

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
      case 'A' :{
      morse.dot();
      morse.dash();
      continue;
      }
      
      
      case 'B' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }

      case 'C' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'D' :{
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }
      
      case 'E':{
      morse.dot();
      continue;
      }

      case 'F' :{
      morse.dot();
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'G' :{
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }

      case 'H' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }
      case 'I' :{
      morse.dot();
      morse.dot();
      continue;
      }

      case 'J' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dash(); 
      continue;
      }

      case 'K' :{
      morse.dash();
      morse.dot();
      morse.dash();
      continue;
      }

      case 'L' :{
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'M' :{
      morse.dash();
      morse.dash();
      continue;
      }

      case 'N' :{
      morse.dash();
      morse.dot();
      continue;
      }

      case 'O' :{
      morse.dash();
      morse.dash();
      morse.dash();
      continue;
      }

      case 'P' :{
      morse.dot();
      morse.dash();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'Q' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dash();
      continue;
      }


      case 'R' :{
      morse.dot();
      morse.dash();
      morse.dot();
      continue;
      }

      case 'S' :{
      morse.dot();
      morse.dot();
      morse.dot();
      continue;
      }

      case 'T' :{
      morse.dash();
      continue;
      }

      case 'U' :{
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      case 'V' :{
      morse.dot();
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      
      case 'W' :{
      morse.dot();
      morse.dash();
      morse.dash();
      continue;
      }
      
      case 'X' :{
      morse.dash();
      morse.dot();
      morse.dot();
      morse.dash();
      continue;
      }
      
      case 'Y' :{
      morse.dash();
      morse.dot();
      morse.dash();
      morse.dash();
      continue;
      }
      
      case 'Z' :{
      morse.dash();
      morse.dash();
      morse.dot();
      morse.dot();
      continue;
      }

      case ' ' :{
      morse.c_space();
      continue;
      }
      
      case '\r' :{
      morse.w_space();
      continue;
      }
    }
  }
}
