volatile double waterVolume;
volatile double waterFlowRate = 0.0;
volatile int previousTime = 0;
boolean isTriggered = false;
double pulseWidth = 0.0;
 
void setup() {
  Serial.begin(9600);  //baudrate
  waterVolume = 0;
  attachInterrupt(digitalPinToInterrupt(2), pulseHigh, RISING);  //DIGITAL Pin 2: Interrupt 0
}
void loop() {
  Serial.print("Total Water Volume:");
  Serial.print(waterVolume);
  Serial.println("   L");
  Serial.print("Flow Rate:");
  if(isTriggered){
    Serial.print("Trigger is happening");
    Serial.print(waterFlowRate);
    isTriggered = false;
  }else{
    Serial.print("No trigger captured");
    Serial.print("0.0");
  }
  Serial.println("  L/min");
  delay(500);
}
 
void pulseHigh()   //measure the quantity of square wave
{
  isTriggered = true;
  //waterVolume += 1.0 / 5880.0;
  waterVolume += 1.00;
  attachInterrupt(digitalPinToInterrupt(2), pulseLow, FALLING);
  previousTime = millis();
}
 
void pulseLow()
{
  pulseWidth = millis()-previousTime;
  waterFlowRate = (1000.0/5880.0) / pulseWidth;
}
