// CAMBIAR ESTA PARTE CON TU CÓDIGO DE BLYNK IOT
#define BLYNK_TEMPLATE_ID "TMPL2v4VMkHiD"
#define BLYNK_TEMPLATE_NAME "TEST1"
#define BLYNK_AUTH_TOKEN "KORuY8VFq5gbO9cYDAfOWAPze8cvT0g7"
//*****************************************************************
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define ledPin 23

char auth[] = BLYNK_AUTH_TOKEN;
// CAMBIAR ESTA PARTE CON TU WIFI Y SU CLAVE
char ssid[] = "OPPO";  // NOMBRE DE WIFI
char pass[] = "b12345678";  // CLAVE DE WIFI
//*****************************************************************


void setup()
{   
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //INICIALIZACIÓN DE PUERTO DE LED
  digitalWrite(ledPin,LOW); //VALOR POR PREDETERMINADO 0
  Blynk.begin(auth, ssid, pass);  //INICIALIZACIÓN DE COMUNICACIÓN BLYNK

  }

void loop()
{
  Blynk.run(); //Comunicación de blynk

 }

 //This function is called everytime there is activity in the Blynk platform
 BLYNK_WRITE(V0) // Esta función se ejecuta cada vez que se realiza un cambio en la plataforma online de blynk o desde el celular
 {
  int pinValue=param.asInt(); //Obtiene el parametro de Blynk
  digitalWrite(ledPin,pinValue); // Modifica el puerto de salida del LED
 }
