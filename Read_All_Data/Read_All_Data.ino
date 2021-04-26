/* Connections:
    MPPT pin     MPPT        Arduino     Arduino pin
    1            GND         GND         GND
    2            RX          TX          -              do not use!
    3            TX          RX          19 (MEGA)
    4            Power+      none        -              do not use!
 */


String label, val, laadstatus;
float meetwaarde;

void setup()  
{
  Serial.begin(57600);
  Serial1.begin(19200);
} 

void loop() 
{
  Serial.println("Trying to Read from MPPT...");
  if (Serial1.available())
   {
      Serial.println("Serial1 available reading from MPPT...");
      label = Serial1.readStringUntil('\t');      
      val = Serial1.readStringUntil('\r\r\n');
      Serial.println(label + val);
      Serial.println("####################");
   } else {
     Serial.println("Serial1 not available. Please connect MPPT (MPPT Pin 1 to Arduino GND -- MPPT Pin 3 to Arduino Pin 19)");
   }
}
