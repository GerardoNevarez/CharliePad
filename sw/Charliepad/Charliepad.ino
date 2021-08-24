#include "DigiKeyboard.h"

#define KEY_KPENTER 0x58 // Keypad ENTER
#define KEY_KP1 0x59 // Keypad 1 and End
#define KEY_KP2 0x5a // Keypad 2 and Down Arrow
#define KEY_KP3 0x5b // Keypad 3 and PageDn
#define KEY_KP4 0x5c // Keypad 4 and Left Arrow
#define KEY_KP5 0x5d // Keypad 5
#define KEY_KP6 0x5e // Keypad 6 and Right Arrow
#define KEY_KP7 0x5f // Keypad 7 and Home
#define KEY_KP8 0x60 // Keypad 8 and Up Arrow
#define KEY_KP9 0x61 // Keypad 9 and Page Up
#define KEY_KP0 0x62 // Keypad 0 and Insert
#define KEY_KPDOT 0x63 // Keypad . and Delete

#define KEY_UP_WAIT 1

void setup_bank_1();
void setup_bank_2();
void setup_bank_3();
void setup_bank_4();

void buttonKeyStroke(byte pin, byte keyStroke);

void setup() {}

void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

  // bank 1
  setup_bank_1();
  buttonKeyStroke(2, KEY_KP7);
  buttonKeyStroke(1, KEY_KP8);
  buttonKeyStroke(0, KEY_KP9);

  // bank 2
  setup_bank_2();
  buttonKeyStroke(5, KEY_KP4);
  buttonKeyStroke(1, KEY_KP5);
  buttonKeyStroke(0, KEY_KP6);

  // bank 3
  setup_bank_3();
  buttonKeyStroke(5, KEY_KP1);
  buttonKeyStroke(2, KEY_KP2);
  buttonKeyStroke(0, KEY_KP3);

  // bank 4
  setup_bank_4();
  buttonKeyStroke(5, KEY_KP0);
  buttonKeyStroke(2, KEY_KPDOT);
  buttonKeyStroke(1, KEY_KPENTER);
}

void setup_bank_1(){
  pinMode(5,OUTPUT);
  digitalWrite(5 ,LOW);
  pinMode(2,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  pinMode(0,INPUT_PULLUP);
}

void setup_bank_2(){
  pinMode(2,OUTPUT);
  digitalWrite(2 ,LOW);
  pinMode(5,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  pinMode(0,INPUT_PULLUP);
}

void setup_bank_3(){
  pinMode(1,OUTPUT);
  digitalWrite(1 ,LOW);
  pinMode(5,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(0,INPUT_PULLUP);
}

void setup_bank_4(){
  pinMode(0,OUTPUT);
  digitalWrite(0 ,LOW);
  pinMode(5,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
}

void buttonKeyStroke(byte pin, byte keyStroke){

    if (digitalRead(pin) == LOW){
      
      DigiKeyboard.sendKeyStroke(keyStroke);
  
      while (digitalRead(pin) == LOW){
        DigiKeyboard.delay(KEY_UP_WAIT);
      }
    }
}
