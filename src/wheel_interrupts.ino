/*
Author: Grady Bosanko
Version: Winter 2026
The code running our racing simulator system.
*/

#include <XInput.h>

const int A_pin = 0;
const int B_pin = 1;
const int X_pin = 2;
const int Y_pin = 3;

const int dpadUp_pin = 4;
const int dpadDown_pin = 5;
const int dpadLeft_pin = 6;
const int dpadRight_pin = 7;

const int PWM_pin = 8;
const int MotorDir_pin = 9;

const int Start_pin = 20;
const int Sel_pin = 21;

const int RB_pin = 22;
const int LB_pin = 23;

const int Wheel_pin = A0;
const int Gas_pin = A1;
const int Brake_pin = A2;

volatile int A_value;
volatile int B_value;
volatile int X_value;
volatile int Y_value;
volatile int RB_value;
volatile int LB_value;
volatile int Start_value;
volatile int Sel_value;
volatile int up_value;
volatile int down_value;
volatile int left_value;
volatile int right_value;

void setup() {
  pinMode(A_pin, INPUT_PULLUP);
  A_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(A_pin),update_A,CHANGE);
  pinMode(B_pin, INPUT_PULLUP);
  B_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(B_pin),update_B,CHANGE);
  pinMode(X_pin, INPUT_PULLUP);
  X_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(X_pin),update_X,CHANGE);
  pinMode(Y_pin, INPUT_PULLUP);
  Y_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(Y_pin),update_Y,CHANGE);
  
  pinMode(RB_pin, INPUT_PULLUP);
  RB_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(RB_pin),update_RB,CHANGE);
  pinMode(LB_pin, INPUT_PULLUP);
  LB_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(LB_pin),update_LB,CHANGE);

  pinMode(Start_pin, INPUT_PULLUP);
  Start_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(Start_pin),update_Start,CHANGE);
  pinMode(Sel_pin, INPUT_PULLUP);
  Sel_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(Sel_pin),update_Sel,CHANGE);

  pinMode(dpadUp_pin, INPUT_PULLUP);
  up_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(dpadUp_pin),update_dpadup,CHANGE);
  pinMode(dpadDown_pin, INPUT_PULLUP);
  down_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(dpadDown_pin),update_dpaddown,CHANGE);
  pinMode(dpadLeft_pin, INPUT_PULLUP);
  left_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(dpadLeft_pin),update_dpadleft,CHANGE);
  pinMode(dpadRight_pin, INPUT_PULLUP);
  right_value = HIGH;
  attachInterrupt(digitalPinToInterrupt(dpadRight_pin),update_dpadright,CHANGE);

  pinMode(Gas_pin, INPUT_PULLUP);
  pinMode(Brake_pin, INPUT_PULLUP);
  XInput.setTriggerRange(0, 1023);
  XInput.setJoystickRange(0, 640); // Tested output values of encoder
  //XInput.setReceiveCallback(rumbleCallback);
}

void loop() {
  XInput.setButton(BUTTON_A, A_value);
  XInput.setButton(BUTTON_B, B_value);
  XInput.setButton(BUTTON_X, X_value);
  XInput.setButton(BUTTON_Y, Y_value);
  XInput.setButton(BUTTON_RB, RB_value);
  XInput.setButton(BUTTON_LB, LB_value);
  XInput.setButton(BUTTON_START, Start_value);
  XInput.setButton(BUTTON_BACK, Sel_value);
  XInput.setDpad(up_value,down_value,left_value,right_value);
  XInput.setTrigger(TRIGGER_LEFT, analogRead(Brake_pin));
  XInput.setTrigger(TRIGGER_RIGHT, analogRead(Gas_pin));
  XInput.setJoystick(JOY_LEFT, analogRead(Wheel_pin), 0);
}

void update_A() {
  A_value = digitalRead(A_pin);
}

void update_B() {
  B_value = digitalRead(B_pin);
}

void update_X() {
  X_value = digitalRead(X_pin);
}

void update_Y() {
  Y_value = digitalRead(Y_pin);
}

void update_RB() {
  RB_value = digitalRead(RB_pin);
}

void update_LB() {
  LB_value = digitalRead(LB_pin);
}

void update_Start() {
  Start_value = digitalRead(Start_pin);
}

void update_Sel() {
  Sel_value = digitalRead(Sel_pin);
}

void update_dpadup() {
  up_value = digitalRead(dpadUp_pin);
}

void update_dpaddown() {
  down_value = digitalRead(dpadDown_pin);
}

void update_dpadleft() {
  left_value = digitalRead(dpadLeft_pin);
}

void update_dpadright() {
  right_value = digitalRead(dpadRight_pin);
}

void rumbleCallback(uint8_t packetType) {
	// If we have an LED packet (0x01), do nothing
	if (packetType == (uint8_t) XInputReceiveType::LEDs) {
		return;
	}

	// If we have a rumble packet (0x00), see our rumble data on the LED
	else if (packetType == (uint8_t) XInputReceiveType::Rumble) {
		uint8_t rumbleValueLeft = XInput.getRumbleLeft();
    uint8_t rumbleValueRight = XInput.getRumbleRight();
    if (rumbleValueLeft > rumbleValueRight) {
      analogWrite(PWM_pin, rumbleValueLeft - rumbleValueRight);
      digitalWrite(MotorDir_pin, HIGH);
    }
    else {
      analogWrite(PWM_pin, rumbleValueRight - rumbleValueLeft);
      digitalWrite(MotorDir_pin, LOW);
    }
		
	}
}



