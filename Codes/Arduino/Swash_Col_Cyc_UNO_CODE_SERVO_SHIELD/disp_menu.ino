void disp_menu()
{
digitalWrite(top_motor_enable,t_rotor);
 digitalWrite(bottom_motor_enable,b_rotor);
  if(t_rotor)
  t_string="[E] DISABLE TOP ROTOR ";
  else 
  t_string ="[E] ENABLE TOP ROTOR ";
  
  if(b_rotor)
  b_string="[R] DISABLE BOTTOM ROTOR ";
  else 
  b_string ="[R] ENABLE BOTTOM ROTOR ";

  String Menu_string=("\n[Q] Top rotor servo \n[W] Bottom Rotor Servo \n"+ t_string +"\n"+  b_string+ "\n[S] CURRENT STATUS\n[Z] SET ZERO\n[D] Disable MOTORS");
  Serial.println(Menu_string);
  
  while(Serial.available()==0){}

  if (Serial.available())  //Constantly checks to see if anything has been sent over the USB Connection and if it needs to be processed
   
   {
     menuselect = Serial.read(); //Reads a single letter
     if (menuselect == 'E' ||menuselect == 'e')
     {
     t_rotor=!t_rotor;
   if(t_rotor)
        Serial.println(F("\nTOP ROTOR ENABLED\n"));
    else 
         Serial.println(F("\nTOP ROTOR DISABLED\n"));
    
     }
     else if (menuselect == 'R'||menuselect == 'r')
     {
     b_rotor=!b_rotor;
     if(b_rotor)
        Serial.println(F("\nBOTTOM  ROTOR ENABLED\n"));
    else 
         Serial.println(F("\nBOTTOM ROTOR DISABLED\n"));
    
     }
     else if (menuselect == 'Q'||menuselect == 'q')
     read_input_t();
     else if (menuselect == 'W'||menuselect == 'w')
    read_input_b();
    else if (menuselect == 's'||menuselect == 'S')
    print_status();
     else if (menuselect == 'D'||menuselect == 'd')
     {
       t_rotor=0;
       b_rotor=0;
      
     }
     else if (menuselect == 'Z'||menuselect == 'z')
     {
    col_t=0;
 lon_t=0;
 lat_t=0;

 col_b=0;
lon_b=0;
 lat_b=0;
 servo_update_t();
 servo_update_b();
      
     }
     else 
     Serial.println(F("\n[!ERROR!] WRONG INPUT"));
     
     
  }
}
