// ini merupakan script menampilan data sensor gas pada andorid
#include "BluetoothSerial.h"
#include <MQ135.h>
BluetoothSerial SerialBT;
 int BTData, Sensor_Jendela, Sensor_Pintu;
 int pinAout = 34; // pin MQ2
 int lpg_gas, co_gas, smoke_gas;

 int Gas_Terbaca;

int led = 14;
int buzzer = 30 ;


  /* Check  Bluetooth configurations are enabled in the SDK */
 #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error // Bluetooth is not enabled! Please run `make menuconfig` to and enable it
  #endif

    void setup()
    {
     Serial.begin(115200);
     SerialBT.begin("Smart Home");
     Serial.println("Bluetooth siap untuk di SAMBUNGKAN...");
     Serial.begin(115200);
    
     pinMode(buzzer,OUTPUT);
       pinMode(led,OUTPUT);

       pinMode(17, OUTPUT);

         }

 void loop() {
  MQ135 gasSensor = MQ135(34);
  float Gas_Terbaca = gasSensor.getPPM();

//float* values= mq135.read(true); //jika diset "false" tidak akan dimunculkan di serial monitor


Serial.print ("Gas= ");
  Serial.println (Gas_Terbaca);


  SerialBT.print("gas  =   ");
SerialBT.println(Gas_Terbaca);


  digitalWrite(led,LOW);

  if(SerialBT.available())
   {
BTData = SerialBT.read();
//Serial.write(BTData);
digitalWrite(17, HIGH);
Serial.println (BTData);

}


if (lpg_gas<=140){
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
}

else if (lpg_gas==0.00){
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

}
else if (lpg_gas>=150){
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
     // delay(1500);
}
else {
digitalWrite(buzzer,LOW);
digitalWrite(led,LOW);

}
}


