#include <heltec.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Endereço I2C do display
#define OLED_ADDR 0x3c

// Distância em pixels de cada linha em relação ao topo do display
#define OLED_LINE1 0
#define OLED_LINE2 10
#define OLED_LINE3 20 
#define OLED_LINE4 30
#define OLED_LINE5 40

// Resolução dos display
#define SCREEN_WIDTH 128
#define SCRENN_HEIGHT 64

// Definição do objeto display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCRENN_HEIGHT, &Wire, 16);

int contador = 0;

void setup() {
  Wire.begin(4,15);

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
    Serial.println("Display OLED: falha ao inicializar");
  else{
    Serial.println("Display OLED: inicialização ok");
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
  }
}

void loop() {
  display.clearDisplay();

  display.setCursor(0, OLED_LINE1);
  display.println('Olá!');

  display.setCursor(0, OLED_LINE2);
  display.println("Programa:");

  display.setCursor(0, OLED_LINE3);
  display.println("teste oled");

  display.setCursor(0, OLED_LINE4);
  display.println("Tempo ligado: ");

  display.setCursor(0, OLED_LINE5);
  display.print(contador);
  display.println("s");

  display.display();

  contador++;
  delay(1000);
}
