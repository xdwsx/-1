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
   case 'f':
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