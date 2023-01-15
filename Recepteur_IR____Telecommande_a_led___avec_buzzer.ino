//Sen Mecatronique 2023
//Copyright 2023, Tous droits Réservés !

// Visite ma chaine youtube : https://www.youtube.com/channel/UC6kEnwoRBb-1Av36WA99mzQ
// Abonne toi et like pour me donner de la force !

// NB: Si vous n'utilisez pas le meme modéle de télécommande que dans ma video le code ne marchera pas ! 
          //Car la fréquence de chaque bouton varie généralement en fonction du modéle de la télécommande.



                  // J'ai expliqué le cablage en commentaire 👇

#include<IRremote.h>
IRrecv IR(11);        // Attention de griller votre recepteur IR 
                      // Mettez le recepteur IR telque la partie blanche soit face á vous et respectez la ligne suivante :
                    //( Signal du Recepteur Infrarouge [1ere patte ]est branché á la broche 11 , ensuite [2eme patte] á GND et enfin [3eme patte ] á 5v)
int buzzer = 8;           //( borne + du buzzer actif branchée á la broche 8 et la borne - est branchéé á GND )
int ledPin = 2;           //( Anode de la led branchée á la broche 2, la cathode á la résistance [220ohms] puis á GND)

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
IR.enableIRIn();
pinMode(ledPin, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
if(IR.decode()){
  Serial.println(IR.decodedIRData.decodedRawData, HEX );
if(IR.decodedIRData.decodedRawData == 0xEA15FF00){
digitalWrite(ledPin, HIGH);  
  digitalWrite(buzzer, HIGH);
}
else if(IR.decodedIRData.decodedRawData == 0xB847FF00){
digitalWrite(ledPin, LOW); 
digitalWrite(buzzer, LOW); 
}
delay(10);
IR.resume();
}
}
