int currentPattern = 2;
int numPatterns = 10;
int twinkleNum=0;

void doLights() {

  if (currentPattern == 0) {
    doAllPatterns();
  } if (currentPattern < 8) {    
    doTwinkles();
  } else if (currentPattern == 8) {
    doFades();
  } else if (currentPattern == 9) {
    allOneColor(userColR,userColG,userColB);
  }
}

int barWatch=0;
void doAllPatterns() {
  if (barWatch != (currentBar%7)) {
    barWatch=(currentBar%7);
    
    if (barWatch == 0) {
      doFades();
    } else if (barWatch == 1) {
      setupNewTwinklePattern(1);
    } else if (barWatch == 2) {
      setupNewTwinklePattern(2);
    } else if (barWatch == 3) {
      setupNewTwinklePattern(3);
    } else if (barWatch == 4) {    
      setupNewTwinklePattern(4);
    } else if (barWatch == 5) {    
      setupNewTwinklePattern(5);
    } else if (barWatch == 6) {    
      setupNewTwinklePattern(6);
    } else if (barWatch == 7) {    
      setupNewTwinklePattern(7);
    }
    
  }
}



void changeLightPattern(int newPatternNum) {

  if (newPatternNum != 9)
    currentPattern = newPatternNum;
  
  if (newPatternNum == 1) {
    setupNewTwinklePattern(1);
  } else if (newPatternNum == 2) {
    setupNewTwinklePattern(2);
  } else if (newPatternNum == 3) {
    setupNewTwinklePattern(3);
  } else if (newPatternNum == 4) {
    setupNewTwinklePattern(4);
  } else if (newPatternNum == 5) {
    setupNewTwinklePattern(5);
  } else if (newPatternNum == 6) {
    setupNewTwinklePattern(6);
  } else if (newPatternNum == 7) {
    setupNewTwinklePattern(7);
  } else if (newPatternNum == 9) {
    if (rainbowTwinkleMode)
      rainbowTwinkleMode=false;
    else
      rainbowTwinkleMode=true;
  }
}

/////////////////////
// Generic patters //
/////////////////////



void horizontalRainbow(bool includeEyes, bool includeMouth, int speedFactor) {
  int ticko = (timey / speedFactor) % 1024;
  
  for(int j = 0; j < numLedsTotal; j++) {
    int xCoord = (getCoord(j,0)+ticko)%1024;
    setLedDirect(j, wheelR, wheelG, wheelB, 0);    
  }
}
