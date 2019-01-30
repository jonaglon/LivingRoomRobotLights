void doKeypad() {

 char customKey = customKeypad.getKey();

  if (customKey != NO_KEY)
  {
    keypadPressed(customKey);
  }
}

void keypadPressed(char key) {

  if (testMode) {
    Serial.print("k!");
    Serial.println(key);
  }
    
  if (key == '#')
    startColorInput();
  else if (key == '*') {
    startIntensityInput();
  } else if (key == '1')
    changeLightPattern(1);
  else if (key == '2')
    changeLightPattern(2);
  else if (key == '3')
    changeLightPattern(3);
  else if (key == '4')
    changeLightPattern(4);
  else if (key == '5')
    changeLightPattern(5);
  else if (key == '6')
    changeLightPattern(6);
  else if (key == '7')
    changeLightPattern(7);
  else if (key == '8')
    changeLightPattern(8);
  else if (key == '9')
    changeLightPattern(9);
  else if (key == '0')
    changeLightPattern(0);

}

void startColorInput() {

  allOneColor(40, 0, 0);
  LEDS.show();
  
  keypadCounter=0;
  userColR=0;
  userColG=0;
  userColB=0;
  bool foundColor = false;

  while (!foundColor) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY)
    {
      if (customKey == '#')
        foundColor = true;
      if (colGrabKeypadPressed(customKey)) {
        foundColor = true;
      }
    }
  }
  allOneColor(0, 40, 0);
  LEDS.show();
  delay(200);
  changeLightPattern(0);
}

void startIntensityInput() {
  if (testMode) {
    Serial.print("Doing intensity");
  }

  bool foundIntensity = false;

  allOneColor(0, 0, 40);
  LEDS.show();
  
  while (!foundIntensity) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY)
    {
      if (customKey == '#')
        foundIntensity = true;
      if (intensityGrabKeypadPressed(customKey)) {
        foundIntensity = true;
      }
    }
  }
  allOneColor(0, 100, 0);
  LEDS.show();
  delay(200);
}

short getKeypadPressed(char key) {

  if (testMode) {
    Serial.print("received:");
    Serial.println(key);
  }
  
  if (key == '0')
    return 0;
  else if (key == '1')
    return 1;
  else if (key == '2')
    return 2;
  else if (key == '3')
    return 3;
  else if (key == '4')
    return 4;
  else if (key == '5')
    return 5;
  else if (key == '6')
    return 6;
  else if (key == '7')
    return 7;
  else if (key == '8')
    return 8;
  else if (key == '9')
    return 9;
}

short colChangeNum=0;
bool colGrabKeypadPressed(char key) {
  short numberToAdd=getKeypadPressed(key);
  
  if (testMode) {
    Serial.print("Intensity, got:");
    Serial.println(numberToAdd);
  }

  if (colChangeNum == 0)
    userColR = userColR + (100 * numberToAdd);
  else if (colChangeNum == 1)
    userColR = userColR + (10 * numberToAdd);
  else if (colChangeNum == 2)
    userColR = userColR + numberToAdd;
  else if (colChangeNum == 3)
    userColG = userColG + (100 * numberToAdd);
  else if (colChangeNum == 4)
    userColG = userColG + (10 * numberToAdd);
  else if (colChangeNum == 5)
    userColG = userColG + numberToAdd;
  else if (colChangeNum == 6)
    userColB = userColB + (100 * numberToAdd);
  else if (colChangeNum == 7)
    userColB = userColB + (10 * numberToAdd);
  else if (colChangeNum == 8)
    userColB = userColB + numberToAdd;

  colChangeNum=colChangeNum+1;
  if (colChangeNum == 9) {
    if (testMode) {
      Serial.print("r:");
      Serial.print(userColR);
      Serial.print(" g:");
      Serial.print(userColG);
      Serial.print(" b:");
      Serial.println(userColB);
    }
    colChangeNum=0;
    changeLightPattern(0);
    return true;
  }  else {
    return false;
  }
}

int intensityChangeVar=0;
int intensityChangeCounter=0;
bool intensityGrabKeypadPressed(char key) {
  short numberToAdd =getKeypadPressed(key);

  if (intensityChangeCounter == 0)
    intensityChangeVar = intensityChangeVar + (100 * (numberToAdd%3));
  else if (intensityChangeCounter == 1)
    intensityChangeVar = intensityChangeVar + (10 * numberToAdd);
  else if (intensityChangeCounter == 2)
    intensityChangeVar = intensityChangeVar + numberToAdd;

  intensityChangeCounter=intensityChangeCounter+1;
  if (intensityChangeCounter == 3) {
    if (testMode) {
      Serial.print("Intensity:");
      Serial.print(intensityChangeVar);
    }
    LEDS.setBrightness(intensityChangeVar);
    intensityChangeVar=0;
    intensityChangeCounter=0;
    return true;
  }  else {
    return false;
  }
}

