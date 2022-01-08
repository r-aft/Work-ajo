void read_input()
{
while(Serial.available()==0){}
flag=Serial.readString()+",";

Serial.println("String:"+flag+ " Length:" + flag.length());

int r=0, t=0;
for (int i=0; i < flag.length(); i++)
{ 
 if(flag.charAt(i) == ',') 
  { 
    input[t] = flag.substring(r, i).toInt(); 
    r=(i+1); 
    t++; 
  }
}

col = input[0];
lon = input[1];
lat = input[2];

//Serial.println("col=" + col +", lon=" + lon + ", lat=" +lat)
Serial.println(col);
Serial.println(lon);
Serial.println(lat);
Serial.println("Enter <col,lon,lat>");


}
