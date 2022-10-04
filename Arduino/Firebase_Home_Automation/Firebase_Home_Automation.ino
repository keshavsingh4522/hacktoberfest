#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
 #include <ESP8266HTTPClient.h>
 
// Set these to run example.
#define FIREBASE_HOST "smart-home-f5995-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH "AxKFBFQR4F4294UvzSy1Am34dR3oN8R9JsSlDkX"   // Enter Your Unique Firebase Authentication Code
#define WIFI_SSID "0opsyProxy :-)"     // Enter Your Wifi Name / SSID
#define WIFI_PASSWORD "12345678"  // Enter Your Wifi Password
 
String myString;
int vr = A0; // variable resistor connected  
int sdata = 0; // The variable resistor value will be stored in sdata.
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vr ,INPUT);  //A0 Pin is set as a Input Mode
  pinMode(D0,OUTPUT);  //D0 Pin is set as a Output Mode
 
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
   Firebase.setString("Variable/Value","smart-home-f5995-default-rtdb");
}
 
void loop()
{
 
sdata = analogRead(vr); // it will Read the data comming from A0 and will store into sdata
myString = String(sdata);
Serial.println(myString); 
Firebase.setString("Variable/Value",myString);
delay(1000);            
}
