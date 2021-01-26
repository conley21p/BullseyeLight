//Made by Conley Price 4,4,2020

//Distance pins
const int trigPin = 9;
const int echoPin = 10;


//LIGHT pins
//define pins for the red, green and blue LEDs
int redRGB = 6;
int greenRGB = 5;
int blueRGB = 11;
//overall brightness value
int brightness = 255;
//individual brightness values for the red, green and blue LEDs
int gBright = 0; 
int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;

float duration, distance;


void setup() {

  pinMode(greenRGB, OUTPUT);
  pinMode(redRGB, OUTPUT);
  pinMode(blueRGB, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void TurnOn(){
    for (int i=0;i<256; i++){
      analogWrite(redRGB, rBright);
      rBright +=1;
      delay(fadeSpeed);
    }
    for (int i=0;i<256; i++){
      analogWrite(blueRGB, bBright);
      bBright += 1;
      delay(fadeSpeed);
    }  

    for (int i=0;i<256; i++){
      
      analogWrite(greenRGB, gBright);
      gBright +=1;
      delay(fadeSpeed);
    }  
}

//Turns off the led strip
void TurnOff(){
    for (int i=0;i<256; i++){
          analogWrite(greenRGB, brightness);
          analogWrite(redRGB, brightness);
          analogWrite(blueRGB, brightness);
    
      
      brightness -= 1;
 
      delay(fadeSpeed);

    }
}

//Method makes the led strip blink red
void blinkRed(){
  int count =0;
  while(count < 10  ){
    analogWrite(redRGB, 255);
    delay(110);
    analogWrite(redRGB, 0);
    count++;
  }
  
}


//Main loop that reads if there is a bullseye
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance >20 && distance < 30){
   blinkRed();
  }
    
  delay(100);
}
