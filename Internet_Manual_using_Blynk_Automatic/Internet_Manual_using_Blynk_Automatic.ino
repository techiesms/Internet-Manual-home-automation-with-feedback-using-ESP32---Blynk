/*************************************************************
 This is the code for the project called

 Internt,W/O Internet & Manual Home Automation project using Blynk IOT Platform
 Here is the full tutorial video of this project 
 https://youtu.be/dHuqD-EaL-U


 Subscriber to techiesms YouTube channel for more such amazing and unique
 electronic project tutorials 
 https://www.youtube.com/techiesms

 This code is provided open only for fair use like projects and education purpose only
 Any one using this code or any material for the purpose other then fair use
 will be considered as breaking the rules of open source material
 and will be taken necesasary actions against them. 

        #techiesms
 explore | learn | share 
 *************************************************************/
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;


#define DEBUG_SW 0


#define S1 32
#define R1 15

#define S2 35
#define R2 2

#define S3 34
#define R3 4

#define S4 39
#define R4 22


#define LED1 26
#define LED2 25
#define LED3 27
#define Buzzer 21



int MODE = 0;


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SmS_jiofi";
char pass[] = "sms123458956";

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "UmQncyp90XXbSad3jWhvF6yGnUCH48Ya";


int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(R1, pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(R2, pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V3 to a variable
  digitalWrite(R3, pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V4 to a variable
  digitalWrite(R4, pinValue);
  // process received value
}

void with_internet()
{
  if (digitalRead(S1) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 0 )
    {
      digitalWrite(R1, LOW);
      if (DEBUG_SW) Serial.println("Relay1- ON");
      Blynk.virtualWrite(V1, 0);
      switch_ON_Flag1_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch1 -ON");

  }
  if (digitalRead(S1) == HIGH )
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(R1, HIGH);
      if (DEBUG_SW) Serial.println("Relay1 OFF");
      Blynk.virtualWrite(V1, 1);
      switch_ON_Flag1_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch1 OFF");
  }


  if (digitalRead(S2) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 0 )
    {
      digitalWrite(R2, LOW);
      if (DEBUG_SW)  Serial.println("Relay2- ON");
      Blynk.virtualWrite(V2, 0);
      switch_ON_Flag2_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch2 -ON");

  }
  if (digitalRead(S2) == HIGH )
  {
    if (switch_ON_Flag2_previous_I == 1)
    {
      digitalWrite(R2, HIGH);
      if (DEBUG_SW) Serial.println("Relay2 OFF");
      Blynk.virtualWrite(V2, 1);
      switch_ON_Flag2_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch2 OFF");
    //delay(200);
  }

  if (digitalRead(S3) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 0 )
    {
      digitalWrite(R3, LOW);
      if (DEBUG_SW) Serial.println("Relay3- ON");
      Blynk.virtualWrite(V3, 0);
      switch_ON_Flag3_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch3 -ON");

  }
  if (digitalRead(S3) == HIGH )
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(R3, HIGH);
      if (DEBUG_SW) Serial.println("Relay3 OFF");
      Blynk.virtualWrite(V3, 1);
      switch_ON_Flag3_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch3 OFF");
    //delay(200);
  }

  if (digitalRead(S4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 0 )
    {
      digitalWrite(R4, LOW);
      if (DEBUG_SW) Serial.println("Relay4- ON");
      Blynk.virtualWrite(V4, 0);
      switch_ON_Flag4_previous_I = 1;
    }
    if (DEBUG_SW) Serial.println("Switch4 -ON");

  }
  if (digitalRead(S4) == HIGH )
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(R4, HIGH);
      if (DEBUG_SW) Serial.println("Relay4 OFF");
      Blynk.virtualWrite(V4, 1);
      switch_ON_Flag4_previous_I = 0;
    }
    if (DEBUG_SW)Serial.println("Switch4 OFF");
    //delay(200);
  }



}

void without_internet()
{

  digitalWrite(R1, digitalRead(S1));
  digitalWrite(R2, digitalRead(S2));
  digitalWrite(R3, digitalRead(S3));
  digitalWrite(R4, digitalRead(S4));

}


void checkBlynk() { // called every 3 seconds by SimpleTimer

  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    MODE = 1;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
  if (isconnected == true) {
    MODE = 0;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }
}

void setup()
{
  // Debug console
  if (DEBUG_SW) Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(R1, OUTPUT);

  pinMode(S2, INPUT);
  pinMode(R2, OUTPUT);

  pinMode(S3, INPUT);
  pinMode(R3, OUTPUT);

  pinMode(S4, INPUT);
  pinMode(R4, OUTPUT);


  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED3, HIGH);
  delay(200);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);

  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED3, HIGH);
  delay(200);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  //pinMode(MODE, INPUT);
  WiFi.begin(ssid, pass);
  timer.setInterval(3000L, checkBlynk); // check if connected to Blynk server every 3 seconds
  Blynk.config(auth);//, ssid, pass);

}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    if (DEBUG_SW) Serial.println("Not Connected");
  }
  else
  {
    if (DEBUG_SW) Serial.println(" Connected");
    Blynk.run();
  }

  timer.run(); // Initiates SimpleTimer
  if (MODE == 0)
    with_internet();
  else
    without_internet();
}
