#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!

#define USMIN  1200// This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  1800 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define top_motor_enable 8
#define bottom_motor_enable 9

#define servoBb 8 //Back bottom
#define servoLb 9 //Left bottom
#define servoRb 10 //Rght bottom

#define servoBt 12 //Back_top
#define servoLt 13 //Left_top
#define servoRt 14 //Right_top


String flag;
int input[3] ={0,0,0};
int inByte = 0;

bool t_rotor =1;
bool b_rotor =1;

String t_string,b_string;

char menuselect;

String bottom_status,top_status;

int col_t=0;
int lon_t=0;
int lat_t=0;

int col_b=0;
int lon_b=0;
int lat_b=0;



int off_Bt = 25;
int off_Lt = 50-10; 
int off_Rt = -50-10;

int off_Bb = 00;
int off_Lb = 75; 
int off_Rb = 75;

void setup() {
  pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  

  pinMode(top_motor_enable,OUTPUT);
pinMode(bottom_motor_enable,OUTPUT);
  // put your setup code here, to run once:


pwm.writeMicroseconds(servoBt,1500+off_Bt); 
pwm.writeMicroseconds(servoLt,1500+off_Lt); 
pwm.writeMicroseconds(servoRt,1500+off_Rt);

pwm.writeMicroseconds(servoBb,1500+off_Bb); 
pwm.writeMicroseconds(servoLb,1500+off_Lb); 
pwm.writeMicroseconds(servoRb,1500+off_Rb);

Serial.begin(9600);
Serial.println("Initial Collective set to 0");
Serial.println("---STARTING-----");

bottom_status="[BOT]\tcol_b="+String(col_b) + "\tlon_b="+ String(lon_b) + "\tlat_b="+ String(lat_b);
 top_status="[TOP]\tcol_t="+String(col_t) + "\tlon_t="+ String(lon_t) + "\tlat_t="+ String(lat_t);
}

void loop() {
 disp_menu();




}
