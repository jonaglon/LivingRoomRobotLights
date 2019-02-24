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
const bool beatTestMode = false;

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

//int timeyInTime;
int timey, animLength;

int lastBeatTime = 0;
int timeyInTime; // This is like timey but in time, counting 16384 per beat
int slowTimeyInTime;
int twinkleTime;
int lastBeatLength = 420;
int percentThroughBeat = 0;  // Not really a percent, beat divides into 16384 parts
int fakeBeatCount = 0;
int fakeBeatLengh = 420;
// Set by midi in to be 1-16 with beat.
int sixteenBeats = 0;
int currentBar = 0;
int dropCountdown = 0;
int mixCurrentBar = 0; // This counts from the start of a mix
int currentGenre = 0;
int currentTrack = 0;
bool currentlyMixing = false;


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
  Serial.begin(115200);
  
  // Make random more random
  randomSeed(analogRead(0));

  animLength=524288; //524288; // 32768; //8192;

  LEDS.addLeds<WS2811_PORTD, 4>(rgbwLeds, numLedsStrip); // Hardcoded to ports:25,26,27,28,14,15
  LEDS.setBrightness(90); // 128 good max, 255 actual /max

  setupNewTwinklePattern(2);
}

void loop() {
  timey = millis();

  listenToAbleton();

  setTimes();

  allOff2();

  doKeypad();

  doFades();

  doLights();

  lightsBeatTest();

  LEDS.show();

}

void setTimes() {

  if (timey > (lastBeatTime + lastBeatLength)) {
    percentThroughBeat = 16383;
  } else {
    percentThroughBeat = (((timey - lastBeatTime) * 16384) / lastBeatLength);  // 16384 is the beat length
    if (percentThroughBeat > 16383)
      percentThroughBeat = 16383;
  }

  // this is a number to be used in animations, it counts up from the start of a tune, 16384 per beat.
  // timeyInTime = (((sixteenBeats * 16384) + percentThroughBeat) + (currentBar * 65536))%2147483647;
  int currentCalc = ((currentBar-1)/4)*262144;
  timeyInTime = ((sixteenBeats * 16384) + percentThroughBeat)+currentCalc;
  slowTimeyInTime = timeyInTime/16;
  twinkleTime = timeyInTime % animLength;

  if (testMode) {
    Serial.print("tt:");
    Serial.print(twinkleTime);
    Serial.print("  cb:");
    Serial.print(currentBar);
    Serial.print("  %:");
    Serial.print(percentThroughBeat);
    Serial.print("  16:");
    Serial.print(sixteenBeats);
    Serial.print("  tit:");
    Serial.println(timeyInTime);
  }
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
  int lengthy;
  short widthy;
  int fadeIn;
  int fadeOut;
  short speedy;
  short sideFade;
  bool hasTwinked;

  twinkle(short aLedNum, byte aRCol, byte aGCol, byte aBCol, byte aToRCol, byte aToGCol, byte aToBCol, int aStart, int aLengthy, short aWidthy, int aFadeIn, int aFadeOut, short aSpeedy, short aSideFade, bool aHasTwinked) :
    ledNum(aLedNum), rCol(aRCol), gCol(aGCol), bCol(aBCol), rToCol(aToRCol), gToCol(aToGCol), bToCol(aToBCol), start(aStart), lengthy(aLengthy), widthy(aWidthy), fadeIn(aFadeIn), fadeOut(aFadeOut), speedy(aSpeedy), sideFade(aSideFade), hasTwinked(aHasTwinked) {  }

  twinkle() : ledNum(0), rCol(0), gCol(0), bCol(0), start(0), lengthy(0), widthy(0), fadeIn(0), fadeOut(0), speedy(0), sideFade(0), hasTwinked(0) { }

};

const int numTwinks = 1000;
twinkle myTwinkles[numTwinks];
const int usedTwinkleCount[] = {0, 700, 600, 600, 600, 660, 660, 1000, 0};


