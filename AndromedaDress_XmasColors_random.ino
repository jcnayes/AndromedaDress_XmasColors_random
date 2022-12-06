// HALLOWEEN 2015: "Andromeda Dress"
//
// Program to control the 16 main 'stars' (NeoPixels) of the Andromeda constellation, 
// sewn onto a black dress.
//
// 2022-12-06: Xmas colors! Randomize red/green/white

#include <Adafruit_NeoPixel.h>

// User-defined parameters //////////////////////////////////////////
// LED output pin on Flora
#define PIN_strip1 9   // 1st "line" of stars
#define PIN_strip2 6   // 2nd "line" of stars
#define PIN_strip3 10  // 3rd "line" of stars

// number of NeoPixels to control
#define starCount_strip1 5    // 1st "line" of stars
#define starCount_strip2 8    // 2nd "line" of stars
#define starCount_strip3 3    // 3rd "line" of stars

#define mySpeed 500  // speed for color changes

// Star color sets
uint32_t cReds[] = {0xFF0000, 0xFF6666, 0x990000, 0x660000, 0xFF3300}; // reds
uint32_t cWhites[] = {0xFFFFFF, 0xFFCCCC, 0xFFFFCC, 0xCCFFCC, 0xCCFFFF, 0xCCCCFF, 0xFFCCFF}; // whites
uint32_t cGreens[] = {0x00FF00, 0x66FF66, 0x009900, 0x006600, 0x33FF00}; // greens
uint32_t cDefault = 0x00FF00; // green default color

uint32_t cAllthecolors[] = {0xFF0000, 0xFF6666, 0x990000, 0x660000, 0xFF3300, 
                            0xFFFFFF, 0xFFCCCC, 0xFFFFCC, 0xCCFFCC, //0xCCFFFF, 0xFFCCFF, 
                            0x00FF00, 0x66FF66, 0x009900, 0x006600, 0x33FF00};

// Set up Pixels
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(starCount_strip1, PIN_strip1, NEO_GRB + NEO_KHZ800); // 1st "line" of stars
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(starCount_strip2, PIN_strip2, NEO_GRB + NEO_KHZ800); // 2nd "line" of stars
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(starCount_strip3, PIN_strip3, NEO_GRB + NEO_KHZ800); // 3rd "line" of stars



void setup() {
  strip1.begin();
  strip1.setBrightness(10); // 1/3 brightness to save battery
  strip1.show();            // Initialize all pixels to 'off'
  strip2.begin();
  strip2.setBrightness(10); // 1/3 brightness to save battery
  strip2.show();            // Initialize all pixels to 'off'
  strip3.begin();
  strip3.setBrightness(10); // 1/3 brightness to save battery
  strip3.show();            // Initialize all pixels to 'off'


}

void loop() {
  colorStars(mySpeed);
  
}




// Change the color of each star/pixel, cycling through its color list/array
void colorStars(int wait) {
  
  int arraySize;
  int whichColor;
  uint32_t color;
  
  // Strip 1
  for (int pos = 0; pos < starCount_strip1; pos ++) {
    arraySize = sizeof(cAllthecolors)/4; // divide by 4 b/c size returned in bytes + array values are in bytes
    whichColor = random(arraySize);
    color = cAllthecolors[whichColor]; // get random color from color array      
    strip1.setPixelColor(pos, color); 
  } // end Strip1
 
 
  // Strip 2
  for (int pos = 0; pos < starCount_strip2; pos ++) {
    arraySize = sizeof(cAllthecolors)/4;
    whichColor = random(arraySize);
    color = cAllthecolors[whichColor];     
    strip2.setPixelColor(pos, color);
  } // end Strip2
 
 
  // Strip 3
  for (int pos = 0; pos < starCount_strip3; pos ++) {
    arraySize = sizeof(cAllthecolors)/4;
    whichColor = random(arraySize);
    color = cAllthecolors[whichColor];
    strip3.setPixelColor(pos, color);
  } // end Strip3
 
  
  strip1.show();
  strip2.show();
  strip3.show();
  delay(wait);
  
}
