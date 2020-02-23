
#include <Keyboard.h>
#include <Bounce2.h>

#define BUTTON_NUMBER 8
// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncer5 = Bounce(); 
Bounce debouncer6 = Bounce(); 
Bounce debouncer7 = Bounce(); 
Bounce debouncer8 = Bounce(); 
Bounce buttonBounce[] = {debouncer1, debouncer2, debouncer3, debouncer4, debouncer5, debouncer6, debouncer7, debouncer8};
int buttonPin[] = {2,3,4,5,6,7,8,9};
char buttonKey[] = {'a','z','e','d','c','x','w','q'};
bool buttonState[] = {false, false, false, false, false, false, false, false};
bool previousState[] = {true, true, true, true, true, true, true, true};

void setup() {

 for (int i = 0; i < BUTTON_NUMBER; i++){
   pinMode(buttonPin[i],INPUT_PULLUP);
   buttonBounce[i].attach(buttonPin[i]);
   buttonBounce[i].interval(5);
  }
  Keyboard.begin();

}

void loop() {

  for (int i = 0; i < BUTTON_NUMBER; i++){
   buttonBounce[i].update();
   buttonState[i] = (buttonBounce[i].read() == HIGH);
   if (buttonState[i] && !previousState[i]) { 
    Keyboard.press(buttonKey[i]);
   } else if (!buttonState[i] && previousState[i]) {
    Keyboard.release(buttonKey[i]);
   }
  }

  for (int i = 0; i < BUTTON_NUMBER; i++){
   previousState[i] = buttonState[i];
  }
  
}


