#define ledPin 8
#define switch1 2
#define SWITCHPRESSED LOW

int switchOldState ;

int ledState = LOW;             // ledState used to set the LED



// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)


  void blinker(){
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

   
    digitalWrite(ledPin, ledState);
  }
  }
  
void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(switch1, INPUT_PULLUP);
  Serial.begin(9600);
  
  switchOldState = digitalRead(switch1);


}

#define VILKUTA 1789
#define EI_VILKUTA 456
int tila = EI_VILKUTA;

void loop() {


int switchNewState = digitalRead (switch1);

    if (switchNewState != switchOldState){
      if (switchNewState == SWITCHPRESSED){
        
       if (tila==EI_VILKUTA) {
          tila=VILKUTA;
       } else {
          tila=EI_VILKUTA;
       }
      
        
      }
    }
    if(tila==VILKUTA){
      blinker();
    } else{
        digitalWrite(ledPin, HIGH);
    }
    
     
     
      
     switchOldState = switchNewState;
      
}
 

