void print_status()
{
 bottom_status="[BOT]\tcol_b="+String(col_b) + "\tlon_b="+ String(lon_b) + "\tlat_b="+ String(lat_b);
  top_status="[TOP]\tcol_t="+String(col_t) + "\tlon_t="+ String(lon_t) + "\tlat_t="+ String(lat_t);
  
  if(t_rotor)
  t_string="TOP ROTOR ENABLED";
  else 
  t_string ="TOP ROTOR DIABLED";

  if(b_rotor)
  b_string="BOTTOM ROTOR ENABLED ";
  else 
  b_string ="BOTTOM ROTOR DISABLED";
  
  Serial.println("\n"+top_status+"\n"+bottom_status+"\n"+t_string+"\n"+b_string);
}
