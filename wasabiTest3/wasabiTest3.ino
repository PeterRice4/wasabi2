#define leftMotorP 1
#define leftMotorN 2
#define rightMotorP 3
#define rightMotorN 4
#define leftEnable 5
#define rightEnable 6
#define leftLine 23
#define rightLine 22
#define leftIR 17
#define middleLeftIR 18
#define middleIR 19
#define middleRightIR 20
#define rightIR 21
#define startModule 16

void setup() {
  pinMode(leftMotorP, OUTPUT);
  pinMode(leftMotorN, OUTPUT);
  pinMode(leftEnable, OUTPUT);
  pinMode(rightMotorP, OUTPUT);
  pinMode(rightMotorN, OUTPUT);
  pinMode(rightEnable, OUTPUT);
  pinMode(leftLine, INPUT);
  pinMode(rightLine, INPUT);
  pinMode(leftIR, INPUT);
  pinMode(middleLeftIR, INPUT);
  pinMode(middleIR, INPUT);
  pinMode(middleRightIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(startModule, INPUT);
}

void loop() {
  
  
  if(digitalRead(startModule) == 1)
  {

    if(analogRead(leftLine) > 200)
  {
    timer(.8, 'B');
    timer(.3, 'R');
    
  }
    else if(analogRead(rightLine) > 200)
  {
    timer(.8, 'B');
    timer(.3, 'L');
    
  }
  else 
  {

     if(digitalRead(middleIR) == 1)
    {
      forward();
      delay(50);
    }
    else if(digitalRead(middleRightIR) == 1)
    {
      veerR();
      delay(50);
    }
     else if(digitalRead(middleLeftIR) == 1)
    {
      veerL();
      delay(50);
    }
    else if(digitalRead(leftIR) == 1)
    {
      //timer(1, 'L');
      while(digitalRead(middleLeftIR) == 0)
      {
        turnL();
      }


      delay(100);
    }
    else if(digitalRead(rightIR) == 1)
    {
     // timer(1, 'R');

     while(digitalRead(middleRightIR) == 0)
      {
        turnR();
      }

      delay(100);
    }
    else 
    {
      search();
    }
  }




  







  }

else if(startModule == 0)
  {
    digitalWrite(leftEnable, 1);
    digitalWrite(rightEnable, 1);

   digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, LOW);
  digitalWrite(rightMotorP, LOW);
  digitalWrite(rightMotorN, LOW);
  }

}

void back() {
analogWrite(leftEnable, 80);
 analogWrite(rightEnable, 80);

  digitalWrite(leftMotorP, HIGH);
  digitalWrite(leftMotorN, LOW);
  digitalWrite(rightMotorP, LOW);
  digitalWrite(rightMotorN, HIGH);
}

void forward() {

analogWrite(leftEnable, 100);
  analogWrite(rightEnable, 100);

 digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, HIGH);
  digitalWrite(rightMotorP, HIGH);
  digitalWrite(rightMotorN, LOW);

}

void stop() {
analogWrite(leftEnable, 0);
 analogWrite(rightEnable, 0);

  digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, LOW);
  digitalWrite(rightMotorP, LOW);
  digitalWrite(rightMotorN, LOW);
}

void turnL() {
  analogWrite(leftEnable, 60);
 analogWrite(rightEnable, 60);

  digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, HIGH);
  digitalWrite(rightMotorP, LOW);
  digitalWrite(rightMotorN, HIGH);
}



void veerL() {
  analogWrite(leftEnable, 100);
 analogWrite(rightEnable, 80);

  digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, HIGH);
  digitalWrite(rightMotorP, HIGH);
  digitalWrite(rightMotorN, LOW);
}

void veerR() {
  analogWrite(leftEnable, 60);
 analogWrite(rightEnable, 120);

  digitalWrite(leftMotorP, LOW);
  digitalWrite(leftMotorN, HIGH);
  digitalWrite(rightMotorP, HIGH);
  digitalWrite(rightMotorN, LOW);
}



void turnR() {
analogWrite(leftEnable, 60);
 analogWrite(rightEnable, 60);

  digitalWrite(leftMotorP, HIGH);
  digitalWrite(leftMotorN, LOW);
  digitalWrite(rightMotorP, HIGH);
  digitalWrite(rightMotorN, LOW);
}
boolean seeLine() {
  if (analogRead(leftLine) > 200 || analogRead(rightLine) > 200) {
    return true;
  }
  return false;
}

void timer(double seconds, char direction) {
  int currentTime = millis();
  //flip while and switch statement later
  while (currentTime + (seconds * 1000) != millis()) {
    switch (direction) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        turnL();
        break;
      case 'R':
        turnR();
        break;
    }
  }
}

void search()
{
   

  while (digitalRead(middleIR) == 0) {


    for(int i=1; i<5; i++)
    {
    turnL();
    delay(150);
    if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
      break;
    }
    veerL();
    delay(200);
    if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
      break;
    }
    turnR();
    delay(150);
    if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
      break;
    }
    veerR();
    delay(200);
   if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
      break;
    }
    }
    turnR();
    for(int j=1; j<5; j++){
    
    if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
      break;
    }
    delay(100);
    }

  }
  if((digitalRead(middleIR) == 1)||(digitalRead(middleLeftIR) == 1)||(digitalRead(middleRightIR) == 1)||(digitalRead(leftIR) == 1)||(digitalRead(rightIR) == 1)||analogRead(leftLine) > 200 || analogRead(rightLine) > 200)
    {
    stop();
    
  }
}