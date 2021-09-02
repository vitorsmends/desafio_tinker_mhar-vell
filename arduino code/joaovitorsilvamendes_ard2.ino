#include "SoftwareSerial.h"
//Arduino 2

byte pinoTransmissor = 2; // trig
byte pinoReceptor = 3; //echo
int led3 = 8, led2 = 9, led1 = 10;
float cm, duracao;

SoftwareSerial sender(5, 4);  
void setup(){  
  pinMode(pinoTransmissor, OUTPUT); 
  pinMode(pinoReceptor, INPUT);     
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  sender.begin(9600); 
  Serial.begin(9600);
  
}

void loop() { 
  cm = distancia();
  read(cm);
  sender.println(cm);
  Serial.println(cm);
  delay(1000);
}

float distancia(){  
  
  digitalWrite(pinoTransmissor, LOW);
  delayMicroseconds(5);
  digitalWrite(pinoTransmissor, HIGH); 
  delayMicroseconds(10);
  digitalWrite(pinoTransmissor, LOW);
  duracao = pulseIn(pinoReceptor, HIGH);
  float calcDistancia= (duracao/2) * 0.0343; 

  return calcDistancia;  
    }


void read(float var){
  if(var <= 50){ 
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
  }
  else if(var > 50 && var <=100){ 
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }else if(var > 100){ 
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
  }
}