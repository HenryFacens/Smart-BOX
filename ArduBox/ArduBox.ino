#include <Grove_LCD_RGB_Backlight.h>
#include<Wire.h>
#include <A2a.h>
#include <DHT.h>
#include <avr/wdt.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define num 100

A2a arduinoSlave;
DHT dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;
SoftwareSerial espSerial(4, 11);

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;

// funcoes
int photoresistor();
float temp();
float umi();
long moving_average(int sig);
int values[num];
int adc_noise1,
    adc_noise2;




void setup() 
{
  Serial.begin(115200);
  espSerial.begin(115200);
  dht.begin();
  lcd.begin(16, 2);
  
  lcd.setRGB(colorR, colorG, colorB);
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  while (!Serial) {
    digitalWrite(7, HIGH);
    delay(3000);
    wdt_enable(WDTO_15MS);
    while(1);
  }
}

void loop()
{
  digitalWrite(8, HIGH);
  char p = 'P';
  char u = 'U';
  char t = 'T';
  char n = 'N';
//  espSerial.write("HELLO World !");  
  smart();
  lcd.setCursor(0, 2);
  lcd.print("Luminosidade:");
  lcd.print(photoresistor());
  Serial.println(String(p) + photoresistor());
  espSerial.println(String(p) + photoresistor());
  delay(5000);
  
  lcd.clear();
  smart();
  lcd.setCursor(0, 2);
  lcd.print("Umidade:");
  lcd.print(umi());
  lcd.print("%");
  Serial.println(String(u) + umi());
  espSerial.println(String(u) + umi());
  delay(5000);
  
  lcd.clear();
  smart();
  lcd.setCursor(0, 2);
  lcd.print("Temperatura:");
  lcd.print(temp());
  Serial.println(String(t) + temp());
  espSerial.println(String(t) + temp());
  delay(5000);


  adc_noise1 = analogRead(1);
  adc_noise2 = moving_average(adc_noise1);
//  Serial.print(adc_noise1);
//  Serial.print(" ");
//  Serial.println(adc_noise2);
  
  
  lcd.clear();
  smart();
  lcd.setCursor(0, 2);
  lcd.print("Ruido:");
  lcd.print(adc_noise1);
  lcd.print("dB");
  Serial.println(String(n) + adc_noise1);
  espSerial.println(String(n) + adc_noise1);
  delay(5000);
  
}
int photoresistor()
{
  int photo = 0;

  photo = analogRead(A2);

//  Serial.print("Photoresistor :");
//  Serial.print(photo);
//  Serial.println("");
  
  return photo;
}

float umi()
{
  float umidade = dht.readHumidity();
//  Serial.print("Umidade :");
//  Serial.print(umidade);
//  Serial.println("");
  return umidade;
}

float temp()
{
  float temperatura = dht.readTemperature();
//  Serial.print("temperatura :");
//  Serial.print(temperatura);
//  Serial.println("");
  return temperatura;
}
void smart()
{
  lcd.setCursor(3, 0);
  lcd.print("SMART-LAB");
}
//int ruido()
//{
//  int ruido;
//  int ruido1;
//  
//  ruido = analogRead(1);
//  Serial.print(ruido);
//  ruido1 = escala(ruido);
//  Serial.print("ruido :");
//  Serial.print(ruido1);
//  Serial.println("");
//  return ruido1;
//  }

long moving_average(int sig)
{
  int i;               //variável auxiliar para iterações
  long acc = 0;        //acumulador
  
  //Desloca o vetor completamente eliminando o valor mais antigo
  for(i = num; i > 0; i--) values[i] = values[i-1];    
  
  values[0] = sig;           //carrega o sinal no primeiro elemento do vetor
  
 // long sum = 0;            //Variável para somatório
  
  for(i = 0; i < num; i++) acc += values[i];
   
  
  return acc / num;         //Retorna a média móvel

} //end moving_average


//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h> 
//
//LiquidCrystal_I2C lcd(0x27,16,2); //endereço I2C do LCD e número de colunas e linhas
//
//void setup() {
//  lcd.begin(); //inicializar o LCD
//  lcd.backlight(); //ligar o backlight do LCD
//  Serial.begin(115200); //inicializar a comunicação serial
//}
//
//void loop() {
//  if (Serial.available() > 0) { //verificar se há dados disponíveis na serial
//    String receivedData = Serial.readStringUntil('\n'); //ler os dados até encontrar um novo linha
//    lcd.clear(); //limpar o display do LCD
//    lcd.print(receivedData); //imprimir os dados recebidos na serial no LCD
//  }
//}
