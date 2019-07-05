#开源硬件实践课程总结

`2019/07/02-2019/07/05`

`王世轩 17010170040`

#第一天 入门

>07/02 一些实用的软件和网站

##1.注册GitHub账号

git@github.com:xdwsx/homework1.git

##2.安装arduino、fritzing、processing

>arduino界面图

![](https://raw.githubusercontent.com/xdwsx/7.4-task-on-class/master/arduino.png)
>fritzing界面图

![](https://raw.githubusercontent.com/xdwsx/7.4-task-on-class/master/Fritzing.png)

>processing界面图

![](https://raw.githubusercontent.com/xdwsx/7.4-task-on-class/master/processing.png)

#第二天 arduino编程

>07/03 morse代码（库函数形式）

##1.Morse.h代码

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

##2.Morse.cpp代码

	#include "Arduino.h"
	#include "Morse.h"

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

#3.in_out代码

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
	      
	      case '\\' :{
	      morse.w_space();
	      break;
	      }
	
	      default:{
	      Serial.print("Please input lowercase letters, or' ', or'\\'");
	      break;
	      
	      }
	    }
	}

#第三天 在线模拟操作

>07/04 小车代码电路图、数码管代码和电路图

#1.1小车代码

>7_4task.ino

	void setup()
	{
	  pinMode(5, OUTPUT);
	  pinMode(6, OUTPUT);
	  pinMode(9, OUTPUT);
	  pinMode(10, OUTPUT);
	  Serial.begin(9600);
	  pinMode(12, OUTPUT);//左转转向灯
	  pinMode(13, OUTPUT);//右转转向灯
	  
	}
		int income=0;
	void loop()
	{
	  if(Serial.available()>0) {
	   income = Serial.read(); 
	  }
	  switch(income){
  	
    forward();
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    break;
    
    case 'l':
    left();
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    break;
    
    case 'r':
    right();
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    break;
    
    case 's':
    stop();
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    break;
    
    case 'b':
    backward();
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    break;
    
    default:
    break;
    
	  }
	}
	
	void forward(){
	 
	  digitalWrite(5,HIGH);
	  digitalWrite(6,LOW);
	  digitalWrite(9,HIGH);
	  digitalWrite(10,LOW);
	  
	}
	
	void backward(){
	 
	  digitalWrite(6,HIGH);
	  digitalWrite(5,LOW);
	  digitalWrite(10,HIGH);
	  digitalWrite(9,LOW);
	  
	}
	
	void left(){
	  
	  digitalWrite(5,HIGH);
	  digitalWrite(6,LOW);
	  digitalWrite(10,HIGH);
	  digitalWrite(9,LOW);
	  
	}
	void right(){
	  
	  digitalWrite(6,HIGH);
	  digitalWrite(5,LOW);
	  digitalWrite(9,HIGH);
	  digitalWrite(10,LOW);
	   
	}
	void stop(){
	 
	  digitalWrite(5,LOW);
	  digitalWrite(6,LOW);
	  digitalWrite(9,LOW);
	  digitalWrite(10,LOW);
	  
	}
##小车部分

###1.2小车电路图

![](https://raw.githubusercontent.com/xdwsx/homework1/master/7.4task.png)

##数码管部分

###2.1数码管代码

>2_ 7_ 4.ino

		void setup()
	{
	  pinMode(7, OUTPUT);
	  pinMode(8, OUTPUT);
	  pinMode(12, OUTPUT);
	  pinMode(13, OUTPUT);
	  pinMode(4, OUTPUT);
	  Serial.begin(9600);
	  
	}
	
	int getbyte = 0;
	
	void loop()
	{
	  if(Serial.available()>0){
	   
    getbyte = Serial.read();
    getbyte = getbyte-'0';
    
    Serial.println(getbyte,DEC);
    Serial.print('\n');
    
	digitalWrite(4, LOW);
	delay(10); // Wait for 10 millisecond(s)
    
    Set_Pin(13, (getbyte>>3)&0x1);
    Set_Pin(12, (getbyte>>2)&0x1);
    Set_Pin(8, (getbyte>>1)&0x1);
    Set_Pin(7, (getbyte&0x1));
    
    Serial.print('\n');
    
	digitalWrite(4, HIGH);
	delay(10); // Wait for 10 millisecond(s)
	}
	}

	void Set_Pin(int pin,int flag){
	 
	  Serial.println(flag);
	
	  if(flag == 1) {
	    
	  	digitalWrite(pin,HIGH);
	    
	  }
	  
	  else if(flag == 0){
	    
	   digitalWrite(pin,LOW);
	    
	  }
	  
	}
##2.2数码管电路图

![](https://raw.githubusercontent.com/xdwsx/homework1/master/2_7_4%20.png)

#第四天 总结

>07/05 MorseCode thinkerpab可执行代码、个人收获与体会

##1.thinkerpad可执行代码

>in_ out_ test.ino
 
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
##2.个人收获与体会

为期四天的课程结束了，在这四天里我收获了很多。我知道了许多有用的网页，也下载了很多有用的应用。它们可以编程、可以模拟仿真、可以写文档、存项目。这几天我用它们学习了串口的使用，学习了arduino的在线模拟、学习小车的简单控制，也了解了cd4511与数码管的使用。当然最大的收获不是这些，而是一扇新的门户————开源硬件的学习应用方法。他让我欣喜，让我着迷，让我忍不住去了解他，学习他。为我以后的大学生活打开的一扇新的大门！