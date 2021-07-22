#include <Wire.h>

int temp = 0;
float vin = 49.9, current = 149.5, kecepatan = 25.0;

void setup() {


Serial.begin(9600);

     
}


void loop() {  



  //SD card
 Serial.print("t9.txt=\""); // Changing the value of box n1
        Serial.print("Vi");
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);

//GPS speed
 Serial.print("t0.txt=\""); // Changing the value of box n1
        Serial.print(kecepatan);
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);

//Voltage Battery
        Serial.print("t1.txt=\""); // Changing the value of box n1
        Serial.print(vin);
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);
        
  //Arus Batre
        Serial.print("t2.txt=\""); // Changing the value of box n1
        Serial.print(current);
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);


  //Watt Batre
        Serial.print("t3.txt=\""); // Changing the value of box n1
        Serial.print(vin*current);
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);




  //Tanggal
        Serial.print("t7.txt=\""); // Changing the value of box n1
        Serial.print("07/04/2021");
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);
        
  //Jam
  //waktu.setText(rtc.getTimeStr());
        Serial.print("t8.txt=\""); // Changing the value of box n1
        Serial.print("5:21");
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);

  //Satellite Number
        Serial.print("t10.txt=\""); // Changing the value of box n1
        Serial.print("30");
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);
        
  //Temperature
        Serial.print("t11.txt=\""); // Changing the value of box n1
        Serial.print(temp);
        Serial.print("\"");
        Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
        Serial.write(0xff);
        Serial.write(0xff);

temp++;
vin -= 0.05;
current -= 1.2;
kecepatan -=0.5;

delay(500);
}
