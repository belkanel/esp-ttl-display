#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

/* Declare LCD object for SPI
 Adafruit_PCD8544(CLK,DIN,D/C,CE,RST); */
//Adafruit_PCD8544 display = Adafruit_PCD8544(18, 23, 4, 15, 2);  //esp32
Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 5, 15, 4);  //D5, D7, D1, D8, D2 esp8266

int contrastValue = 60; // Default Contrast Value
const int adcPin = 34;
int adcValue = 0;

void setup()
{
  Serial.begin(115200);
  
  /* Initialize the Display*/
  display.begin();

  /* Change the contrast using the following API*/
  display.setContrast(contrastValue);

  /* Clear the buffer */
  display.clearDisplay();
  display.display();
  delay(1000);
  
  /* Now let us display some text */
  display.setTextColor(WHITE, BLACK);
  display.setCursor(5,1);
  display.setTextSize(2);
  display.println("|UART|");
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(17,20);
  display.println("|Serial|");
  display.setCursor(17,32);
  display.println("|reader|");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop()
{
  /* You can implement your own display logic here*/ 
  for(;;)
  {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    
    if (Serial.available())
    {
      display.println(Serial.readStringUntil('/r'));
      display.display();
    }
    display.clearDisplay();
  }
   
}
