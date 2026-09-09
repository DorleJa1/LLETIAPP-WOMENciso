

// Incluye las bibliotecas necesarias
#include <LiquidCrystal_I2C.h>   
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Inicializa la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Configura la autenticación y la información de la red WiFi
char auth[] = "TU_BLYNK_AUTH_TOKEN";
char ssid[] = "TU_WIFI";
char pass[] = "TU_PASSWORD";
BlynkTimer timer;

// Define los pines de los componentes
#define trig D7
#define echo D8
#define LED1 D0
#define LED2 D3
#define LED3 D4
#define LED4 D5
#define LED5 D6
#define relay 3

// Ingresa el valor máximo del tanque 
int MaxLevel = 20;

int Level1 = (MaxLevel * 75) / 100; // calcula el valor de Level1 como el 75% de MaxLevel.
int Level2 = (MaxLevel * 65) / 100; // calcula el valor de Level2 como el 65% de MaxLevel.
int Level3 = (MaxLevel * 55) / 100; // calcula el valor de Level3 como el 55% de MaxLevel.
int Level4 = (MaxLevel * 45) / 100; // calcula el valor de Level4 como el 45% de MaxLevel.
int Level5 = (MaxLevel * 35) / 100; // calcula el valor de Level5 como el 35% de MaxLevel.

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600); //significa que se están transmitiendo 9600 bits por segundo,
  //es comúnmente utilizado como un estándar en muchas aplicaciones de comunicación serial

  // Inicializa la pantalla LCD
  lcd.init();
  lcd.backlight();
  // Configura los pines como entrada/salida
  pinMode(trig, OUTPUT); //salidas
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); //: Es una función que se utiliza para establecer el estado de un pin digital. 
   // Inicia la conexión con Blynk
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); // utiliza la plataforma Blynk para habilitar la comunicación entre un dispositivo (como un microcontrolador) y un servidor en la nube de Blynk.

  lcd.setCursor(0, 0); //coloca el cursor en la primera fila (fila 0) y la primera columna (columna 0)de la pantalla
  lcd.print("LLETI-app");
  lcd.setCursor(4, 1); // (fila 1) y (columna 4) de la pantalla LCD.
  lcd.print("Dorle Jasive");
  delay(9000);// 9 segundos
  lcd.clear();


  timer.setInterval(100L, ultrasonic); //Esta línea configura un temporizador para que llame a la función ultrasonic cada 100 milisegundos (0.1 segundos).
}

//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW); //el pin trig se utiliza para enviar un pulso ultrasónico que rebotará en un objeto y luego se detectará para calcular la distancia.
  delayMicroseconds(4); //Después de establecer el pin trig en bajo, se produce un pequeño retraso de 4 microsegundos.
  digitalWrite(trig, HIGH); // pulso ultrasónico al objeto que se encuentra frente al sensor.
  delayMicroseconds(10); // Esto permite que el pulso ultrasónico se propague y rebote en el objeto.
  digitalWrite(trig, LOW); // Finalmente, el pin trig se establece nuevamente en bajo (LOW) para detener el pulso ultrasónico.
  long t = pulseIn(echo, HIGH); //la función pulseIn para medir la duración del pulso de eco que regresa al pin echo como resultado del rebote 
  //del pulso ultrasónico en el objeto. La duración se almacena en la variable t.
  int distance = t / 14 / 2;

  int blynkDistance = (distance - MaxLevel) * -1;
  if (distance <= MaxLevel) {
    Blynk.virtualWrite(V0, blynkDistance);
  } else {
    Blynk.virtualWrite(V0, 0);
  }
  lcd.setCursor(0, 0);
  lcd.print("Nivel:");

  if (Level1 <= distance) {
    lcd.setCursor(8, 0);
    lcd.print("Muy bajo");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (Level2 <= distance && Level1 > distance) {
    lcd.setCursor(8, 0);
    lcd.print("Bajo");
      lcd.print("      ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (Level3 <= distance && Level2 > distance) {
    lcd.setCursor(8, 0);
    lcd.print("Medio");
    lcd.print("      ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (Level4 <= distance && Level3 > distance) {
    lcd.setCursor(8, 0);
    lcd.print("Alto");
     
    lcd.print("      ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
  } else if (Level5 >= distance) {
    lcd.setCursor(8, 0);
    lcd.print("Lleno");
     lcd.print("      ");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }
}

//Get the button value
BLYNK_WRITE(V1) {
  bool Relay = param.asInt();
  if (Relay == 1) {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor encendido ");
  } else {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor apagado");
  }
}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
