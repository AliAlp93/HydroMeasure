#include "Screen.h"
String results[SENSORCOUNT] = { "PH =", "Temp(C)=", "DO(mg/l)=","Ec(ms/cm)=","Nem= ","Oda(C)=" ,"Isik(Lux)=" };

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

Screen::Screen(ISensor * gravitySensor[]) { 
	this->gravitySensor = gravitySensor;
}


Screen :: ~Screen()
{
}

void Screen::setup() {

	lcd.begin(16, 2);                       // start the library
	lcd.setCursor(0, 0);                   // set the LCD cursor   position
	lcd.print("Hosgeldin");
	delay(3000);
  lcd.clear();
	lcd.print("Sistem Basliyor!!");
	delay(3000);
  
}


void Screen::update()
{
	for (int i = 0; i < SENSORCOUNT; i++) //SENSORCOUNT
	{
		if (this->gravitySensor[i] != NULL)
		{
			double Value = this->gravitySensor[i]->getValue();
      lcd.clear();
			lcd.print(results[i]);
			lcd.print(Value);
			delay(5000);
		}
	

	}

}
