void read_input_t()
{
  
  label2:
   bool valid_data_2=false;
  top_status="[TOP]\tcol_t="+String(col_t) + "\tlon_t="+ String(lon_t) + "\tlat_t="+ String(lat_t);
Serial.println("\n[X]to exit \n"+top_status+"\n"+bottom_status+"\n[TOP SERVO] Enter <col,lon,lat>[TOP SERVO] ");
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
    valid_data_2=true;
    else 
   valid_data_2=false;
  }
  }
}



//Serial.println("col=" + col +", lon=" + lon + ", lat=" +lat)
Serial.println("\tcol_t="+String(col_t) + "\tlon_t=" +String(lon_t) + "\tlat_t=" +String(lat_t));


if (abs(input[0]) > 300)
 {
  Serial.println("-----OVERLIMIT-------");
 }
if (abs(input[0]) <=300 && valid_data_2)
{
col_t = input[0];
lon_t = input[1];
lat_t = input[2];
servo_update_t();

}
else
Serial.println(F("\n[!ERROR!] UNSUPPORTED FORMAT"));

goto label2;



}
