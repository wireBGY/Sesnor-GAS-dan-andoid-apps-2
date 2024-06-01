// by Wire Bagye 2024
//
// Script ini untuk mengontrol ESP32 melalui aplikasi penemu MIT (Bluetooth).
// perangkat yang digunakan untuk pengujian: ESP32-WROOM-32D
// menggunakan arduino IDE 1.8.9
// Aplikasi di ponsel memiliki tiga tombol:
// Tombol 1: 11 untuk ON dan 10 untuk OFF
// Tombol 2: 21 untuk ON dan 20 untuk OFF
// Tombol 3: 31 untuk ON dan 30 untuk OFF
//
//
// ------------------------------------------------ --

// header ini diperlukan untuk Bluetooth Serial -> HANYA berfungsi di ESP32
#include "BluetoothSerial.h" 
// init Class:
BluetoothSerial ESP_BT; 

// init PINs: assign any pin on ESP32
int LED1base1 = 4;
int LED1base2 = 0;
int LED2base1 = 2;     // Pada beberapa ESP32 pin 2 terdapat LED internal, milik saya tidak memilikinya
int LED2base2 = 27; 
// Parameter untuk antarmuka Bluetooth
int BTData, incoming;

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control"); //Nama  Bluetooth Anda -> akan muncul di ponsel Anda

  pinMode (LED1base1, OUTPUT); // len pin sebagai fungsi keluaran
  pinMode (LED1base2, OUTPUT);
  pinMode (LED2base1, OUTPUT);
  pinMode (LED2base2, OUTPUT);
}

  
  // -------------------- menerima sinyal bluetooth ----------------------
void loop()
                {
                   if (ESP_BT.available()) 
                  {
BTData = ESP_BT.read();
//Serial.write(BTData);
digitalWrite(17, HIGH);
                  }

                  if (BTData == 48) {
// left start
digitalWrite(LED1base1, HIGH);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, HIGH);
                  } else if (BTData == 49) {
// left stop
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, LOW);
                  } else if (BTData == 50) {
// forward start
digitalWrite(LED1base1, HIGH);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, HIGH);
digitalWrite(LED2base2, LOW);
                  } else if (BTData == 51) {
// forward stop
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, LOW);
                  } else if (BTData == 52) {
// right start
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, HIGH);
digitalWrite(LED2base1, HIGH);
digitalWrite(LED2base2, LOW);
                  } else if (BTData == 53) {
// right stop
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, LOW);
                  } else if (BTData == 54) {
// backward start
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, HIGH);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, HIGH);
                  } else if (BTData == 55) {
// backward stop
digitalWrite(LED1base1, LOW);
digitalWrite(LED1base2, LOW);
digitalWrite(LED2base1, LOW);
digitalWrite(LED2base2, LOW);
                  } else {
digitalWrite(25, LOW);
digitalWrite(26, LOW);
digitalWrite(14, LOW);
digitalWrite(12, LOW);
                  }
                }

//}
//  if (ESP_BT.available()) 
//  {
//    incoming = ESP_BT.read(); //membaca masukkan blue tooth
//
//    // pisahkan ID tombol dari nilai tombol -> ID tombol adalah 10, 20, 30, dst, nilainya 1 atau 0
//    int button = floor(incoming / 10);
//    int value = incoming % 10;
//    
//    switch (button) {
//      case 1:  
//        Serial.print("Button 1:"); 
//        Serial.println(value);
//        digitalWrite(led_pin_1, value);
//        break;
//      case 2:  
//        Serial.print("Button 2:"); 
//        Serial.println(value);
//        digitalWrite(led_pin_2, value);
//        break;
//      case 3:  
//        Serial.print("Button 3:");
//        Serial.println(value);
//        digitalWrite(led_pin_3, value);
//        break;
//    }
//  }
//}
