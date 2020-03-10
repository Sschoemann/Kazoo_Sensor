
const int kazooPin = A0; // Define the analog input pin to measure the kazoo bend sensor 
const int piezoPin = 9; // Define the output pin for the piezo buzzer



void setup() {
  // Use the serial monitor window to help debug our sketch:
  Serial.begin(9600);

// initialize the piezoPin as an output:
  pinMode(piezoPin, OUTPUT);

}

void loop() {

  int kazooBend = analogRead(A0); // stores the sensor value from the analog pin.

  Serial.print("Kazoo: "); //Prints the word "Kazoo" and a colon
  Serial.print(kazooBend); //Prints the vale of the kazoo sensor

  
  int piezoPitch =  // Output value that controls the piezo.
  map(kazooBend,0,1023,4000,0); //maps the sensor values to the frequency range of the arduino
  tone(9,piezoPitch,20);
  delay(10);

  
  Serial.print(" Piezo: "); //Prints the word "Piezo" and a colon
  Serial.println(piezoPitch); //Prints the frequency the piezo is playing

}
