#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

//button arrays
int buttonPins[4] = {0, 1, 2, 3};
int buttonBuffer[4] = {0, 0, 0, 0};

//joystick arrays
int joystickPins[2] = {A0, A1};
int joystickBuffer[2] = {0, 0};

boolean but1 = false;

Metro controlRate = Metro(25);

//initializes the buttons
void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

//recieves inputs from the physical buttons and joystick
void getControls() {
  //an array to set each button value to 1 when the button is pressed
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].fell()) {buttonBuffer[i] = 1;}
    if (buttons[i].rose()) {buttonBuffer[i] = 0;}
  }

  //an array to match the joystickBuffer to the reading of the joystick
  for (int i = 0; i < 2; i++) {
    joystickBuffer[i] = analogRead(joystickPins[i]);
  }

  //sets the values of the buffer to 1 (down), 0 (neutral), or -1 (up)
  if (joystickBuffer[0] > 525) {joystickBuffer[0] = 1;}
  else if (joystickBuffer[0] < 475) {joystickBuffer[0] = -1;}
  else {joystickBuffer[0] = 0;}

  //sets the values of the buffer to 1 (right), 0 (neutral), or -1 (left)
  if (joystickBuffer[1] > 515) {joystickBuffer[1] = 1;}
  else if (joystickBuffer[1] < 475) {joystickBuffer[1] = -1;}
  else {joystickBuffer[1] = 0;}

//  if (controlRate.check()) {
//    Serial.print(buttonBuffer[0]);
//    Serial.print("  |  ");
//    Serial.print(buttonBuffer[1]);
//    Serial.print("  |  ");
//    Serial.print(buttonBuffer[2]);
//    Serial.print("  |  ");
//    Serial.print(buttonBuffer[3]);
//    Serial.print("  |  ");
//    Serial.print(joystickBuffer[0]);
//    Serial.print("  |  ");
//    Serial.println(joystickBuffer[1]);
//  }
}
