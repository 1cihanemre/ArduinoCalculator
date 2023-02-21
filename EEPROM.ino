int displaySegment[10][7]={ 
  {8,9,10,11,12,13},  //0
  {10,13},            //1
  {7,9,10,11,12},     //2
  {7,9,10,12,13},     //3
  {7,8,10,12,13},     //4
  {7,8,9,12,13},      //5
  {7,8,9,11,12,13},   //6
  {9,10,13},          //7
  {7,8,9,10,11,12,13},//8
  {7,8,9,10,12,13},   //9
  };


bool flag=0;
int writer=2,i,j;
int binary[4];
int sum=0,counter=1;
int islemSecici[3];
int GirilenSayiSayici=0;

void setup() {
  Serial.begin(9600);
  
  pinMode(writer,INPUT_PULLUP);
  for(i=3;i<=6;i++){
    pinMode(i,INPUT_PULLUP);
  }

  for(i=7;i<=13;i++){
    pinMode(i,OUTPUT);
  }
}

void binaryCalc(){
  //  3  4  5  6
  //  0  0  0  0
  if(counter==1){
     if(binary[0]==0){
       sum= 0 + binary[1]*2 + binary[2]*2*2 + binary[3]*2*2*2;  
      }
     else{
       sum= 1 + binary[1]*2 + binary[2]*2*2 + binary[3]*2*2*2;
     }
     Serial.println(sum);
    // EEPROM.write(0,sum);
     counter++;
  }
  else{
    if(binary[0]==0){
       sum= 0 + binary[1]*2 + binary[2]*2*2 + binary[3]*2*2*2;  
      }
     else{
       sum= 1 + binary[1]*2 + binary[2]*2*2 + binary[3]*2*2*2;
     }
     //EEPROM.write(1,sum);
     Serial.println(sum);
  }
}

void loop() {

//Binary aldığımız sayıyı binaryCalc() fonksiyonuna yollayıp eeprom üzerine yazdırıyoruz.
// Girilen Sayı sayacı max 2 sayı girebilmemiz için

  if(digitalRead(writer)==0 && flag==true && GirilenSayiSayici<2){
    flag=false;
    for(i=3;i<=6;i++){
      if(digitalRead(i)==0){
        binary[j]=1;
        j++;
      }
      else{
        binary[j]=0;
        j++;
      }
    }
    binaryCalc();
    
    
    
    GirilenSayiSayici++;
    delay(300);

    Serial.println(GirilenSayiSayici);
  }
  else if(digitalRead(writer)==1 && flag==false){
    flag=true;
    delay(100);
  }


//Toplam Bulduracağız.
//Girilen sayı sayacının 2 olmasının sebebi 2 sayı girildikten sonra çalışmasını istememiz.

  if(GirilenSayiSayici==2){                                                
      if(digitalRead(writer)==0 && flag==true){
      flag=false;
      for(i=3;i<=6;i++){
        if(digitalRead(i)==0){
          if(i==3){
            
          }
          else if(i==4){
            
          }
          else if(i==5){
            
          }
          else if(i==6){
            
          }         
        }
      }
      GirilenSayiSayici++;
    }    
    else if(digitalRead(writer)==1 && flag==false){
      flag=true;
    }
  
  }




/*
  if(digitalRead(writer)==1&&flag==false){
    Serial.println("1");
    flag=true;
  }
  else if(digitalRead(writer)==0&&flag==true){
    Serial.println("0");
    flag=false;
  }
  */
  
}
