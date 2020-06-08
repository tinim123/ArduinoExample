#define SensorSol 10  
#define SensorOrta 9
#define SensorSag 8

#define MotorR1 3
#define MotorR2 4 
#define MotorRE 2

#define MotorL1 5
#define MotorL2 6
#define MotorLE 7

#define buzzerPin 13
int mesafe;
unsigned long sure;
int trigPin = 11; 
int echoPin = 12; 
 



void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);
  pinMode(MotorR1, OUTPUT); // Sensör ve Motorların Giriş-Çıkış bilgilerini belirtiyoruz.
  pinMode(MotorR2, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); 

  // başladı bluetooth
  



}

int x = 0;

void loop() {
  

  for(x ; x<5 ; x++){
    digitalWrite(buzzerPin,HIGH); 
    delay(500);                
    digitalWrite(buzzerPin,LOW);
    delay(500); 
  }
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
mesafe = (sure/2) / 29.1;
   if (mesafe > 200 || mesafe < 0){
   Serial.println("Menzil Disi");
   }
   else {
   Serial.print(mesafe);
   Serial.println(" cm");
   }
   if(mesafe < 15){
   dur();
   }
delay(1);
//bt
//


  if(digitalRead(SensorSol) == LOW &&digitalRead(SensorOrta)==HIGH&& digitalRead(SensorSag) == LOW){ 
    ileri();
  }

  if(digitalRead(SensorSol) == LOW &&digitalRead(SensorOrta)==LOW&&  digitalRead(SensorSag) == HIGH){  
   sag();
  }

  if(digitalRead(SensorSol) == HIGH &&digitalRead(SensorOrta)==LOW&& digitalRead(SensorSag) == LOW){  // Sol sensör çizgiyi gördüğünde robot sola dönsün.
   sol();
  }
  
         
  
}


void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 90);

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, 90);
  
  
}


void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, 75); 
  
  
}

void sol(){ 

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 75); 

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, 0); 
  
}

void dur(){ 

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, LOW);
  
}
