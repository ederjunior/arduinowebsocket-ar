
String entrada="0";

void setup() {
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);

    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    
      
    Serial.begin(9600);
}

int ultimoComando=0;
int comando = 0;
int velocidade = 140;

void loop() {
  while(comando == ultimoComando){
    if(Serial.available()){
        comando = Serial.read();
         
        //comando = entrada.toInt();            
    }
  }
  // comando de parada -----------------------------
  if(comando == 48){
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(8,LOW);
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
        digitalWrite(11,LOW);

  //comando para frente ---------------------------      
  }else if(comando == 49){
          analogWrite(2,velocidade);
          analogWrite(3,velocidade+10);
          digitalWrite(9,LOW);
          digitalWrite(11,LOW);
          
          digitalWrite(8,HIGH);
          digitalWrite(10,HIGH);  

   //comando para esquerda -----------------------
   }else if(comando == 51){
          analogWrite(2,velocidade);
          analogWrite(3,velocidade);
          digitalWrite(9,HIGH);
          digitalWrite(11,LOW);
          
          digitalWrite(8,LOW);
          digitalWrite(10,HIGH);

   //comando para direita ------------------------       
   }else if(comando == 50){
          analogWrite(2,velocidade);
          analogWrite(3,velocidade);
          digitalWrite(9,LOW);
          digitalWrite(11,HIGH);
          
          digitalWrite(8,HIGH);
          digitalWrite(10,LOW);

   //comando para tras ---------------------------                         
   }else if(comando == 52){        
          analogWrite(2,velocidade);
          analogWrite(3,velocidade+10);
          digitalWrite(9,HIGH);
          digitalWrite(11,HIGH); 
          
          digitalWrite(8,LOW);
          digitalWrite(10,LOW);
   } 
   ultimoComando = comando;
}
