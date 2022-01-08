#include<Servo.h>

String flag;
int input[3] ={0,0,0};
int inByte = 0;

Servo servoB;
Servo servoL;
Servo servoR;

int col;
int lon;
int lat;
int pwm;
int off_B = 00;
int off_L = 75; 
int off_R = 75;

void setup() {
  // put your setup code here, to run once:
servoB.attach(8);
servoL.attach(9);
servoR.attach(10);
servoB.writeMicroseconds(1500+off_B); 
servoL.writeMicroseconds(1500+off_L); 
servoR.writeMicroseconds(1500+off_R);
Serial.begin(9600);
Serial.println("Initial Collective set to 0");
Serial.println("---STARTING-----");
delay(1000);
Serial.println("Enter <collec,loncyc,latcyc>");

}

void loop() {
  // put your main code here, to run repeatedly:

//if(Serial.available()!=0)
//{
//  collec = Serial.parseInt();
//  Serial.print("Collective :");
//  Serial.println(col);
//  Serial.flush();  
//  
//if (collec < -500 || collec > 500)
//{
//Serial.println("--OVER LIMIT--");
//}

//if (collec >= -500 && collec <= 500)
//{


//  servoB.writeMicroseconds(1500+off_B+collec-loncyc); // set servo to mid-point m
//  servoL.writeMicroseconds(1500+off_L+collec-loncyc+latcyc); // set servo to mid-point L
//  servoR.writeMicroseconds(1500+off_R+collec+latcyc+loncyc); // set servo to mid-point R
//}
   

if (Serial.available()>0)
  {
  read_input();
  }
 
  servoB.writeMicroseconds(1500+off_B+col-lon); // set servo to mid-point m
  servoL.writeMicroseconds(1500+off_L+col+lon-lat); // set servo to mid-point L
  servoR.writeMicroseconds(1500+off_R+col+lon+lat); // set servo to mid-point R


}
