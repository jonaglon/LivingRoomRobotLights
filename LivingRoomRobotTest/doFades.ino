int fadeLength = 20000;
int myCycle = 0;

void doFades() {  

  myCycle = (slowTimeyInTime / fadeLength)%7;

  if (myCycle == 0) {
    doFading(245,140,7,245,7,225);
  } else if (myCycle == 1) {
    doFading(245,7,225,2, 133, 142);
  } else if (myCycle == 2) {
    doFading(2, 133, 142,0,2,40);
  } else if (myCycle == 3) {
    doFading(0,2,40,82,104,2);
  } else if (myCycle == 4) {
    doFading(82,104,2,80,20,70);
  } else if (myCycle == 5) {
    doFading(80,20,70,userColR,userColG,userColB);
  } else if (myCycle == 6) {
    doFading(userColR,userColG,userColB,245,140,7);
  }
}

void doCycles() {  

  myCycle = (slowTimeyInTime / fadeLength)%7;
  
  if (myCycle == 0) {
    doColour(245,140,7);
  } else if (myCycle == 1) {
    doColour(245,7,225);
  } else if (myCycle == 2) {
    doColour(2, 133, 142);
  } else if (myCycle == 3) {
    doColour(0,2,40);
  } else if (myCycle == 4) {    
    doColour(82,104,2);
  } else if (myCycle == 5) {    
    doColour(80,20,70);
  } else {    
    doColour(userColR,userColG,userColB);
  }
}
 

void doFading(int firstR, int firstG, int firstB, int secondR, int secondG, int secondB) {
  int myTimey = slowTimeyInTime % fadeLength;

  int newRed = firstR + ((((secondR-firstR)*10000)/fadeLength) * myTimey)/10000;
  int newGreen = firstG + ((((secondG-firstG)*10000)/fadeLength) * myTimey)/10000;
  int newBlue = firstB + ((((secondB-firstB)*10000)/fadeLength) * myTimey)/10000;

  /*if (testMode) {
    Serial.print("    myCycle:");
    Serial.print(myCycle);
    Serial.print("    myTimey:");
    Serial.print(myTimey);    
    Serial.print("    newRed:");
    Serial.print(newRed);    
    Serial.print("    newGreen:");
    Serial.print(newGreen);    
    Serial.print("    newBlue:");
    Serial.println(newBlue);    
  }*/

  for (int pixNum = 0; pixNum < numLedsTotal; pixNum++) {
    setLedDirect(pixNum, newRed, newGreen, newBlue, 0);
  }
}

void doColour(int theR, int theG, int theB) {
  for (int pixNum = 0; pixNum < numLedsTotal; pixNum++) {
    setLedDirect(pixNum, (theR), (theG), (theB), 0);
  }
}


