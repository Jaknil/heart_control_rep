/*
Two joysticks
Joy 2: 
vrx analog 2
vry analog 3
sw digital 7



*/




// what pins did you hook up to joy 1?
int xPin_joy1 = A1;
int yPin_joy1 = A0;
int buttonPin_joy1 = 2;

// what pins did you hook up to joy 2?
int xPin_joy2 = A2;
int yPin_joy2 = A3;
int buttonPin_joy2 = 7;

int xPosition_joy1 = 0;
int xPosition_joy2 = 0;
//int yPosition = 0;
int buttonState_joy1 = 0;
int buttonState_joy2 = 0;
int speed_steps = 0; //anvøænder vi denna?
int set_speed =1;//anvøænder vi denna?
int step_delay_joy1;
int step_delay_joy2;

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
// define pins you hooked the steppers to
#define IN1_1  8
#define IN1_2  9
#define IN1_3  10
#define IN1_4  11
#define IN2_1  3
#define IN2_2  4
#define IN2_3  5
#define IN2_4  6
int Steps_joy1 = 0;
int Steps_joy2 = 0;
boolean Direction_joy1 = true;
boolean Direction_joy2 = true;
unsigned long last_time_joy1;
unsigned long currentMillis;
unsigned long last_time_joy2;

void setup()
{
  //Set up joysticks
  
  //joy1
  pinMode(xPin_joy1, INPUT); //lyssna
  pinMode(yPin_joy2, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin_joy1, INPUT_PULLUP); //starta på "1" HIGH eller hög, så att man märker när man klickar
  
  
   //joy2
  pinMode(xPin_joy2, INPUT); //lyssna
  pinMode(yPin_joy2, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin_joy2, INPUT_PULLUP); //starta på "1" HIGH eller hög, så att man märker när man klickar

Serial.begin(115200);

//specify how we will use the pins
pinMode(IN1_1, OUTPUT); 
pinMode(IN1_2, OUTPUT); 
pinMode(IN1_3, OUTPUT); 
pinMode(IN1_4, OUTPUT); 
pinMode(IN2_1, OUTPUT); 
pinMode(IN2_2, OUTPUT); 
pinMode(IN2_3, OUTPUT); 
pinMode(IN2_4, OUTPUT); 


}
void loop()
{

currentMillis = micros(); // not enought time passed to use millis 

      
//Læs værdier från joys
xPosition_joy1 = analogRead(xPin_joy1);
xPosition_joy2 = analogRead(xPin_joy2);
                

              //Joy1
        if ((xPosition_joy1<=520)||(xPosition_joy1>=530)){ //kör bara om joystick är aktiverad
          if(xPosition_joy1<=523) {  //Vänder riktning beroende på hur man vrider joystick
            Direction_joy1 = true;
            step_delay_joy1 = xPosition_joy1*0.05;
             } 
          else { 
            Direction_joy1 = false;
            step_delay_joy1 = (1023-xPosition_joy1)*0.05; 
          }
         if (step_delay_joy1==0) {step_delay_joy1=1;}
        // Serial.print("Step_delay_joy1 ");
       // Serial.println(step_delay_joy1);
         // Serial.println((currentMillis-last_time_joy1)/1000);
       
          if((currentMillis-last_time_joy1)/1000>=step_delay_joy1){
          stepper1(1); //take one step with stepper 1
          last_time_joy1=micros();
        
          
          
          
          }
        }
        
          
          //joy2
       if ((xPosition_joy2<=520)||(xPosition_joy2>=530)){ //kör bara om joystick är aktiverad
          if(xPosition_joy2<=523) {  //Vänder riktning beroende på hur man vrider joystick
            Direction_joy2 = true;
            step_delay_joy2 = xPosition_joy2*0.05;
       
             } 
          else { 
            Direction_joy2 = false;
            step_delay_joy2 = (1023-xPosition_joy2)*0.05;
          }
           if (step_delay_joy2==0) {step_delay_joy2=1;}
          //  Serial.print("Step_delay_joy2 ");
       // Serial.println(step_delay_joy2);
         // Serial.println((currentMillis-last_time_joy2)/1000);
          
        if((currentMillis-last_time_joy2)/1000>=step_delay_joy2){
        stepper2(1); //take one step with stepper 1
         last_time_joy2=micros();
        }
       }
       /* Serial.print("currentMillis ");
        Serial.print(currentMillis);
        Serial.print("  last_time_joy1 ");
        Serial.print(last_time_joy1);
        Serial.print("  last_time_joy2 ");
        Serial.println(last_time_joy2);
*/
       
}
    

 

  
  

  

void stepper1(int xw){
  for (int x=0;x<xw;x++){
switch(Steps_joy1){
   case 0:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, HIGH);
   break; 
   case 1:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, HIGH);
     digitalWrite(IN1_4, HIGH);
   break; 
   case 2:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, HIGH);
     digitalWrite(IN1_4, LOW);
   break; 
   case 3:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, HIGH);
     digitalWrite(IN1_3, HIGH);
     digitalWrite(IN1_4, LOW);
   break; 
   case 4:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, HIGH);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, LOW);
   break; 
   case 5:
     digitalWrite(IN1_1, HIGH); 
     digitalWrite(IN1_2, HIGH);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, LOW);
   break; 
     case 6:
     digitalWrite(IN1_1, HIGH); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, LOW);
   break; 
   case 7:
     digitalWrite(IN1_1, HIGH); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, HIGH);
   break; 
   default:
     digitalWrite(IN1_1, LOW); 
     digitalWrite(IN1_2, LOW);
     digitalWrite(IN1_3, LOW);
     digitalWrite(IN1_4, LOW);
   break; 
}
//SetDirection();
if(Direction_joy1==1){ Steps_joy1++;}
if(Direction_joy1==0){ Steps_joy1--; }
if(Steps_joy1>7){Steps_joy1=0;}
if(Steps_joy1<0){Steps_joy1=7;}

}
} 
void stepper2(int xw){
  for (int x=0;x<xw;x++){
switch(Steps_joy2){
   case 0:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, HIGH);
   break; 
   case 1:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, HIGH);
     digitalWrite(IN2_4, HIGH);
   break; 
   case 2:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, HIGH);
     digitalWrite(IN2_4, LOW);
   break; 
   case 3:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, HIGH);
     digitalWrite(IN2_3, HIGH);
     digitalWrite(IN2_4, LOW);
   break; 
   case 4:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, HIGH);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, LOW);
   break; 
   case 5:
     digitalWrite(IN2_1, HIGH); 
     digitalWrite(IN2_2, HIGH);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, LOW);
   break; 
     case 6:
     digitalWrite(IN2_1, HIGH); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, LOW);
   break; 
   case 7:
     digitalWrite(IN2_1, HIGH); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, HIGH);
   break; 
   default:
     digitalWrite(IN2_1, LOW); 
     digitalWrite(IN2_2, LOW);
     digitalWrite(IN2_3, LOW);
     digitalWrite(IN2_4, LOW);
   break; 
}

if(Direction_joy2==1){ Steps_joy2++;}
if(Direction_joy2==0){ Steps_joy2--; }
if(Steps_joy2>7){Steps_joy2=0;}
if(Steps_joy2<0){Steps_joy2=7; }
}
}






