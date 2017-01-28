#include "U8glib.h"

U8GLIB_SSD1306_128X64 displayOne(13, 11, 10, 12, 8);
U8GLIB_SSD1306_128X64 displayTwo(13, 11, 9, 12, 7);

void setup() {
}

void drawDisplayOne(void) {
  displayOne.setFont(u8g_font_unifont);
  displayOne.setPrintPos(0, 20); 
  displayOne.print("Hello, world!");
}

void drawDisplayTwo(void) {
  displayTwo.setFont(u8g_font_unifont);
  displayTwo.setPrintPos(0, 20); 
  displayTwo.print("Hello, too!");
}

void loop(void) {

  displayOne.begin();
  displayOne.firstPage();  
  do {
    drawDisplayOne();
  } while( displayOne.nextPage() );

  displayTwo.begin();
  displayTwo.firstPage();
  do {
    drawDisplayTwo();
  } while (displayTwo.nextPage() );
  
  delay(5000);
}

