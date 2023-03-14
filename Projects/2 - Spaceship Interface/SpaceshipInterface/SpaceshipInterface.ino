//Celia Evans 
//March 8th, 2023

//Spaceship Interface
//**CODE COPIED FROM ARDUINO PROJECTS BOOK**
//Comments written by CE for clarification.

//init vars
int switchState = 0;

void setup() { //run once for setup
  //Set uses of all pins:
  //outs:
  pinMode(3, OUTPUT);//green led
  pinMode(4, OUTPUT);//yellow led
  pinMode(5, OUTPUT);//red led
  //ins:
  pinMode(2, INPUT);//push button
}

void loop() { //loops forever, AKA main loop

  switchState = digitalRead(2);//read pb

  if(switchState == LOW){ //button unpressed

    digitalWrite(3, HIGH); //green on
    digitalWrite(4, LOW); //yellow off
    digitalWrite(5, LOW); //red off

  }
  else{ //button pressed
    //set
    digitalWrite(3, LOW); //green off
    digitalWrite(4, HIGH); //yellow on
    digitalWrite(5, LOW); //red off
    
    delay(100); //wait 250ms
    
    digitalWrite(4, LOW); //yellow off
    digitalWrite(5, HIGH); //red on

    delay(100); //wait 250ms
  }
}//loop again
