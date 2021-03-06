//www.elegoo.com
//2016.12.9

#include "IRremote.h"
const int motor=12; //motor pin
int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 13
//G=gnd, R=5v, Y=signal

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes

{

  switch (results.value)

  {
    case 0xFFA25D: Serial.println("POWER"); break;
   /* case 0xFFE21D: Serial.println("Blades"); break; //FUNC/STOP
    case 0xFF629D: Serial.println("Forward"); break; //VOL+
    case 0xFF22DD: Serial.println("Left");    break; //FAST BACK
    case 0xFF02FD: Serial.println("Stop");    break; //PAUSE
    case 0xFFC23D: Serial.println("Right");   break; //FAST FORWARD
    case 0xFFE01F: Serial.println("Light on");    break; //DOWN
    case 0xFFA857: Serial.println("Reverse");    break; //VOL-
    case 0xFF906F: Serial.println("Light off");    break; //UP
   // case 0xFF9867: Serial.println("EQ");    break;
   // case 0xFFB04F: Serial.println("ST/REPT");    break; 
   // case 0xFF6897: Serial.println("0");    break;
    case 0xFF30CF: Serial.println("1");    break;//speeds 1-9
    case 0xFF18E7: Serial.println("2");    break;
    case 0xFF7A85: Serial.println("3");    break;
    case 0xFF10EF: Serial.println("4");    break;
    case 0xFF38C7: Serial.println("5");    break;
    case 0xFF5AA5: Serial.println("6");    break;
    case 0xFF42BD: Serial.println("7");    break;
    case 0xFF4AB5: Serial.println("8");    break;
    case 0xFF52AD: Serial.println("9");    break; */
    case 0xFFFFFFFF: Serial.println(" REPEAT"); break;

    default:
      Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(motor, OUTPUT);

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    if(results.value==0xFFA25D){
      digitalWrite(motor, HIGH);
    }
    else {
     digitalWrite(motor, LOW);
    }
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */
