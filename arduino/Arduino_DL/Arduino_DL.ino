
int ledPin=13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Within the loop, we will do matrix multiplication
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
} 
