// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include "RTClib.h"
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        8 // On Trinket or Gemma, suggest changing this to 1
#define PIN1       7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size
#define NUMPIXELS1 64

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

RTC_DS1307 rtc; //initialize correct RTC version

void setup() {
  Serial.begin(9600); //set BAUD of Arduino
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels1.begin();
}

void loop() {

  //initialize time variables
  int hour = 0;
  int minute = 0;

  //update time variables with RTC values
  DateTime now = rtc.now();
  hour = now.hour();
  minute = now.minute();

    if ((minute % 5) != 0) //round down minute to next lowest multiple of 5
  {
    int aboveFive = (minute % 5);
    minute = minute - aboveFive;
  }

  if (minute == 0 || minute == 5 || minute == 10) //make Viertel, Halb, Dreviertel work correctly
  {} else {
    hour += 1;
  }

  if (hour > 12) //AM PM swap
  {
    hour = hour % 12;

    pixels.setPixelColor(3, pixels.Color(100, 0, 0)); //"NACH"
    pixels.setPixelColor(2, pixels.Color(100, 0, 0));
    pixels.setPixelColor(1, pixels.Color(100, 0, 0));
    pixels.setPixelColor(0, pixels.Color(100, 0, 0));

    pixels1.setPixelColor(7, pixels.Color(100, 0, 0)); //"MITTAGS"
    pixels1.setPixelColor(6, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(5, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(4, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(3, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(2, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(1, pixels.Color(100, 0, 0));
    pixels1.show();
  } else {
    pixels.setPixelColor(7, pixels.Color(100, 0, 0)); //"VOR"
    pixels.setPixelColor(6, pixels.Color(100, 0, 0));
    pixels.setPixelColor(5, pixels.Color(100, 0, 0));

    pixels1.setPixelColor(7, pixels.Color(100, 0, 0)); //"MITTAGS"
    pixels1.setPixelColor(6, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(5, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(4, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(3, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(2, pixels.Color(100, 0, 0));
    pixels1.setPixelColor(1, pixels.Color(100, 0, 0));
  }

  pixels.setPixelColor(63, pixels.Color(100, 0, 0)); //"ES IST"
  pixels.setPixelColor(62, pixels.Color(100, 0, 0));
  pixels.setPixelColor(52, pixels.Color(100, 0, 0));
  pixels.setPixelColor(51, pixels.Color(100, 0, 0));
  pixels.setPixelColor(50, pixels.Color(100, 0, 0));
  pixels.show();


  //switch on correct LEDs for the corresponding hours/minutes
  switch (hour)
  {
    case 0:
      pixels.setPixelColor(39, pixels.Color(100, 0, 0));
      pixels.setPixelColor(38, pixels.Color(100, 0, 0));
      pixels.setPixelColor(37, pixels.Color(100, 0, 0));
      pixels.setPixelColor(36, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 1:
      pixels.setPixelColor(35, pixels.Color(100, 0, 0));
      pixels.setPixelColor(34, pixels.Color(100, 0, 0));
      pixels.setPixelColor(33, pixels.Color(100, 0, 0));
      pixels.setPixelColor(32, pixels.Color(100, 0, 0));
      if (minute == 0) // "ES IST EIN(S) UHR"
      {
        pixels.setPixelColor(32, pixels.Color(0, 0, 0));
        pixels.show();
      }
      pixels.show();
      break;
    case 2:
      pixels1.setPixelColor(39, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(38, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(37, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(36, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 3:
      pixels1.setPixelColor(35, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(34, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(33, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(32, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 4:
      pixels.setPixelColor(31, pixels.Color(100, 0, 0));
      pixels.setPixelColor(30, pixels.Color(100, 0, 0));
      pixels.setPixelColor(29, pixels.Color(100, 0, 0));
      pixels.setPixelColor(28, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 5:
      pixels.setPixelColor(27, pixels.Color(100, 0, 0));
      pixels.setPixelColor(26, pixels.Color(100, 0, 0));
      pixels.setPixelColor(25, pixels.Color(100, 0, 0));
      pixels.setPixelColor(24, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 6:
      pixels1.setPixelColor(30, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(29, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(28, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(27, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(26, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 7:
      pixels.setPixelColor(22, pixels.Color(100, 0, 0));
      pixels.setPixelColor(21, pixels.Color(100, 0, 0));
      pixels.setPixelColor(20, pixels.Color(100, 0, 0));
      pixels.setPixelColor(19, pixels.Color(100, 0, 0));
      pixels.setPixelColor(18, pixels.Color(100, 0, 0));
      pixels.setPixelColor(17, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 8:
      pixels1.setPixelColor(23, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(22, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(21, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(20, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 9:
      pixels1.setPixelColor(19, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(18, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(17, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(16, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 10:
      pixels.setPixelColor(15, pixels.Color(100, 0, 0));
      pixels.setPixelColor(14, pixels.Color(100, 0, 0));
      pixels.setPixelColor(13, pixels.Color(100, 0, 0));
      pixels.setPixelColor(12, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 11:
      pixels.setPixelColor(10, pixels.Color(100, 0, 0));
      pixels.setPixelColor(9, pixels.Color(100, 0, 0));
      pixels.setPixelColor(8, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 12:
      pixels1.setPixelColor(15, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(14, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(13, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(12, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(11, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    default:
      Serial.println("errH");
      pixels.clear(); // Set all pixel colors to 'off'
      pixels1.clear();
      break;
  }

  switch (minute)
  {
    case 0:
      pixels1.setPixelColor(8, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(9, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(10, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 5:
      pixels1.setPixelColor(63, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(62, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(61, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(60, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(51, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(50, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(49, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(48, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 10:
      pixels1.setPixelColor(59, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(58, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(57, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(56, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(51, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(50, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(49, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(48, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 15:
      pixels1.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(43, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(42, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(41, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 20:
      pixels1.setPixelColor(59, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(58, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(57, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(56, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(55, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(54, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(53, pixels.Color(100, 0, 0));

      pixels.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 25:
      pixels1.setPixelColor(63, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(62, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(61, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(60, pixels.Color(100, 0, 0));

      pixels1.setPixelColor(55, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(54, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(53, pixels.Color(100, 0, 0));

      pixels.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 30:
      pixels.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 35:
      pixels1.setPixelColor(63, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(62, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(61, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(60, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(51, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(50, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(49, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(48, pixels.Color(100, 0, 0));

      pixels.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 40:
      pixels1.setPixelColor(59, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(58, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(57, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(56, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(51, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(50, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(49, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(48, pixels.Color(100, 0, 0));

      pixels.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels.show();
      break;
    case 45:
      pixels.setPixelColor(43, pixels.Color(100, 0, 0));
      pixels.setPixelColor(42, pixels.Color(100, 0, 0));
      pixels.setPixelColor(41, pixels.Color(100, 0, 0));
      pixels.setPixelColor(40, pixels.Color(100, 0, 0));

      pixels1.setPixelColor(47, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(46, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(45, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(44, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(43, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(42, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(41, pixels.Color(100, 0, 0));
      pixels.show();
      pixels1.show();
      break;
    case 50:
      pixels1.setPixelColor(59, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(58, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(57, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(56, pixels.Color(100, 0, 0));
      
      pixels1.setPixelColor(55, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(54, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(53, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    case 55:
      pixels1.setPixelColor(63, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(62, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(61, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(60, pixels.Color(100, 0, 0));

      pixels1.setPixelColor(55, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(54, pixels.Color(100, 0, 0));
      pixels1.setPixelColor(53, pixels.Color(100, 0, 0));
      pixels1.show();
      break;
    default:
      pixels.clear(); // Set all pixel colors to 'off'
      pixels1.clear();
      Serial.println("errM");
      break;
  }

  delay(DELAYVAL);

  /*pixels.clear(); // Set all pixel colors to 'off'
  pixels1.clear();


    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(50, 0, 0));
    pixels1.setPixelColor(i, pixels.Color(50, 0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.
    pixels1.show();

    delay(DELAYVAL); // Pause before next pass through loop
    }*/



}
