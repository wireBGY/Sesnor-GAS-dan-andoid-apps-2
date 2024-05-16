// ini merupakan script menampilan data sensor gas pada andorid
#include "BluetoothSerial.h"
#include <MQ2.h>
BluetoothSerial SerialBT;
 int BTData, Sensor_Jendela, Sensor_Pintu;
 int pinAout = 12; // pin MQ2
 int lpg_gas, co_gas, smoke_gas;
int led = 14;
  MQ2 mq2(pinAout);
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
       mq2.begin();
       pinMode(17, OUTPUT);

         }

 void loop() {
float* values= mq2.read(true); //jika diset "false" tidak akan dimunculkan di serial monitor
  lpg_gas = mq2.readLPG();
  co_gas = mq2.readCO();
  smoke_gas = mq2.readSmoke();


  Serial.println (lpg_gas);
  Serial.println (co_gas);
  Serial.println (smoke_gas);

  SerialBT.print("LPG =   ");
SerialBT.println(co_gas);

  SerialBT.print("co_gas =  ");
SerialBT.println(co_gas);

  SerialBT.print("Smoke_gas=  ");
SerialBT.println(co_gas);

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


