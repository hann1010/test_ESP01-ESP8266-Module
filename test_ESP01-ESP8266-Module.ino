/* test_ESP01-ESP8266-Module en Hanna P 2025
For Arduino Mega 2560 board */
/********************************************/

// Serial Event

String inputString = "";      // a String to hold incoming data
String inputString1 = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
bool stringComplete1 = false;  // whether the string is complete


void setup() {
  // initialize serials:
  Serial.begin(9600);
  Serial1.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  inputString1.reserve(200);
  Serial.println("Setup... Done");
  // Test
  //Serial1.println("AT");
  //Serial1.println("AT+CWMODE?");
}


void loop() {
  // print the string when a newline arrives:
  if (stringComplete1) {
    Serial.println(inputString1);
    // clear the string:
    inputString1 = "";
    stringComplete1 = false;
  }
  if (stringComplete) {
    Serial1.println(inputString);
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  //delay(1000);
}


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/

void serialEvent() {
  while (Serial1.available() > 0) {
    // get the new byte:
    char inChar = (char)Serial1.read();
    // add it to the inputString:
    inputString1 += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete1 = true;
      Serial.println("Serial1 read... Done");      
    }
  }
  while (Serial.available() > 0) {
    // get the new byte:
    //Serial1.write(Serial.read());
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      Serial.println("Serial read... Done");      
    }
  }
}
