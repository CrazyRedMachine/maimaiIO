#define BOUNCE_WITH_PROMPT_DETECTION
#include <Joystick.h>
#include <Bounce2.h>
#define BUTTON_COUNT 8
#define EXTRA_BUTTON_COUNT 1
#define TOTAL_BUTTON_COUNT BUTTON_COUNT+EXTRA_BUTTON_COUNT
#define BOUNCE_INTERVAL 5

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  TOTAL_BUTTON_COUNT, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int buttonPin[] = {2,3,4,5,6,7,8,9,10};
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
  Joystick.begin();

}

void loop() {

  for (int i = 0; i < BUTTON_COUNT; i++){
   buttonBounce[i].update();
   buttonState[i] = (buttonBounce[i].read() == HIGH);
   if (buttonState[i] && !previousState[i]) { 
    Joystick.setButton(i, buttonState[i]);
   } else if (!buttonState[i] && previousState[i]) {
    Joystick.setButton(i, buttonState[i]);
   }
   previousState[i] = buttonState[i];
  }
  
  for (int i = BUTTON_COUNT; i < TOTAL_BUTTON_COUNT; i++){
   buttonBounce[i].update();
   buttonState[i] = (buttonBounce[i].read() == LOW);
   
   if (buttonState[i] && !previousState[i]) { 
    Joystick.setButton(i, buttonState[i]);
   } else if (!buttonState[i] && previousState[i]) {
    Joystick.setButton(i, buttonState[i]);
   }
   previousState[i] = buttonState[i];
  }
  
}


