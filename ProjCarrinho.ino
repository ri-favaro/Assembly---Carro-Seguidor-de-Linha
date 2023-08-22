#define motor1 5 //Motor esquerdo
#define motor2 6  //Motor direito
#define CNY1 A0
#define CNY2 A1
#define CNY3 A2
int leituraSensor1 = 0; //Sensor esquerdo
int leituraSensor2 = 0; //Sensor direito
int leituraSensor3 = 0; //Sensor do meio
float potenciaPorcentagem1, potenciaPorcentagem2;
float potenciaAnalogica1, potenciaAnalogica2;

int sensorFunction(){
  leituraSensor1 = analogRead(CNY1);
  leituraSensor2 = analogRead(CNY2);
  leituraSensor3 = analogRead(CNY3);
  if((leituraSensor1 > 500) && (leituraSensor3 > 500) && (leituraSensor2 > 500)){ //Sensor Esq: preto | Sensor Meio: preto | Sensor Dir: preto
    return 1;
  }
  if((leituraSensor1 <= 500) && (leituraSensor3 > 500) && (leituraSensor2 > 500)){ //Sensor Esq: branco | Sensor Meio: preto | Sensor Dir: preto
    return 2;
  }
  if((leituraSensor1 > 500) && (leituraSensor3 <= 500) && (leituraSensor2 > 500)){ //Sensor Esq: preto | Sensor Meio: branco | Sensor Dir: preto
    return 3;
  }
  if((leituraSensor1 > 500) && (leituraSensor3 > 500) && (leituraSensor2 <= 500)){ //Sensor Esq: preto | Sensor Meio: preto | Sensor Dir: branco
    return 4;
  }
  if((leituraSensor1 <= 500) && (leituraSensor3 <= 500) && (leituraSensor2 > 500)){ //Sensor Esq: branco | Sensor Meio: branco | Sensor Dir: preto
    return 5;
  }
  if((leituraSensor1 > 500) && (leituraSensor3 <= 500) && (leituraSensor2 <= 500)){ //Sensor Esq: preto | Sensor Meio: branco | Sensor Dir: branco
    return 6;
  }
  if((leituraSensor1 <= 500) && (leituraSensor3 > 500) && (leituraSensor2 <= 500)){ //Sensor Esq: branco | Sensor Meio: preto | Sensor Dir: branco
    return 7;
  }
  if((leituraSensor1 <= 500) && (leituraSensor3 <= 500) && (leituraSensor2 <= 500)){ //Sensor Esq: branco | Sensor Meio: branco | Sensor Dir: branco
    return 8;
  }
}

void motorFunction(float porcentagem1, float porcentagem2){
  potenciaPorcentagem1 = porcentagem1;
  potenciaAnalogica1 = (2.55 * porcentagem1);
  analogWrite(motor1, potenciaAnalogica1);
  potenciaPorcentagem2 = porcentagem2;
  potenciaAnalogica2 = (2.55 * porcentagem2);
  analogWrite(motor2, potenciaAnalogica2);
}

void setup() {
  pinMode(CNY1, INPUT);
  pinMode(CNY2, INPUT);
  pinMode(CNY3, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  switch(sensorFunction()){
    case 1:
      motorFunction(100, 100);
      break;
    case 2:
      motorFunction(100, 0);
      break;
    case 3:
      motorFunction(0, 0);
      break;
    case 4:
      motorFunction(100, 0);
      break;
    case 5:
      motorFunction(0, 100);
      break;
    case 6:
      motorFunction(100, 0);
      break;
    case 7:
      motorFunction(100, 100);
      break;
    case 8:
      motorFunction(0, 0);
      break;
    default:
      break;
  }
  Serial.print("Valor analogico do sensor esquerdo: ");
  Serial.println(leituraSensor1);
  Serial.print("Valor analogico do sensor do meio: ");
  Serial.println(leituraSensor3);
  Serial.print("Valor analogico do sensor direito: ");
  Serial.println(leituraSensor2);
  Serial.print("Potencia Motor Esquerdo - ");
  Serial.print(potenciaPorcentagem1);
  Serial.print("% = ");
  Serial.println(potenciaAnalogica1);
  Serial.print("Potencia Motor Direito - ");
  Serial.print(potenciaPorcentagem2);
  Serial.print("% = ");
  Serial.println(potenciaAnalogica2);
  Serial.println("");
  delay(500);
}