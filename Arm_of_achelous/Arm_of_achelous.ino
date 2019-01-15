#include <SoftwareSerial.h>
#define RxD 11 // Pin that the Bluetooth (BT_TX) will transmit to the Arduino (RxD)
#define TxD 12

const int lPWM = 6 ;
const int rPWM = 9;
const int lM1 = 2, lM2 = 3;
const int rM1 = 7, rM2 = 8;
SoftwareSerial blueToothSerial(RxD, TxD);

void setup()
{
  Serial.begin(9600); // Allow Serial communication via USB cable to computer (if required)
  pinMode(RxD, INPUT); // Set pin to receive INPUT from bluetooth shield on Digital Pin 6
  pinMode(TxD, OUTPUT); // Set pin to send data (OUTPUT) to bluetooth shield on Digital Pin 7
  pinMode(lM1, OUTPUT);
  pinMode(lM2, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(rM2, OUTPUT);
  pinMode(rPWM, OUTPUT);
  pinMode(lPWM, OUTPUT);

  setupBlueToothConnection(); //Used to initialise the Bluetooth shield
}


void loop()
{
  if (blueToothSerial.available())
  { //check for data sent from the remote bluetooth shield
    char recvChar = blueToothSerial.read();
    Serial.println(recvChar);
    switch (recvChar)
    {
      case 'F' : moveForward();
        break;
      case 'B': moveBackward();
        break;
      case 'I' : arcRight();
        break;
      case 'R' : spotfastRight();
        break;
      case 'G' : arcLeft();
        break;
      case 'L' : spotfastLeft();
        break;
            case 'H' : arcBackLeft();
        break;
              case 'J' : arcBackRight();
        break;
      case 'S' : Stop();
        break;

    }

  }
}



void setupBlueToothConnection()
{
  blueToothSerial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  blueToothSerial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  blueToothSerial.print("\r\n+STNA=SeeedBTSlave\r\n"); //set bluetooth name as "SeeedBTSlave"
  blueToothSerial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  blueToothSerial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
  delay(2000); // This delay is required.
  blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
  blueToothSerial.flush();
}

void moveForward()
{
  Serial.println("MOVEFASTFORWARD");
  analogWrite(lPWM, 255);
  analogWrite(rPWM, 255);
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}


void moveBackward()
{
  Serial.println("BACKWARD");
  analogWrite(lPWM, 255);
  analogWrite(rPWM, 255);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}

void arcRight()
{
  Serial.println("MOVERIGHT");
  analogWrite(lPWM, 200);
  analogWrite(rPWM, 200);
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}

void arcLeft()
{
  Serial.println("MOVELEFT");
  analogWrite(lPWM, 200);
  analogWrite(rPWM, 200);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}

void arcBackRight()
{
  Serial.println("MOVERIGHT");
  analogWrite(lPWM, 200);
  analogWrite(rPWM, 200);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}

void arcBackLeft()
{
  Serial.println("MOVELEFT");
  analogWrite(lPWM, 200);
  analogWrite(rPWM, 200);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}

void Stop()
{
  Serial.println("STOP");
  analogWrite(lPWM, 0);
  analogWrite(rPWM, 0);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, LOW);
}



void spotfastRight()
{
  Serial.println("MOVEFASTRIGHT");
  analogWrite(lPWM, 255);
  analogWrite(rPWM, 255);
  digitalWrite(lM1, HIGH);
  digitalWrite(lM2, LOW);
  digitalWrite(rM1, LOW);
  digitalWrite(rM2, HIGH);
}

void spotfastLeft()
{
  Serial.println("MOVEFASTLEFT");
  analogWrite(lPWM, 255);
  analogWrite(rPWM, 255);
  digitalWrite(lM1, LOW);
  digitalWrite(lM2, HIGH);
  digitalWrite(rM1, HIGH);
  digitalWrite(rM2, LOW);
}












