#include <TinyGPS.h>

TinyGPS gps;  //Creates a new instance of the TinyGPS object


void setup()
{
  Serial.begin(9600);  
//  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPS::library_version());
//  Serial.println("Testing GPS");
//  Serial.println("Designed by: www.TheEngineeringProjects.com");
//  Serial.println();
}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available())
    {
      char c = Serial.read();
      //Serial.print(c);
      if (gps.encode(c)) 
        newData = true;  
    }
  }

  if (newData)      //If newData is true
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    if(flat > 0.00000){   
    Serial.print("Latitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);}
   // Serial.print("my print=");
   // Serial.print(flat);
    //delay(5000);
    if(flon > 0.000000)
    {
     Serial.print(" Longitude = ");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);}

    if(age!=0)
    {Serial.print(" Age = ");
    Serial.print(age == TinyGPS::GPS_INVALID_AGE ? 0.0 : age, 6);}
  }
 
  Serial.println(failed);
 // if (chars == 0)
   // Serial.println("** No characters received from GPS: check wiring **");
}
