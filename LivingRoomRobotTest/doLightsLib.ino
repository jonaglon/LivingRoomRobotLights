
void allOff1() {
  for(int j = 0; j < numLedsTotal; j++) {
    setLedDirect(j, 0, 0, 0, 0);
  }
}

void allOff2() {
  for(int j = 0; j < numLedsStrip; j++) {
    setLedDirectStrip(j, 0, 0, 0, 0);
  }
}

void allOn() {
  for(int j = 0; j < numLedsTotal; j++) {
    setLedDirect(j, 40, 20, 20, 0);
  }
}

void allOneColor(int r, int g, int b) {
  for(int j = 0; j < numLedsTotal; j++) {
      setLedDirect(j, r, g, b, 0);
  }
}

void setLedDirect(int ledNum, int rVal, int gVal, int bVal, int wVal) {
    int whitey = wVal/3;
    rgbwLeds[ledNum].r = (rVal + whitey) % 255;
    rgbwLeds[ledNum].g = (gVal + whitey) % 255;
    rgbwLeds[ledNum].b = (bVal + whitey) % 255;
}

void setLedDirectStrip(int ledNum, int rVal, int gVal, int bVal, int wVal) {
    if (rVal < 0)
      rVal = 0;
    if (gVal < 0)
      gVal = 0;
    if (bVal < 0)
      bVal = 0;
    if (wVal < 0)
      wVal = 0;
    if (ledNum < 0)
      ledNum = 0;

    ledNum = ledNum%numLedsStrip;
    int whitey = wVal/3;

    rgbwLeds[ledNum].r = (rVal + whitey) > 255 ? 255 : (rVal + whitey);
    rgbwLeds[ledNum].g = (gVal + whitey) > 255 ? 255 : (gVal + whitey);
    rgbwLeds[ledNum].b = (bVal + whitey) > 255 ? 255 : (bVal + whitey);

    rgbwLeds[numLedsStrip + ledNum].r = (rVal + whitey) > 255 ? 255 : (rVal + whitey);
    rgbwLeds[numLedsStrip + ledNum].g = (gVal + whitey) > 255 ? 255 : (gVal + whitey);
    rgbwLeds[numLedsStrip + ledNum].b = (bVal + whitey) > 255 ? 255 : (bVal + whitey);

    rgbwLeds[(numLedsStrip*2) + ledNum].r = (rVal + whitey) > 255 ? 255 : (rVal + whitey);
    rgbwLeds[(numLedsStrip*2) + ledNum].g = (gVal + whitey) > 255 ? 255 : (gVal + whitey);
    rgbwLeds[(numLedsStrip*2) + ledNum].b = (bVal + whitey) > 255 ? 255 : (bVal + whitey);

    rgbwLeds[(numLedsStrip*3) + ledNum].r = (rVal + whitey) > 255 ? 255 : (rVal + whitey);
    rgbwLeds[(numLedsStrip*3) + ledNum].g = (gVal + whitey) > 255 ? 255 : (gVal + whitey);
    rgbwLeds[(numLedsStrip*3) + ledNum].b = (bVal + whitey) > 255 ? 255 : (bVal + whitey);
}


int getCoord(int ledNum, int xOrY) {
  if (ledNum < 2003)
     return 10;
}


int quickAbsolute(int number) {
  if (number < 0)
    return number * (-1);
  else
    return number;
}



void SetRgbwWheelVars(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    wheelR = 255 - WheelPos * 3;
    wheelG = 0;
    wheelB = WheelPos * 3;
    return;
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    wheelR = 0;
    wheelG = WheelPos * 3;
    wheelB = 255 - WheelPos * 3;
    return;
  }
  WheelPos -= 170;
  wheelR = WheelPos * 3;
  wheelG = 255 - WheelPos * 3;
  wheelB = 0;
  return;
}

int goodColR, goodColG, goodColB, goodColW;
void setGoodRandomColorVars() {
  int randomNum = random(4);
  switch (randomNum) {
    case 0: 
      goodColR = 255;
      goodColG = 0;
      goodColB = 0;
      goodColW = 0;
      break;
    case 1: 
      goodColR = 0;
      goodColG = 255;
      goodColB = 0;
      goodColW = 0;
      break;
    case 2: 
      goodColR = 0;
      goodColG = 0;
      goodColB = 255;
      goodColW = 0;
      break;
    case 3: 
      goodColR = 0;
      goodColG = 0;
      goodColB = 0;
      goodColW = 255;
      break;
  }
}




