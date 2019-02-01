/* .____    .__      .__              __________                     __________      ___.           __  .____    .__       .__     __          
   |    |   |__|__  _|__| ____    ____\______   \ ____   ____   _____\______   \ ____\_ |__   _____/  |_|    |   |__| ____ |  |___/  |_  ______
   |    |   |  \  \/ /  |/    \  / ___\|       _//  _ \ /  _ \ /     \|       _//  _ \| __ \ /  _ \   __\    |   |  |/ ___\|  |  \   __\/  ___/
   |    |___|  |\   /|  |   |  \/ /_/  >    |   (  <_> |  <_> )  Y Y  \    |   (  <_> ) \_\ (  <_> )  | |    |___|  / /_/  >   Y  \  |  \___ \ 
   |_______ \__| \_/ |__|___|  /\___  /|____|_  /\____/ \____/|__|_|  /____|_  /\____/|___  /\____/|__| |_______ \__\___  /|___|  /__| /____  >
        \/                \//_____/        \/                    \/       \/           \/                    \/ /_____/      \/          */
#include<Arduino.h>
#include<Wire.h>
#include<Keypad.h>
#include<FastLED.h>

const bool testMode = false; 

//change

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};

byte rowPins[ROWS] = {52, 50, 48, 46}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {44, 42, 40}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int totalTimey;
int cycle, currentCycle, timey, slowTimey, vSlowTimey, animLength;

bool rainbowTwinkleMode = false;

int keypadCounter;

const int numLedsStrip = 684;
const int numLedsTotal = numLedsStrip * 4;
CRGB rgbwLeds[numLedsTotal]; // 600 * 4

byte wheelR;
byte wheelG;
byte wheelB;

byte userColR=40;
byte userColG=20;
byte userColB=20;


void setup() {
  if (testMode) {
    Serial.begin(9600);
    Serial.println(" * * Test Mode Start * * ");
  }
  
  // Make random more random
  randomSeed(analogRead(0));

  currentCycle=0;
  animLength=32768; 

  LEDS.addLeds<WS2811_PORTD, 4>(rgbwLeds, numLedsStrip); // Hardcoded to ports:25,26,27,28,14,15
  LEDS.setBrightness(100); // 128 good max, 255 actual /max

  setupNewTwinklePattern(1);
}

void loop() {

  setTimes();

  //allOneColor(1,1,1);
  //LEDS.show();
  allOff1();

  doKeypad();

  doLights();

  LEDS.show();

}

void setTimes() {
  totalTimey = millis()%2147483647;
  cycle = totalTimey / animLength;
  timey = totalTimey % animLength;
  slowTimey = (totalTimey / 10) % animLength;
  vSlowTimey = (totalTimey / 100) % animLength;

}

struct twinkle {
  short ledNum;
  byte rCol;
  byte gCol;
  byte bCol;
  byte rToCol;
  byte gToCol;
  byte bToCol;
  int start;
  short lengthy;
  short widthy;
  short fadeIn;
  short fadeOut;
  short speedy;
  short sideFade;
  bool hasTwinked;

  twinkle(short aLedNum, byte aRCol, byte aGCol, byte aBCol, byte aToRCol, byte aToGCol, byte aToBCol, int aStart, short aLengthy, short aWidthy, short aFadeIn, short aFadeOut, short aSpeedy, short aSideFade, bool aHasTwinked) :
    ledNum(aLedNum), rCol(aRCol), gCol(aGCol), bCol(aBCol), rToCol(aToRCol), gToCol(aToGCol), bToCol(aToBCol), start(aStart), lengthy(aLengthy), widthy(aWidthy), fadeIn(aFadeIn), fadeOut(aFadeOut), speedy(aSpeedy), sideFade(aSideFade), hasTwinked(aHasTwinked) {  }

  twinkle() : ledNum(0), rCol(0), gCol(0), bCol(0), start(0), lengthy(0), widthy(0), fadeIn(0), fadeOut(0), speedy(0), sideFade(0), hasTwinked(0) { }

};

const int numTwinks = 500;
twinkle myTwinkles[numTwinks];
const int usedTwinkleCount[] = {0, 160, 160, 160, 100, 160, 160, 500, 0};


