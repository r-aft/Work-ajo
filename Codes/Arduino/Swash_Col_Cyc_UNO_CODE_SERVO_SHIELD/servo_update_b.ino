void servo_update_b()
{
 
 pwm.writeMicroseconds(servoBb,constrain(1500+off_Bb+col_b-lon_b,USMIN ,USMAX)); // set servo to mid-point m
      pwm.writeMicroseconds(servoLb,constrain(1500+off_Lb+col_b+lon_b-lat_b,USMIN ,USMAX)); // set servo to mid-point L
      pwm.writeMicroseconds(servoRb,constrain(1500+off_Rb+col_b+lon_b+lat_b,USMIN ,USMAX)); // set servo to mid-point R
Serial.println(F("\n UPDATED BOTTOM SERVO"));
}
