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
    
    
  	digitalWrite(4, LOW);
  	delay(10); // Wait for 10 millisecond(s)
    Set_Pin(7, (getbyte&0x1));
    Set_Pin(8, (getbyte>>1)&0x1);
    Set_Pin(12, (getbyte>>2)&0x1);
    Set_Pin(13, (getbyte>>3)&0x1);
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