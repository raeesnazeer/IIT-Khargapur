#define rc1 A1 // receiver chanel 1 on pin 9
#define rc2 A2 // receiver chanel 2 on pin 10
#define rc3 A3 // receiver chanel 3 on pin 11
#define rc4 12 // receiver chanel 4 on pin 12

#define spdLeft 5 // PWM pin on L298N
#define spdRight 6 // PWM pin on L298N

#define left1 4 // in 2 pin on L298N to pin 4 on ARDUINO
#define left2 3 // in 3 pin on L298N to pin 3 on ARDUINO


#define right1 7 // in 4 pin on L298N to pin 7 on ARDUINO
#define right2 8 // in 5 pin on L298N to pin 8 on ARDUINO

int ch1; // value of chanel 1 of the receiver
int ch2; // value of chanel 2 of the receiver
int ch3; // value of chanel 3 of the receiver
int ch4; // value of chanel 4 of the receiver

int sp1;
int sp2; // PWM
int val1, val2, val3, val4;

void setup() {
  // put your setup code here, to run once:
  pinMode (rc1, INPUT);
  pinMode (rc2, INPUT);
  pinMode (rc3, INPUT);
  pinMode (rc4, INPUT);

  pinMode (sp1, OUTPUT);
  pinMode (sp2, OUTPUT);

  pinMode (left1, OUTPUT);
  pinMode (left2, OUTPUT);
  pinMode (right1, OUTPUT);
  pinMode (right2, OUTPUT);

  Serial.begin(9600); // for testing
}

void loop() {
  ch1 = pulseIn(rc1, HIGH);
  ch2 = pulseIn(rc2, HIGH);
  ch3 = pulseIn(rc3, HIGH);
  ch4 = pulseIn(rc4, HIGH);

  Serial.print("\t");
  Serial.print(ch1);
  Serial.print("\t");
  Serial.print(ch2);
  Serial.print("\t");
  Serial.println(ch3);
  delay(500);

  // val1 = map(ch1, 1027, 1949, 0, 255); // X-axis
  // val2 = map(ch2, 1003, 1981, 0, 255); // Y-axis
  val3 = map(ch3, 990, 1984, 0, 255); //Speed
  // val4 = map(ch4, 994, 1970, 0, 255);

  if (ch2 < 1400)
    moveForward(val3);
  if (ch1 < 1400)
    arcLeft(val3);
  if (ch1 > 1500)
    arcRight(val3);
  if (ch2 > 1500)
    moveBackward(val3);
  if (ch4 < 1400)
    spotLeft(val3);
  if (ch4 > 1500)
    spotRight(val3);
  else
    Stop();
}
//1485 ch1 1949-right
//1496 ch2
//1494 ch4

void moveForward(int val3)
{
  Serial.println("FORWARD");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  delay(50);
}
void arcLeft(int val3)
{
  Serial.println("Arc LEFT");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  delay(50);
}
void arcRight(int val3)
{
  Serial.println("Arc RIGHT");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
  delay(50);
}

void moveBackward(int val3)
{
  Serial.println("BACKWARD");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, LOW);
  digitalWrite(left2, HIGH);
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);
  delay(50);
}

void spotRight(int val3)
{
  Serial.println("Spot RIGHT");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);
  delay(50);
}

void spotLeft(int val3)
{
  Serial.println("Spot LEFT");
  analogWrite(spdLeft, val3);
  analogWrite(spdRight, val3);
  digitalWrite(left1, LOW);
  digitalWrite(left2, HIGH);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  delay(50);
}
void Stop()
{
  Serial.println("STOP");
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
  delay(50);
}

