#include <CapacitiveSensor.h>
#include <WS2812FX.h>

//#include "Keyboard.h"
#define LED_COUNT 16
#define LED_PIN 13

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);


CapacitiveSensor   cs_4_2 = CapacitiveSensor(2,5);   
CapacitiveSensor   cs_4_3 = CapacitiveSensor(2,7);
CapacitiveSensor   cs_4_4 = CapacitiveSensor(2,9);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(2,11);
void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 
   cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
   
  ws2812fx.init();
 ws2812fx.setBrightness(20);
  
ws2812fx.setSpeed(20);
//Keyboard.begin();
  ws2812fx.start();
   Serial.begin(9600);
}

int max_value=70;
bool rainbow=false;
int mode_fx=2;
int set_mode=2;
bool pressed1=false, pressed2=false, pressed3=false, pressed4=false;

void loop()                    
{
    ws2812fx.service();
  
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_3.capacitiveSensor(30);
    long total3 =  cs_4_4.capacitiveSensor(30);
    long total4 =  cs_4_5.capacitiveSensor(30);

    
    if(total4>max_value){

      if(pressed4==false)
      Serial.println("4");
      pressed4=true;
      mode_fx=32;
      if(rainbow==false)
       ws2812fx.setMode(mode_fx);

      rainbow=true;
    }
    else{
      pressed4=false;
    if(total1>max_value){
      if(pressed1==false){
      Serial.println("1");
      pressed1=true;
     // Keyboard.press('A');
     mode_fx=set_mode;
     if(mode_fx!=set_mode)
     ws2812fx.setMode(mode_fx);
      ws2812fx.setColor(0x5FFF00);
      }
    }
    else pressed1=false;
    
   if(total2>max_value){
    if(pressed2==false){
      Serial.println("2");
      pressed2=true;
   // Keyboard.press('S');
   mode_fx=set_mode;
     if(mode_fx!=set_mode)
     ws2812fx.setMode(mode_fx);
    ws2812fx.setColor(0xFFFF00);
    }
   }
    else pressed2=false;
     
   if(total3>max_value){
    if(pressed3==false){
      Serial.println("3");
      pressed3=true;
   // Keyboard.press('D');
    mode_fx=set_mode;
     if(mode_fx!=set_mode)
     ws2812fx.setMode(mode_fx);
      ws2812fx.setColor(0xFF0000);
    }
   }
   else pressed3=false;
    }

   if(total1<max_value && total2<max_value && total3<max_value && total4<max_value ){
   // Keyboard.releaseAll();
   ws2812fx.setMode(0);
     ws2812fx.setColor(0x000000);
     rainbow=false;
   }

   
    delay(1);                             // arbitQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQrary delay to limit data to serial port 
}

void ChangeColor(int color){
for(int i=0;i<LED_COUNT;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    if(color==0)
    ws2812fx.setPixelColor(i, ws2812fx.Color(255,156,0)); // Moderately bright green color.

    if(color==1)
    ws2812fx.setPixelColor(i, ws2812fx.Color(255,255,0)); // Moderately bright green color.
    
    if(color==2)
    ws2812fx.setPixelColor(i, ws2812fx.Color(0,255,0)); // Moderately bright green color.

    if(color==3)
    ws2812fx.setPixelColor(i, ws2812fx.Color(0,0,0)); // Moderately bright green color.

    if(color==4)
    ws2812fx.setPixelColor(i, ws2812fx.Color(255,255,255)); // Moderately bright green color.

    ws2812fx.show(); // This sends the updated pixel color to the hardware.


  }
}


