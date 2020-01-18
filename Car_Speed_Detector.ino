#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int Time;

int timer1=0, timer2=0, timer3=0; 

int flag = 0;

int ir_s1 = A0;
int ir_s2 = A1;

void setup(){
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    WELCOME To  ");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(2000);
  lcd.clear();
}

void loop() {
if(digitalRead (ir_s1) == LOW){flag=1;}

if(digitalRead (ir_s2) == LOW){flag=0;}

if(flag==1){timer1 = timer1+1;}
if(timer1>99){timer2 = timer2+1; timer1=0;}
if(timer2>59){timer3 = timer3+1; timer2=0;}

lcd.setCursor(0, 0); 
lcd.print("Time = ");

if(timer3<10){lcd.print("0");}
lcd.print(timer3);
lcd.print(":");
if(timer2<10){lcd.print("0");}
lcd.print(timer2);
lcd.print(":");
if(timer1<10){lcd.print("0");}
lcd.print(timer1);
 
lcd.setCursor(0, 1);   
if(flag==1){lcd.print("     Start    ");}
       else{lcd.print("      Stop    ");}
   
 
}
