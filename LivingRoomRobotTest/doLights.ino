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

int cycleWatch=0;
void doAllPatterns() {
  if (cycleWatch != (cycle%7)) {
    cycleWatch=(cycle%7);
    
    if (cycleWatch == 0) {
      doFades();
    } else if (cycleWatch == 1) {
      setupNewTwinklePattern(1);
    } else if (cycleWatch == 2) {
      setupNewTwinklePattern(2);
    } else if (cycleWatch == 3) {
      setupNewTwinklePattern(3);
    } else if (cycleWatch == 4) {    
      setupNewTwinklePattern(4);
    } else if (cycleWatch == 5) {    
      setupNewTwinklePattern(5);
    } else if (cycleWatch == 6) {    
      setupNewTwinklePattern(6);
    } else if (cycleWatch == 7) {    
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
