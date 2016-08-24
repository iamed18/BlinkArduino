/*  BlinkArduino is a two-LED system controlled by a single push-button
 *  
 *  The logic as currently written:
 *  if the button is currently being pressed: blink the two LEDs in anti-marchstep
 *  if the button is currently not pressed:   do nothing
 *  
 *  Wiring for the button is pull-up style
 *  
 *  Pin-out from the board is listed immediately after the comment block
*/

int pinLED1  = 12       // pin for LED1
int pinLED2  = 13       // pin for LED2
int pinBUT1  = 7        // pin for reading state of BUT1
int valBUT1  = 0        // int to store state of BUT1
float blinkRate = 10    // switching rate of the LEDs in Hz

// Run once; define pins for IO
void setup() {

  // Output pins 1 and 2
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);

  // Input pins
  pinMode(pinBUT1, INPUT);
}

// Main loop; checks button state and responds by blinking or not
void loop() {

  // Read button state
  val = digitalRead(pinBUT1);

  // If button is not pressed (HIGH), turn off the lights
  if (val == HIGH) {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);  
  }

  // If the button is pressed (LOW), flash the lights 
  else {
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, LOW);
    delay(1/blinkRate);
    
    digitalWrite(pinLED1,LOW);
    digitalWrite(pinLED2,HIGH);
    delay(1/blinkRate);  
  }
}


