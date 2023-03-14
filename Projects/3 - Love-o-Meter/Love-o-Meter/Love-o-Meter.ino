const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600); //open a serial port
  
  // Have all LEDs be off
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          n-0

  //convert the ADC reading the voltage            
  float voltage = (sensorVal/1024.0)*5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage-.5)*100;
  Serial.println(temperature);

  if(temperature < baselineTemp){
    for(int pinNumber = 2; pinNumber<5; pinNumber++){
      digitalWrite(pinNumber, LOW);
    }
  }
  else if(temperature >= baselineTemp && temperature < baselineTemp+1){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+1 && temperature < baselineTemp+2){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+3){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  else{
    for(int pinNumber = 2; pinNumber<5; pinNumber++){
      digitalWrite(pinNumber, HIGH);
    }
    delay(100);
    for(int pinNumber = 2; pinNumber<5; pinNumber++){
      digitalWrite(pinNumber, LOW);
    }
    delay(100);
  }
  delay(1);
}
