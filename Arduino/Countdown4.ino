#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include "Arial14.h"

char b[8];
String str;
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

const int startStopButtonPin = 2; // change to your start/stop button pin
const int resetButtonPin = 3; // change to your reset button pin
const int timeUpButtonPin = 4; // increase time
const int timeDownButtonPin = 5; // decrease time

unsigned long startTime = 0;
unsigned long pauseTime = 0;
unsigned long countdownTime = 600000; // 10 minutes in milliseconds

bool paused = false;
bool running = false;


void ScanDMD(){
  dmd.scanDisplayBySPI();
}


void setup() {
  pinMode(startStopButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(timeUpButtonPin, INPUT_PULLUP);
  pinMode(timeDownButtonPin, INPUT_PULLUP);
  
  Serial.begin(9600);

  Timer1.initialize(5000);
  Timer1.attachInterrupt(ScanDMD);
  dmd.selectFont(Arial_Black_16);
}

void loop() {
  if (digitalRead(resetButtonPin) == LOW) {
    Serial.println("Reset time...");
    startTime = 0;
    pauseTime = 0;
    paused = false;
    running = false;
    
    delay(100);
  }

  if (digitalRead(startStopButtonPin) == LOW && !running) {
    Serial.println("Starting countdown...");
    startTime = millis();
    running = true;
    paused = false;
    delay(100);
  } else if (digitalRead(startStopButtonPin) == LOW && running && !paused) {
    Serial.println("Pausing countdown...");
    pauseTime = millis();
    paused = true;
    delay(100);
  } else if (digitalRead(startStopButtonPin) == LOW && running && paused) {
    Serial.println("Resuming countdown...");
    unsigned long pauseDuration = millis() - pauseTime;
    startTime += pauseDuration;
    paused = false;
    delay(100);
  }

  if (running && !paused) {
    unsigned long elapsedTime = millis() - startTime;
    if (elapsedTime >= countdownTime) {
      Serial.println("Time's up!");
      
      int slen = 0;                               
      str=" Time's up! ";
      dmd.selectFont(Arial_14); 
      slen = str.length()+1;                                     
      str.toCharArray(b,slen);           
      dmd.drawString(-4,1,b,slen,GRAPHICS_NORMAL);
      delay(5000);          
      dmd.clearScreen(true);
      
      running = false;
      paused = false;
      return;
    }
    unsigned long remainingTime = countdownTime - elapsedTime;
    int minutes = (remainingTime / 60000) % 60;
    int seconds = (remainingTime / 1000) % 60;
    int milliseconds = remainingTime % 1000;
    int millis1 = (remainingTime / 100) % 10;
    int millis2 = (remainingTime / 10) % 10;
    int millis3 = remainingTime % 10;

    String strMin, strSec, strMil;
    if (minutes < 10) {
      strMin = "0" + String(minutes, DEC);
    } else {
      strMin = String(minutes, DEC);
    }
    if (seconds < 10) {
      strSec = "0" + String(seconds, DEC);
    } else {
      strSec = String(seconds, DEC);
    }
    if (milliseconds < 10) {
      strMil = "00" + String(milliseconds, DEC);
    } else if (milliseconds < 100) {
      strMil = "0" + String(milliseconds, DEC);
    } else {
      strMil = String(milliseconds, DEC);
    }
    if(!paused){
      Serial.print(strMin);
      Serial.print(":");
      Serial.print(strSec);
      Serial.print(":");
      Serial.print(strMil);
      Serial.println("");

      //output for LED 
      int slen = 0;
      str=strMin + " ";   
      slen= str.length()+1;                                       
      str.toCharArray(b,slen);       
      dmd.drawString(0,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
      
      str=":";   
      slen= str.length()+1;                                       
      str.toCharArray(b,slen);       
      dmd.drawString(19,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
    
      str=strSec + " ";   
      slen= str.length()+1;                                       
      str.toCharArray(b,slen);       
      dmd.drawString(23,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
    
      str=":";   
      slen= str.length()+1;                                       
      str.toCharArray(b,slen);       
      dmd.drawString(42,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
    
      str=strMil + " ";   
      slen= str.length();                                       
      str.toCharArray(b,slen);       
      dmd.drawString(46,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
      
    }
  }
  if(startTime == 0){

    //increasing countdown time by 1 minute (max=59 mins)
    if(digitalRead(timeUpButtonPin) == LOW && countdownTime<3540000){
      countdownTime += 60000;
      delay(100);
    }
    
    //decreasing countdown time by 1 minute (min=1 min)
    if(digitalRead(timeDownButtonPin) == LOW && countdownTime>60000){
      countdownTime -= 60000;
      delay(100);
    }
    
    int minutes = (countdownTime / 60000) % 60;
    int seconds = (countdownTime / 1000) % 60;
    int milliseconds = countdownTime % 1000;
    int millis1 = (countdownTime / 100) % 10;
    int millis2 = (countdownTime / 10) % 10;
    int millis3 = countdownTime % 10;

    String strMin, strSec, strMil;
    if (minutes < 10) {
      strMin = "0" + String(minutes, DEC);
    } else {
      strMin = String(minutes, DEC);
    }
    if (seconds < 10) {
      strSec = "0" + String(seconds, DEC);
    } else {
      strSec = String(seconds, DEC);
    }
    if (milliseconds < 10) {
      strMil = "00" + String(milliseconds, DEC);
    } else if (milliseconds < 100) {
      strMil = "0" + String(milliseconds, DEC);
    } else {
      strMil = String(milliseconds, DEC);
    }
    Serial.print(strMin);
    Serial.print(":");
    Serial.print(strSec);
    Serial.print(":");
    Serial.print(strMil);
    Serial.println("");
      
    //output for LED 
    int slen = 0;
    str=strMin + " ";   
    slen= str.length()+1;                                       
    str.toCharArray(b,slen);       
    dmd.drawString(0,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
    
    str=":";   
    slen= str.length()+1;                                       
    str.toCharArray(b,slen);       
    dmd.drawString(19,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
  
    str=strSec + " ";   
    slen= str.length()+1;                                       
    str.toCharArray(b,slen);       
    dmd.drawString(23,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
  
    str=":";   
    slen= str.length()+1;                                       
    str.toCharArray(b,slen);       
    dmd.drawString(42,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
  
    str=strMil + " ";   
    slen= str.length();                                       
    str.toCharArray(b,slen);       
    dmd.drawString(46,1,b,slen,GRAPHICS_NORMAL);  //(x, y, value, length,type)   
    
  }
  delay(50);
}
