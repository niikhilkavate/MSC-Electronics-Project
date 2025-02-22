#include "WiFi.h"
 
const char* ssid = "POCO X2"; //choose your wireless ssid
const char* password =  "nikhil@6388"; //put your wireless password here.
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi iqoo Z6");
  }
 
  Serial.println("Connected to the WiFi network");
  // Print local IP address and start web server
  Serial.println("wifi name");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //show ip address when connected on serial monitor.
}
 
void loop() {}

ESP32 interface LED

#include "BluetoothSerial.h"

const char LED= 12;
const char turnON ='a';
const char turnOFF ='b';

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
 Serial.begin(115200);
 pinMode(LED, OUTPUT);
 SerialBT.begin("ESP32test"); //Bluetooth device name
 //SerialBT.begin("Hackertest"); //Bluetooth device name
 Serial.println("The device started, now you can pair it with bluetooth!");
 Serial.println("Now You can TURN ON LED by sending 'a' and TURN OFF by 'b'");
}

void loop() {
 char message;
 
 if (SerialBT.available()) {
   message=SerialBT.read();
   Serial.write(message);
   
   if(message==turnON){
     digitalWrite(LED, HIGH);      //Turn LED ON
     Serial.println(" :LED Turned ON");
     SerialBT.println("LED Turned ON");   
   }
 
   else if(message==turnOFF){
     digitalWrite(LED, LOW);        //Turn LED Off
     Serial.println(" :LED Turned OFF");
     SerialBT.println("LED Turned OFF");   
   }
 
   else{
     Serial.println(" :Invalid Input"); 
     SerialBT.println("Invalid Input");
   } 
 }
 delay(20);
}
