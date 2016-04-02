#include "SEPS525_OLED.h"
#include "Adafruit_GFX.h"
#include <SPI.h>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

SEPS525_OLED tft;
int wh_h_l, bl_h_l;
void setup(void) {
  Serial.begin(9600);
  tft.begin();
}

int incomingByte;

void loop(void) 
{

	if (Serial.available() > 0)
	{
		incomingByte = Serial.read();
		swch(incomingByte - '0');
	}
}

void init_line(void)
{
	wh_h_l = 1;
	bl_h_l = 1;
}

void white_line(void)
{
	bl_h_l = 1;
	tft.drawFastHLine(0, tft.height() / 2 - wh_h_l, tft.width(), WHITE);
	Serial.println(wh_h_l);
	wh_h_l++;
}

void black_line(void)
{
	wh_h_l = 1;
	tft.drawFastHLine(0, tft.height() / 2 - bl_h_l, tft.width(), BLACK);
	Serial.println(bl_h_l);
	bl_h_l++;
}

void experiment1(void)
{
	init_line();
	tft.fillScreen(BLACK);
	tft.fillRect(0, 0, tft.width(), tft.height() / 2, WHITE);
	Serial.println("experiment 1 is ready");
}

void experiment2(void)
{
	init_line();
	tft.fillScreen(BLACK);
	Serial.println("experiment 2 is ready");
}

void swch(uint8_t indx)
{
	switch (indx)
	{
	case 0:
		init_line();
		break;
	case 1:
		experiment1();
		break;
	case 2:
		experiment2();
		break;
	case 3:
		black_line();
		break;
	case 4:
		white_line();
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		break;
	}
}