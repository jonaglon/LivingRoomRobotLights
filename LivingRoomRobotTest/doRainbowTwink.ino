/*
const short speedyDivisor = 50; 

int numRainbowTwinks = 169;

void doRainbowTwinkles() {

  for (int twinky = 0; twinky < numRainbowTwinks; twinky++) {

    int newLedNum = myTwinkles[twinky].ledNum;

    if (myTwinkles[twinky].speedy != 0)
    {
        int ticky = (totalTimey / speedyDivisor)/quickAbsolute(myTwinkles[twinky].speedy);
        if (myTwinkles[twinky].speedy < 0) {
          newLedNum = numLedsStrip-((myTwinkles[twinky].ledNum + ticky)%numLedsStrip);
        } else {
          newLedNum = (myTwinkles[twinky].ledNum + ticky)%numLedsStrip;
        }
    }
    
    int twinkLength = myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut;

    if ((timey > (myTwinkles[twinky].start)) && (timey < (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn))) {
      setLedsFadeIn(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn) > animLength) && (timey < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn) % animLength))) {
      setLedsFadeIn(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((timey >= (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn)) && (timey < (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy))) {
      setLedRainbow(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy) > animLength) && (timey < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy) % animLength))) {
      setLedRainbow(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((timey >= (myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy)) && (timey < (myTwinkles[twinky].start + twinkLength)) ) {
      setLedsFadeOut(newLedNum, twinky, false);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) > animLength) && (timey < ((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) % animLength))) {
      setLedsFadeOut(newLedNum, twinky, true);
      if (!myTwinkles[twinky].hasTwinked)
        myTwinkles[twinky].hasTwinked = true;
    } else if ((timey >= (((myTwinkles[twinky].start + myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut) % animLength))) && myTwinkles[twinky].hasTwinked) {
      resetTwink(twinky);
    }
  }
}


void setLedRainbow(int ledNum, int twinky, bool rolledOver) {

  int percentThroughFade = 0;
  if (rolledOver) {
    percentThroughFade = ((timey + animLength) - myTwinkles[twinky].start) * 100;
  } else {
    percentThroughFade = (timey - myTwinkles[twinky].start) * 100;
  }
  int percentThroughPattern = percentThroughFade / (myTwinkles[twinky].fadeIn + myTwinkles[twinky].lengthy + myTwinkles[twinky].fadeOut);

  int newRed = ((myTwinkles[twinky].rCol + (((myTwinkles[twinky].rToCol - myTwinkles[twinky].rCol) * percentThroughPattern) / 100)));
  int newGreen = ((myTwinkles[twinky].gCol + (((myTwinkles[twinky].gToCol - myTwinkles[twinky].gCol) * percentThroughPattern) / 100)));
  int newBlue = ((myTwinkles[twinky].bCol + (((myTwinkles[twinky].bToCol - myTwinkles[twinky].bCol) * percentThroughPattern) / 100)));

  for (int ledToLight = 0; ledToLight < myTwinkles[twinky].widthy; ledToLight++) {
    int minusFade = myTwinkles[twinky].sideFade * ledToLight;
    int offsetPlus = ledNum + ledToLight;
    int offsetMinus = ledNum - ledToLight;
    setLedDirectStrip(offsetPlus, returnRainbowColor(offsetPlus, minusFade, newRed), returnRainbowColor(offsetPlus, minusFade, newGreen), returnRainbowColor(offsetPlus, minusFade, newBlue), 0);
    setLedDirectStrip(offsetMinus, returnRainbowColor(offsetMinus, minusFade, newRed), returnRainbowColor(offsetMinus, minusFade, newGreen), returnRainbowColor(offsetMinus, minusFade, newBlue), 0);
  }
}

*/

