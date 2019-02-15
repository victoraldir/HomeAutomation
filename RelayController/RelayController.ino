
const int relay1 = 5;
const int relay2 = 6;
const int relay3 = 7;
const int relay4 = 8;

const char TRIGGER_RELAY_1 = 'a';
const char TRIGGER_RELAY_2 = 'b';
const char TRIGGER_RELAY_3 = 'c';
const char TRIGGER_RELAY_4 = 'd';

int relay1State = LOW;
int relay2State = LOW;
int relay3State = LOW;
int relay4State = LOW;

char inputCommand = '0';         // The command itself
bool incomingEvent = false;  // Flags when something get in

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
//  inputCommand.reserve(200);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // set the relay state
  digitalWrite(relay1, relay1State);
  digitalWrite(relay2, relay2State);
  digitalWrite(relay3, relay3State);
  digitalWrite(relay4, relay4State);
}

void loop() {
  // print the string when a newline arrives:
  if (incomingEvent) {
    Serial.println(inputCommand);
    handleCommand(inputCommand);
    incomingEvent = false;
  }
  
}

void handleCommand(char inputCommand){
  switch(inputCommand){
    case TRIGGER_RELAY_1:
      Serial.println("TRIGGER_RELAY_1");
      if(relay1State == HIGH){
        relay1State = LOW;
      }else{
        relay1State = HIGH;
      }
      digitalWrite(relay1, relay1State);
      break;
    case TRIGGER_RELAY_2:
      Serial.println("TRIGGER_RELAY_2");
      if(relay2State == HIGH){
        relay2State = LOW;
      }else{
        relay2State = HIGH;
      }
      digitalWrite(relay2, relay2State);
      break;
    case TRIGGER_RELAY_3:
      Serial.println("TRIGGER_RELAY_3");
      if(relay3State == HIGH){
        relay3State = LOW;
      }else{
        relay3State = HIGH;
      }
      digitalWrite(relay3, relay3State);
      break;
    case TRIGGER_RELAY_4:
      Serial.println("TRIGGER_RELAY_4");
      if(relay4State == HIGH){
        relay4State = LOW;
      }else{
        relay4State = HIGH;
      }
      digitalWrite(relay4, relay4State);
      break;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = Serial.read();
    // add it to the inputString:
    inputCommand = inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    incomingEvent = true;
  }
}

int readInt(){
  byte b1 = Serial.read();
  byte b2 = Serial.read();
  return  b2 + b1 * 256;
}
