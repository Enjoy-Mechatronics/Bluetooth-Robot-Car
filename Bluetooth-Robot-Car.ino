
char cmd;//The Bluetooth Command

//The L298N Control Pins
const int rightMotorForward = 2;
const int rightMotorBackward = 3;

const int leftMotorForward = 4;
const int leftMotorBackward = 5;
 
void setup() {
  pinMode(leftMotorForward,OUTPUT);   //left motor forward
  pinMode(leftMotorBackward,OUTPUT);   //left motor reverse
  pinMode(rightMotorForward,OUTPUT);   //right motor forward
  pinMode(rightMotorBackward,OUTPUT);   //right motor reverse
  Serial.begin(9600);
}
 
void loop() {
  if(Serial.available()){
    cmd = Serial.read();
  }
   
  if(cmd == 'F'){           //move forward
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);
  }
   
  else if(cmd == 'B'){      //move reverse
    digitalWrite(leftMotorBackward,HIGH);
    digitalWrite(rightMotorBackward,HIGH);
  }
   
  else if(cmd == 'L'){      //turn Left
    digitalWrite(rightMotorForward,HIGH);
  }
   
  else if(cmd == 'R'){      //turn Right
    digitalWrite(leftMotorForward,HIGH);
  }
   
  else{      //STOP (all motors stop)
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }
  delay(50);
}
