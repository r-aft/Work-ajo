#include<Servo.h>

String flag;
int input[3] ={0,0,0};
int inByte = 0;

Servo servoBb; //Back bottom
Servo servoLb; //Left bottom
Servo servoRb; //Rght bottom
Servo servoBt; //Back_top
Servo servoLt; //Left_top
Servo servoRt; //Right_top


int col;
int lon;
int lat;
int pwm;

int off_Bt = 00;
int off_Lt = 75; 
int off_Rt = 75;

int off_Bb = 00;
int off_Lb = 75; 
int off_Rb = 75;

void setup() {
  // put your setup code here, to run once:
servoBt.attach(8);
servoLt.attach(9);
servoRt.attach(10);

servoBb.attach(11);
servoLb.attach(12);
servoRb.attach(13);

servoBt.writeMicroseconds(1500+off_Bt); 
servoLt.writeMicroseconds(1500+off_Lt); 
servoRt.writeMicroseconds(1500+off_Rt);

servoBb.writeMicroseconds(1500+off_Bb); 
servoLb.writeMicroseconds(1500+off_Lb); 
servoRb.writeMicroseconds(1500+off_Rb);

Serial.begin(9600);
Serial.println("Initial Collective set to 0");
Serial.println("---STARTING-----");
delay(1000);
//Serial.println("Enter <collec,loncyc,latcyc>");
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
   
  Serial.println("Enter <col,lon,lat>");
  read_input();

if (col > 300)
 {
  Serial.println("-----OVERLIMIT-------");
 }

else if (col <300)
{
  Serial.flush();
  int rotor;
  Serial.println("Enter : 1--> Top OR 2 --> Bottom");
  while(Serial.available()==0){}
  rotor = Serial.parseInt(); 
    if(rotor == 1)
      {  
      Serial.print("UPDATING TOP ROTOR : ");
      Serial.println(col+lon+lat);
      servoBt.writeMicroseconds(1500+off_Bt+col-lon); // set servo to mid-point m
      servoLt.writeMicroseconds(1500+off_Lt+col+lon-lat); // set servo to mid-point L
      servoRt.writeMicroseconds(1500+off_Rt+col+lon+lat); // set servo to mid-point R
      }

    else if(rotor == 2)
      {
      servoBb.writeMicroseconds(1500+off_Bb+col-lon); // set servo to mid-point m
      servoLb.writeMicroseconds(1500+off_Lb+col+lon-lat); // set servo to mid-point L
      servoRb.writeMicroseconds(1500+off_Rb+col+lon+lat); // set servo to mid-point R
      }
    Serial.flush();
    delay(1000);
}
}
