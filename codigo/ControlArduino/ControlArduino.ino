char letra;

int IN1 = 8;  // MOTOR TRACKER 1 
int IN2 = 9;  // MOTOR TRACKER 1 
int IN3 = 10;  // MOTOR DIRECTION
int IN4 = 11;  // MOTOR DIRECTION

float POTENCIOMETER = A0;
float DIRECTION;
void setup(){
  // INICIANDO COMUNICAÇÃO SERIAL 9600
  Serial.begin(9600);
  Serial.println("Brawler-Yukon Robot Start System.....");
  Serial.println("....");
  
  // INICIANDO I/O DE SAIDA
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN3,OUTPUT);
 
  pinMode(POTENCIOMETER,INPUT);
}

void TRACKER_RUN(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void TRACKER_BACK(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH); 
}

void left(){  // testar 
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,HIGH);
	DIRECTION = map(analogRead(POTENCIOMETER),0,1023,0,179);
    if (DIRECTION == 45){
    	digitalWrite(IN3,LOW);
    	digitalWrite(IN4,LOW);
    }
}

void right(){  // testar 
	digitalWrite(IN3,HIGH);
	digitalWrite(IN4,LOW);
	DIRECTION = map(analogRead(POTENCIOMETER),0,1023,0,179);
    if (DIRECTION == 135){
    	digitalWrite(IN3,LOW);
    	digitalWrite(IN4,LOW);
    }
}


void STOP(){
	digitalWrite(IN1,LOW);
	digitalWrite(IN2,LOW);
	digitalWrite(IN3,LOW);
	digitalWrite(IN4,LOW);
}

void loop(){
  letra = Serial.read();
  switch(letra){
  	
  	case 'w':
  	 Serial.println("CENTER [ON] - CENTER");
  	 CENTER();
  	 Serial.println("TRACKER MOTORS [ON] - RUN");
  	 TRACKER_RUN();
  	 break;
  	
  	case 'a':
  	  Serial.println("left [ON] - LEFT");
      left();
    break;

  	case 'd':
  	 Serial.println("right [ON] - RIGHT");
  	 right();
  	break;

  	case 's':
  	 Serial.println("TRACKER MOTORS [ON] - BACK");
  	 TRACKER_BACK();
  	break;

  	case 'p':
      Serial.println("STOP MOTORS");
  	  STOP();
  	break;

  }
}