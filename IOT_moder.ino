#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 128

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
#include <dht11.h>
#define DHT11PIN 8
dht11 DHT11;

int MQ2=A1;
int ledpin=2;
int val=0;

int motor = 10; 
int val1;
int speed_0;


void setup() {
  pinMode(DHT11PIN, OUTPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // init done
  display.display();
  delay(2000);
  display1();
  delay(100);
  pinMode(MQ2,INPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}
void loop()  {
  
  test();
  display2();
  MQ_2();
  display3();
  
  
  
  }



void test() 
{
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Tep: ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.println("C");
  Serial.print("Hum: ");
  Serial.print((float)DHT11.humidity, 2);
  Serial.println("%");
  Serial.println();
  delay(200);
}

void display1() 
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("Welcome!");
  display.println("My IOT");
  delay(2000);
  display.display();
}

void display2() 
{
  display.setCursor(0, 0);
  display.clearDisplay();
  display.print("TEM:");
  display.print((float)DHT11.temperature, 2);
  display.println("C");
  display.print("HUM:");
  display.print((float)DHT11.humidity, 2);
  display.println("%");
  display.display();
  delay(100);
}

void MQ_2()
{
  val=analogRead(MQ2);
  Serial.print("Smoke sensor :");
  Serial.println(val);
  if(val>260)
  digitalWrite(ledpin,HIGH);
  else
  digitalWrite(ledpin,LOW);

}
void FANon(){
val1 = 9; 
speed_0 = val1 *(252 / 9); 
  
  analogWrite(motor, speed_0);
}
void FANoff(){
  val1 = 0; 
speed_0 = val1 *(252 / 9); 
  
  analogWrite(motor, speed_0);
}
void display3()
{
  
  
  display.print("Smoke sensor :");
  display.println(val);
  display.display();
  delay(100);
  
  }
void display_restart()
{
  
  display.setCursor(0, 0);
  display.clearDisplay();
  
}

  
  
  
