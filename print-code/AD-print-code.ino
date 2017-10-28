#include <SoftwareSerial.h>
SoftwareSerial Thermal(2, 3);
String income="";

void setup() 
{
 Serial.begin(9600); // for debug info to serial monitor
 Thermal.begin(19200); // to write to our new printer
}
void loop() {
  read_pi();
}

void read_pi()
{
    while(Serial.available()){
    income += (char)Serial.read();
  }

  if(income != 0)
  {
    Serial.println(income);
    Thermal.println(income);
    Thermal.print("\n\n");
    income="";
  }
  delay(10);
}

