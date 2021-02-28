#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);


#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define MIN_PULSE  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define MAX_PULSE  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define default0  445 //+ вперед - назад
#define default1  260 //+ вперед - назад
#define default2  330 //+ вверх  - вниз

#define default3  90 //+ назад  - вперед
#define default4  350 //+ назад  - вперед
#define default5  220 //+ вверх  - вниз

#define default6  390 //+ вперед - назад
#define default7  225 //+ вперед - назад
#define default8  150 //- вверх  + вниз

#define default9  130 //+ назад  - вперед
#define default10 370 //+ назад  - вперед
#define default11 220 //+ вверх  - вниз

// our servo # counter
uint8_t servonum = 0;

// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ
void stand_stationary()
{
    pwm.setPWM(0, 0, default0-100);//передняя правая
    pwm.setPWM(1, 0, default1+100);
    pwm.setPWM(2, 0, default2);

    pwm.setPWM(3, 0, default3+100);//передняя левая
    pwm.setPWM(4, 0, default4-100);
    pwm.setPWM(5, 0, default5);

    pwm.setPWM(6, 0, default6-100);//задняя правая
    pwm.setPWM(7, 0, default7+100);
    pwm.setPWM(8, 0, default8);

    pwm.setPWM(9, 0, default9+100);//задняя левая
    pwm.setPWM(10, 0, default10-100);
    pwm.setPWM(11, 0, default11);
    //----------------------------------------------
}

// МЕТОД ВСТАВАНИЯ ИЗ ПОЛОЖЕНИЯ СИДЯ
void stand_up_from_down() 
{
  for (int i = 0; i < 100; i++)
    {
      pwm.setPWM(0, 0, default0-i);//передняя правая
      pwm.setPWM(1, 0, default1+i);
      pwm.setPWM(2, 0, default2);
  
      pwm.setPWM(3, 0, default3+i);//передняя левая
      pwm.setPWM(4, 0, default4-i);
      pwm.setPWM(5, 0, default5);
  
      pwm.setPWM(6, 0, default6-i);//задняя правая
      pwm.setPWM(7, 0, default7+i);
      pwm.setPWM(8, 0, default8);
  
      pwm.setPWM(9, 0, default9+i);//задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(11, 0, default11);
      delay(10);
    }

   stand_stationary();
}



// ПОЛОЖЕНИЕ СИДЯ
void sit_stationary()
{
    pwm.setPWM(0, 0, default0+25); //передняя правая
    pwm.setPWM(1, 0, default1+30);
    pwm.setPWM(2, 0, default2);

    pwm.setPWM(3, 0, default3); //передняя левая
    pwm.setPWM(4, 0, default4);
    pwm.setPWM(5, 0, default5);

    pwm.setPWM(6, 0, default6);//задняя правая
    pwm.setPWM(7, 0, default7);
    pwm.setPWM(8, 0, default8);

    pwm.setPWM(9, 0, default9);//задняя левая
    pwm.setPWM(10, 0, default10);
    pwm.setPWM(11, 0, default11);
    
    //+++++++++++++++++++++++++++++++++++++++++++
}


// МЕТОД ПРИСЕДАНИЯ ИЗ СТАЦИОНАРНОГО ПОЛОЖЕНИЯ
void sit_down_from_stationary() 
{
  for (int i = 100; i > 0; i--)
    {
      pwm.setPWM(0, 0, default0-i);//передняя правая
      pwm.setPWM(1, 0, default1+i);
      pwm.setPWM(2, 0, default2);
  
      pwm.setPWM(3, 0, default3+i);//передняя левая
      pwm.setPWM(4, 0, default4-i);
      pwm.setPWM(5, 0, default5);
  
      pwm.setPWM(6, 0, default6-i);//задняя правая
      pwm.setPWM(7, 0, default7+i);
      pwm.setPWM(8, 0, default8);
  
      pwm.setPWM(9, 0, default9+i);//задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(11, 0, default11);
      delay(10);
    }
  
    //sit_stationary();
}


// НАКЛОН ВПРАВО
void tilt_right()
{
  for (int i = 0; i < 40; i++)
    {
      pwm.setPWM(2, 0, default2+i); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      
      pwm.setPWM(5, 0, default5+i); // Передняя левая
      pwm.setPWM(3, 0, default3+i);
      
      pwm.setPWM(8, 0, default8-i/2); // Задняя правая
      pwm.setPWM(7, 0, default7+i);  
      
      pwm.setPWM(11, 0, default11-i); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(9, 0, default9+i);
      
      delay(10);
    }
    tilt_right_stationary();
}

void tilt_right_stationary()
{
      pwm.setPWM(2, 0, default2+40); // Передняя правая
      pwm.setPWM(1, 0, default1+40);
      
      pwm.setPWM(5, 0, default5+40); // Передняя левая
      pwm.setPWM(3, 0, default3+40);
      
      pwm.setPWM(8, 0, default8-20); // Задняя правая
      pwm.setPWM(7, 0, default7+40);  
      
      pwm.setPWM(11, 0, default11-40); // Задняя левая
      pwm.setPWM(10, 0, default10-40);
      pwm.setPWM(9, 0, default9+40);
}

// ВОЗВРАЩЕНИЕ ИЗ НАКЛОНА ВПРАВО
void sit_stationary_from_tilt_right()
{
  for (int i = 40; i > 0; i--)
    {
      pwm.setPWM(2, 0, default2+i); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      
      pwm.setPWM(5, 0, default5+i); // Передняя левая
      pwm.setPWM(3, 0, default3+i);
      
      pwm.setPWM(8, 0, default8-i/2); // Задняя правя
      pwm.setPWM(7, 0, default7+i);  
      
      pwm.setPWM(11, 0, default11-i); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(9, 0, default9+i); 
      
      delay(10);
    }
  sit_stationary();
}

// НАКЛОН ВЛЕВО
void tilt_left()
{
  for (int i = 0; i < 40; i++)
    {
      pwm.setPWM(0, 0, default0-i); // Передняя правая
      pwm.setPWM(2, 0, default2-i); 
      
      pwm.setPWM(4, 0, default4-i); // Передняя левая
      pwm.setPWM(5, 0, default5-i); 
      
      pwm.setPWM(6, 0, default6-i); // Задняя правая
      pwm.setPWM(7, 0, default7+i); 
      pwm.setPWM(8, 0, default8+i); 
      
      pwm.setPWM(10, 0, default10-i); // Задняя левая
      pwm.setPWM(11, 0, default11+i);
      delay(10);
    }
    tilt_left_stationary();
}

// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ НАКЛОНА ВЛЕВО
void tilt_left_stationary()
{
      pwm.setPWM(0, 0, default0-40); // Передняя правая
      pwm.setPWM(2, 0, default2-40); 
      
      pwm.setPWM(4, 0, default4-40); // Передняя левая
      pwm.setPWM(5, 0, default5-40); 
      
      pwm.setPWM(6, 0, default6-40); // Задняя правая
      pwm.setPWM(7, 0, default7+40); 
      pwm.setPWM(8, 0, default8+40); 
      
      pwm.setPWM(10, 0, default10-40); // Задняя левая
      pwm.setPWM(11, 0, default11+40);
}

// ВОЗВРАЩЕНИЕ ИЗ НАКЛОНА ВЛЕВО
void sit_stationary_from_tilt_left()
{
  for (int i = 40; i > 0; i--)
    {
      pwm.setPWM(0, 0, default0-i); // Передняя правая
      pwm.setPWM(2, 0, default2-i); 
      
      pwm.setPWM(4, 0, default4-i); // Передняя левая
      pwm.setPWM(5, 0, default5-i); 
      
      pwm.setPWM(6, 0, default6-i); // Задняя правая
      pwm.setPWM(7, 0, default7+i); 
      pwm.setPWM(8, 0, default8+i); 
      
      pwm.setPWM(10, 0, default10-i); // Задняя левая
      pwm.setPWM(11, 0, default11+i);
      delay(10);
    }
  sit_stationary();
}


void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  yield();
  delay(10);

    sit_stationary();
    delay(2000);
    stand_up_from_down();
    delay(3000);
    
    
}

void loop() {
  // Drive each servo one at a time using setPWM()
  Serial.println(servonum);
  Serial.println("start");
    stand_up_from_down();
    delay(2000);
    sit_down_from_stationary();
    delay(2000);
    tilt_right();
    delay(3000);
    sit_stationary_from_tilt_right();
    delay(3000);
    tilt_left();
    delay(3000);
    sit_stationary_from_tilt_left();
    delay(3000);
    stand_up_from_down();
    delay(2000);
    sit_down_from_stationary();
    sit_stationary();
    delay(2000);

   // встаем
   //stand_up();
   //delay(2000);

   // садимся
   //sit_down();
   //delay(2000);
    
}
