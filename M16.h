/*
This menu is designed to work with a 16x2 LCD.
*/


# ifndef M16_h
# define M16_h

#include "Arduino.h"
#include <LCD.h>
#include "LiquidTWI.h"
#include <LiquidCrystal.h>

class M16 
{
public:
	M16(byte butOne, byte butTwo, byte butThree, byte butFour);
	byte checkButtons();
	void buttonSelect(byte butOne, byte butTwo, byte butThree);
	void clear();
	void clearLn(byte lineNum);
	void printVal(byte val);
	void printVal2(byte val);
	void printVal3(int val);
	void printVal4(int val);
	void screen(String scrA, String scrB);
	void menuSelect(int menuVal);
	
	String Clear16;
	
private:
	byte _but1;
	byte _but2;
	byte _but3;
	byte _but4;
	int _menuVal;
};
	
# endif
