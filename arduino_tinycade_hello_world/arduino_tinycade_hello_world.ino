// simple project using Tinycade 8bit arcade machine (ATTINY85) to show a Hello World messsage

// created by upir, 2023
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE video: https://youtu.be/brjS56u5oHk
// SOURCE files: https://github.com/upiir/tinycade_attiny85_games
// WOKWI simulation: https://wokwi.com/projects/378925799915970561

// Links from the video:
// Buy Tinycade: https://robo.com.cy/products/tinycade-8bit-arcade-machine
// Tinycade Games HEX files: https://github.com/RoboCY/Tinycade
// USBtinyISP Programmer: https://s.click.aliexpress.com/e/_DBwCTlv
// Adafruit USBtinyISP drivers: https://github.com/adafruit/Adafruit_Windows_Drivers/releases/tag/2.5.0.0
// Avrdudess (uploading HEX file to Arduino): https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/
// U8X8 Documentation: https://github.com/olikraus/u8g2/wiki/u8x8reference
// Previous project with ATTINY85+OLED: https://wokwi.com/projects/378474884125460481
// Image2cpp (convert array to image): https://javl.github.io/image2cpp/
// Photopea (online graphics editor like Photoshop): https://www.photopea.com

// Related videos with Arduino UNO and 128x64 OLED screen:
// Arduino + OLED displays: https://www.youtube.com/playlist?list=PLjQRaMdk7pBZ1UV3IL5ol8Qc7R9k-kwXA


#include <Arduino.h>
#include <U8x8lib.h> // u8x8 library for drawing on the OLED display

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 3, /* reset=*/ U8X8_PIN_NONE); // software IIC communication with the OLED display

// image was generated using the image2cpp website
// 'upir_logo_24x8px', 24x8px
unsigned char epd_bitmap_upir_logo_24x8px [] = { 	0x00, 0x00, 0x00, 0x7e, 0x81, 0xbd, 0xa1, 0x9d, 0x81, 0xbd, 0x95, 0x8d, 0x81, 0xb5, 0x81, 0xbd, 0x95, 0xad, 0x81, 0x7e, 0x00, 0x00, 0x00, 0x00};



void setup(void)
{
  u8x8.begin(); // display initialization
  u8x8.setPowerSave(0); // this is required
}

void loop(void)
{
  u8x8.setFont(u8x8_font_chroma48medium8_r); // set some random font
  u8x8.drawString(2,2,"Hello World!"); // draw a Hello World message


  // draw the image defined above, positions are multiplies of 8
  // image is sized 24x8px, 24/8 = 3 tiles
  u8x8.drawTile(/*x*/6, /*y*/5, /*tiles*/3, epd_bitmap_upir_logo_24x8px); 

  delay(2000); // no need to redraw a display since the content is static
}