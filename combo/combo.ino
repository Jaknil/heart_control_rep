// what pins did you hook up?
int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
int speed_steps = 0;
int set_speed =1;
int abs_position;

/*
   BYJ48 Stepper motor code
   Connect :
   IN1 >> D8
   IN2 >> D9
   IN3 >> D10
   IN4 >> D11
   VCC ... 5V Prefer to use external 5V Source
   Gnd
   written By :Mohannad Rawashdeh
  http://www.instructables.com/member/Mohannad+Rawashdeh/
     28/9/2013
  */

#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left=4095;
long time;
void setup()
{
  
    pinMode(xPin, INPUT); //lyssna
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); //starta på "1" HIGH eller hög, så att man märker när man klickar
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
Serial.begin(115200);
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
// delay(1000);

}
void loop()
{
  while(steps_left>0){
  currentMillis = micros();
  if(currentMillis-last_time>=1000){//was 1000 //Kollar om det gått minst 1000 microsec sen senaste step
              xPosition = analogRead(xPin);
             // yPosition = analogRead(yPin);
             Serial.println(xPosition);
        if ((xPosition<=520)||(xPosition>=530)){ //kör bara om joystick är aktiverad
          if(xPosition<=523) {  //Vänder riktning beroende på hur man vrider joystick
            Direction = true;
            abs_position = xPosition*0.05;
             } 
          else { 
            Direction = false;
            abs_position = (1023-xPosition)*0.05;
          }
     // if(xPosition<=530) Direction = false;
 /*         if(speed_steps>set_speed){
            delay(5);
             Serial.println(speed_steps);
            speed_steps=0;
            }
          speed_steps++;
          */
          
          //Speed control
              //Serial.print("Abs_X: ");
             // Serial.println(abs_position);
             // Serial.println(steps_left);
            delay(abs_position);
             Serial.println(abs_position);
          //End speed control
          
          
      
        //Kör stegmotorn ett steg i rätt riktning
        stepper(1); 
        time=time+micros()-last_time;
        last_time=micros();
        steps_left--;
        // kört stegmotor i rätt riktning
       }
      }
  }    
        steps_left=4095;
 
 }
 /* Serial.println(time);
  Serial.println(currentMillis);
   currentMillis = micros();
  Serial.println(currentMillis);
 Serial.println("Wait...!");
  delay(100);
 // Direction=!Direction;
  */
  
  

  
//joystick code
 /* xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

//set_speed = xPosition+1;
//set_speed=1;
 // delay(500); // add some delay between reads

  */


void stepper(int xw){
  for (int x=0;x<xw;x++){
switch(Steps){
   case 0:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   case 1:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
   break; 
   case 2:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 3:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 4:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 5:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
     case 6:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 7:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   default:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
}
SetDirection();
}
} 
void SetDirection(){
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }



}
