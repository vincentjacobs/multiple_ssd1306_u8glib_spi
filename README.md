# Two SSD1306 OLEDs simultaneously using U8glib with SPI

Quick summary of the things I've learned

- Don't share either the CS line (it selects the right display) or the RES line (u8g.begin() will clear BOTH displays if you do)
- I've not been able to get [Adafruits SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306) to work correctly with these displays. Not just with multiple, also one display showed a correct intro screen but a garbled mess after that. I have used this library successfully with other SSD1306 OLED displays, though, so YMMV.
- I have tried U8g2, but with a faulty pin configuration, so that MAY work.

## Longer version

I bought two cheap SPI OLED displays, more specifically these: 

![front](https://raw.githubusercontent.com/vincentjacobs/multiple_ssd1306_u8glib_spi/master/images/oled_front.jpg)

![back](https://raw.githubusercontent.com/vincentjacobs/multiple_ssd1306_u8glib_spi/master/images/oled_back.jpg)


It took quite a lot of figuring out to get them to work simultaneously. So, for future reference and other folks wrestling with this display type: here's a quick sketch that works.

I used a 5V ATmega328 Arduino Pro Mini: https://www.arduino.cc/en/Main/ArduinoBoardProMini.

Connections:

| First OLED           	| Arduino Pro Mini 	| Description 			            |
|-----------------------|-------------------|-----------------------------------|
| GND 					| GND     		 	| power ground 			            |
| VCC 					| VCC 				| power positive		            |
| D0                    | pin 13    	    | clock wire, SCK, Serial Clock 	|
| D1 					| pin 11			| data wire, MOSI					|
| RES 					| pin 8				| reset wire, RESET 				|
| DC 					| pin 12 			| data/command, selection line 		|
| CS 					| pin 10			| chip select, SS, Slave Select 	|

| Second OLED          	| Arduino Pro Mini 	| Description 			            |
|-----------------------|-------------------|-----------------------------------|
| CS 					| pin 9	    		| chip select, SS, Slave Select 	|
| RES 					| pin 7				| reset wire, RESET 				|




