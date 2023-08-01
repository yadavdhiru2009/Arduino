/*
Author:Dharmendra Kumar Yadav
*/

#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

// Map the buttons to an array for the Keymap instance
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad

// Initialise the Keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);   // Initialise the serial monitor
}

void loop() {

  // Read the pushed button
  char button = customKeypad.getKey();

  if (button) {
    Serial.println(button);
  }
}
