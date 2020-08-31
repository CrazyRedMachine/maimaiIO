#define BOUNCE_WITH_PROMPT_DETECTION
#include <Keyboard.h>
#include <Bounce2.h>
#define BUTTON_COUNT 8
#define EXTRA_BUTTON_COUNT 1
#define TOTAL_BUTTON_COUNT BUTTON_COUNT+EXTRA_BUTTON_COUNT
#define BOUNCE_INTERVAL 5

int buttonPin[] = {2,3,4,5,6,7,8,9,10};
char buttonKey[] = {'q','w','e','d','c','x','z','a','s'};
Bounce buttonBounce[TOTAL_BUTTON_COUNT];
bool buttonState[TOTAL_BUTTON_COUNT];
bool previousState[TOTAL_BUTTON_COUNT];

void setup() {

 for (int i = 0; i < BUTTON_COUNT; i++){
   buttonBounce[i] = Bounce();
   buttonBounce[i].attach(buttonPin[i], INPUT_PULLUP);
   buttonBounce[i].interval(BOUNCE_INTERVAL);
   buttonState[i] = false;
   previousState[i] = true;
  }
  
 for (int i = BUTTON_COUNT; i < TOTAL_BUTTON_COUNT; i++){
   buttonBounce[i] = Bounce();
   buttonBounce[i].attach(buttonPin[i], INPUT_PULLUP);
   buttonBounce[i].interval(BOUNCE_INTERVAL);
   buttonState[i] = false;
   previousState[i] = false;
  }
  Keyboard.begin();
}

void loop() {

  for (int i = 0; i < BUTTON_COUNT; i++){
   buttonBounce[i].update();
   buttonState[i] = (buttonBounce[i].read() == HIGH);
   if (buttonState[i] && !previousState[i]) { 
    Keyboard.press(buttonKey[i]);
   } else if (!buttonState[i] && previousState[i]) {
    Keyboard.release(buttonKey[i]);
   }
   previousState[i] = buttonState[i];
  }
  for (int i = BUTTON_COUNT; i < TOTAL_BUTTON_COUNT; i++){
   buttonBounce[i].update();
   buttonState[i] = (buttonBounce[i].read() == LOW);
   
   if (buttonState[i] && !previousState[i]) { 
    Keyboard.press(buttonKey[i]);
   } else if (!buttonState[i] && previousState[i]) {
    Keyboard.release(buttonKey[i]);
   }
   previousState[i] = buttonState[i];
  }
}


