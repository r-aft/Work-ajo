void read_input_b()
{
  
  label1:
  bool valid_data_1=false;
  bottom_status="[BOT]\tcol_b="+String(col_b) + "\tlon_b="+ String(lon_b) + "\tlat_b="+ String(lat_b);
Serial.println("\n[X]to exit \n"+top_status+"\n"+bottom_status+"\n[BOTTOM SERVO]\tEnter <col,lon,lat> [BOTTOM SERVO]");
flag="";
while(!Serial.available()){}
flag=Serial.readString();
//Serial.println(flag);
Serial.flush();
if(flag=="X"||flag=="x")
return;
else
{
 flag=flag+",";
//Serial.println("String:"+flag+ " Length:" + flag.length());

int r=0, t=0;
for (int i=0; i < flag.length(); i++)
{ 
 if(flag.charAt(i) == ',') 
  { 
    input[t] = flag.substring(r, i).toInt(); 
    r=(i+1); 
    t++; 
   if(t==3 && flag.length()>=6)
    valid_data_1=true;
    else 
   valid_data_1=false;
  }
  }
}



//Serial.println("col=" + col +", lon=" + lon + ", lat=" +lat)
Serial.println("\tcol_b="+String(col_b) + "\tlon_b="+ String(lon_b) + "\tlat_b="+ String(lat_b));

if (abs(input[0])> 300)
 {
  Serial.println("-----OVERLIMIT-------");
 }
else if (abs(input[0])<=300 && valid_data_1)
{
col_b = input[0];
lon_b = input[1];
lat_b = input[2];
servo_update_b();
  
}
else
Serial.println(F("\n[!ERROR!] UNSUPPORTED FORMAT"));

goto label1;




}
