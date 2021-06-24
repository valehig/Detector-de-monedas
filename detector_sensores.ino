#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64
#define OLED_RESET 4
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);

int s0=0;
int s1=0;
int s3=0;
int s7=0;
int sumador=0;

int sensorA = A0;
int sensorB = A1;
int sensorC = A2;
int valorSensorA = 0;
int valorSensorB = 0;
int valorSensorC = 0;

int A=10;
int B=11;
int C=12;

void setup () {

 Wire.begin();
 oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);


 pinMode(6, INPUT);
 pinMode(7, INPUT);
 pinMode(8, INPUT);
 pinMode(9, INPUT);


 pinMode(sensorA, INPUT);
 pinMode(sensorB, INPUT);
 pinMode(sensorC, INPUT);


 pinMode(A, OUTPUT);
 pinMode(B, OUTPUT);
 pinMode(C, OUTPUT);
 Serial.begin (9600);

}


 void loop()  {

  s0=digitalRead(6);
  s1=digitalRead(7);
  s3=digitalRead(8);
  s7=digitalRead(9);
  
  valorSensorA = analogRead(sensorA);
  Serial.print("Valor sensor A: ");
  Serial.print(valorSensorA);
  delay(500);

  valorSensorB = analogRead(sensorB);
  Serial.print("Valor sensor B: ");
  Serial.print(valorSensorB);
  delay(500);

  valorSensorC = analogRead(sensorC);
  Serial.print("Valor sensor C: ");
  Serial.print(valorSensorC);
  delay(500);

  if(valorSensorA>=480) {
    digitalWrite(A, HIGH);
  }
  if(valorSensorA<480) {
    digitalWrite(A, LOW);
  }
  

  if(valorSensorB>=480) {
    digitalWrite(B, HIGH);
  }
  if(valorSensorB<480) {
    digitalWrite(B, LOW);
   }

 if(valorSensorC>=480) {
    digitalWrite(C, HIGH);
  }
  if(valorSensorC<480) {
    digitalWrite(C , LOW);
   }

   oled.setTextColor(WHITE);

   if(s0==LOW)  {

    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.setTextSize(1);
    oled.print("No hay moneda");
    oled.setCursor(10,15);
    oled.setTextSize(2);
    oled.print("$0");

    oled.setCursor (0,35);
    oled.setTextSize(2);
    oled.print("Ahorro:");
    oled.print(sumador);
    oled.display();
    delay(1000);
    }

  if(s1==LOW)  {

    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.setTextSize(1);
    oled.print(" Moneda de:");
    oled.setCursor(10,15);
    oled.setTextSize(2);
    oled.print("$1");
     sumador=sumador+1;

    oled.setCursor (0,35);
    oled.setTextSize(2);
    oled.print("Ahorro:");
    oled.print(sumador);
    oled.display();
    delay(1000);
    }


     if(s3==LOW)  {

    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.setTextSize(1);
    oled.print("Moneda de");
    oled.setCursor(10,15);
    oled.setTextSize(2);
    oled.print("$2");
    sumador=sumador+2;

    oled.setCursor (0,35);
    oled.setTextSize(2);
    oled.print("Ahorro:");
    oled.print(sumador);
    oled.display();
    delay(1000);
    }


    if(s7==LOW)  {

    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.setTextSize(1);
    oled.print("Moneda de:");
    oled.setCursor(10,15);
    oled.setTextSize(2);
    oled.print("$5");
     sumador=sumador+5;

    oled.setCursor (0,35);
    oled.setTextSize(2);
    oled.print("Ahorro:");
    oled.print(sumador);
    oled.display();
    delay(1000);
    }



    
  }
  
  







 
 
 
 
