#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeLineFollower linefollower_3(3);
MeDCMotor motor_10(10);

void setup(){
}

void loop(){
    if(((linefollower_3.readSensors())==(0))){
        motor_10.run(0);
    }else{
        motor_10.run(255);
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}

