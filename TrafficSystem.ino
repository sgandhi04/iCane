#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double distance;
MeLEDMatrix ledMtx_3(3);
unsigned char drawBuffer[16];
unsigned char *drawTemp;
Me7SegmentDisplay seg7_1(1);
MeRGBLed rgbled_2(2, 2==7?2:4);
MeUltrasonicSensor ultrasonic_4(4);
MeBuzzer buzzer;
MeIR ir;

void setup(){
    ledMtx_3.setColorIndex(1);
    ledMtx_3.setBrightness(6);
    ir.begin();
drawTemp = new unsigned char[16]{241,145,145,159,0,128,255,128,0,255,129,255,0,255,144,240};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_3.drawBitmap(0,0,16,drawBuffer);
    seg7_1.display((float)0);
    rgbled_2.setColor(0,0,255,0);
    rgbled_2.show();
}

void loop(){
    distance = ultrasonic_4.distanceCm();
    if((distance) < (105)){
        buzzer.tone(330, 500);
        delay(20);
    drawTemp = new unsigned char[16]{241,145,145,159,0,128,255,128,0,255,129,255,0,255,144,240};
        memcpy(drawBuffer,drawTemp,16);
        free(drawTemp);
        ledMtx_3.drawBitmap(0,0,16,drawBuffer);
        seg7_1.display((float)0);
        if(ir.keyPressed(12)){
        drawTemp = new unsigned char[16]{255,129,137,137,143,0,255,129,129,129,255,0,0,0,0,0};
            memcpy(drawBuffer,drawTemp,16);
            free(drawTemp);
            ledMtx_3.drawBitmap(0,0,16,drawBuffer);
        }else{
            while(!(ir.keyPressed(12)))
            {
                _loop();
            }
        drawTemp = new unsigned char[16]{255,129,137,137,143,0,255,129,129,129,255,0,0,0,0,0};
            memcpy(drawBuffer,drawTemp,16);
            free(drawTemp);
            ledMtx_3.drawBitmap(0,0,16,drawBuffer);
            rgbled_2.setColor(0,20,0,0);
            rgbled_2.show();
            seg7_1.display((float)20);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)19);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)18);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)17);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)16);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)15);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)14);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)13);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)12);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)11);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)10);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)9);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)8);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)7);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)6);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)5);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)4);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)3);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)2);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)1);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
            seg7_1.display((float)0);
            buzzer.tone(262, 500);
            delay(20);
            _delay(0.3);
        drawTemp = new unsigned char[16]{241,145,145,159,0,128,255,128,0,255,129,255,0,255,144,240};
            memcpy(drawBuffer,drawTemp,16);
            free(drawTemp);
            ledMtx_3.drawBitmap(0,0,16,drawBuffer);
            rgbled_2.setColor(0,0,150,0);
            rgbled_2.show();
        }
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir.loop();
}
