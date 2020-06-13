
// WORKING CODE FOR RECORDING DATA FROM THE WATER METER
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = 2;
volatile int triggerCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(input,INPUT);
  attachInterrupt(digitalPinToInterrupt(2), pulseHigh, RISING); 
  // put your setup code here, to run once:

}

void loop() {
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  
  // put your main code here, to run repeatedly:

}

void pulseHigh()
{
  triggerCount= triggerCount + 1;
  Serial.print("Interrupt received : Trigger Count is : ");
  Serial.print(triggerCount);
  Serial.print("\n");
}
