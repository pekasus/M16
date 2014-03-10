/*
M16.cpp - rapidly deployable menu system

Screen command can expand to add more lines, but what if no value is entered?
*/

#include "Arduino.h"
#include "LCD.h"
#include "LiquidTWI.h"
#include "LiquidCrystal.h"
#include "M16.h"

String Clear16 = "                ";

M16::M16(byte butOne, byte butTwo, byte butThree, byte butFour)
{
	pinMode(butOne, INPUT_PULLUP);
	pinMode(butTwo, INPUT_PULLUP);
	pinMode(butThree, INPUT_PULLUP);
	pinMode(butFour, INPUT_PULLUP);
	_but1 = butOne;
	_but2 = butTwo;
	_but3 = butThree;
	_but4 = butFour;
	LiquidTWI lcd(0);
}

byte M16::checkButtons()
{
	if(digitalRead(_but1) == LOW) {
    lcd.clear();
    delay(300);
    return _but1;
  }
  else if(digitalRead(_but2) == LOW) {
    lcd.clear();
    delay(300);
    return _but2;
  }
  else if(digitalRead(_but3) == LOW) {
    lcd.clear();
    delay(300);
    return _but3;
  }
  else {
    return;
  }
}

void M16::buttonSelect(byte butOne, byte butTwo, byte butThree)
{
	for(unsigned int ii = 0; ii < timeout; ii++) {
    	byte butPress = checkButtons();
    	if (butPress == but1) {
      menuSelect(butOne);
    	}
    	else if (butPress == but2) {
			menuSelect(butTwo);
    	}
    	else if (butPress == but3) {
    		menuSelect(butThree);
    	}
    	else if (butPress == but4) {
			break;
    	}
    	else {
    		delay(200);
    	}
  	}
}

void M16::clear()
{
	lcd.clear();
}

void M16::clearLn(byte lineNum)
{
lcd.setCursor(0,lineNum);
lcd.print(Clear16);
}

void M16::printVal(byte val)
void M16::printVal2(byte val)
void M16::printVal3(int val)
void M16::printVal4(int val)

void M16::screen(String scrA, String scrB)
{
lcd.setCursor(0,0);
lcd.print(scrA);
lcd.setCursor(0,1);
lcd.print(scrB);
}

void M16::menuSelect(_menuVal) 
{
  if(_menuVal == 1) {
    menu1();
  }
  else if(_menuVal == 2) {
    menu2();
  }
  else if(_menuVal == 3) {
    menu3();
  }
  else if(_menuVal == 11) {
    menu11();
  }
  else if(_menuVal == 12) {
    menu12();
  }
  else if(_menuVal == 13) {
    menu13();
  }
  else if(_menuVal == 21) {
    menu21();
  }
  else if(_menuVal == 22) {
    menu22();
  }
  else if(_menuVal == 23) {
    menu23();
  }
  else if(_menuVal == 31) {
    menu31();
  }
  else if(_menuVal == 32) {
    menu32();
  }
  else if(_menuVal == 33) {
    menu33();
  }
  else if(_menuVal == 41) {
    menu211();
  }
  else if(_menuVal == 42) {
    menu212();
  }
  else if(_menuVal == 43) {
    menu213();
  }
}
