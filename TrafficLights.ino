const int RED = 2;
const int YELLOW = 3;
const int GREEN = 4;

void setup() {
  // put your setup code here, to run once:


pinMode(RED, OUTPUT);
pinMode(YELLOW, OUTPUT);
pinMode(GREEN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite (RED, HIGH);
delay(3000);
digitalWrite (RED, LOW);

digitalWrite (GREEN, HIGH);
delay(3000);
digitalWrite (GREEN, LOW);

digitalWrite (YELLOW, HIGH);
delay(1000);
digitalWrite (YELLOW, LOW);


}
