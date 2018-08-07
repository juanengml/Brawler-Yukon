char letra;

int pin1 = 9; // motor A 
int pin2 = 8; // MOtor A 


int pin7 = 3;  // motor d 
int pin8 = 2; // motor d 



void setup() {
 Serial.begin(9600); // serial comunicacao
 pinMode(pin1,OUTPUT); // MOTOR A 
 pinMode(pin2,OUTPUT);  // MOTOR A 
 pinMode(pin7,OUTPUT);
 pinMode(pin8,OUTPUT);
 Serial.println("BigRobot RUNNING...");

}

void loop() {
  letra = Serial.read();
  switch(letra){
    case 'w': // Motor A
    Serial.println("MOTOR A,B,C e D RUN ");
    //digitalWrite(pin1,HIGH);       // Motor A 
    //digitalWrite(pin2,LOW);       // Motor A 
    digitalWrite(pin7,HIGH);      // Motor D
    digitalWrite(pin8,LOW);       // Motor D

    
    break;
    case 's':
    Serial.println("MOTOR A,B,C e D  BACK ");   
    digitalWrite(pin7,LOW);  // Motor A 
    digitalWrite(pin8,HIGH);  // Motor A
   
    break;

    case 'p':
    Serial.println("MOTOR A and B STOP ");
    digitalWrite(pin1,LOW); // Motor A 
    digitalWrite(pin2,LOW); // Motor A 
    digitalWrite(pin7,LOW); // MOtor B 
    digitalWrite(pin8,LOW);  // MOtor B    
    break;

    case 'd':
    Serial.println("MOTOR 3 DIRECAO: (DIREITA)");
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    delay(100);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    delay(100);
    break;
    
    case 'a':
     Serial.println("MOTOR 3 DIRECAO: (ESQUERDA");
     digitalWrite(pin1,LOW);
     digitalWrite(pin2,HIGH);
     delay(100);
     digitalWrite(pin1,LOW);
     digitalWrite(pin2,LOW);
     delay(100);
     break;
     
                       
  }

}
