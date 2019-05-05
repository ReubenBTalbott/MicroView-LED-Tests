#include <MicroView.h>
void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(A2, INPUT);
    uView.begin();

}

void loop(){
    Serial.println(analogRead(A2));
    delay(25);
    uView.clear(PAGE);
    uView.setFontType(0);
    uView.setCursor(0,0);
    uView.print("Brightness");
    uView.setCursor(0,8);
    uView.print(analogRead(A2)*100L/1023);
    uView.print("%");
    uView.setCursor(0,16);
    uView.print("of"); 
    uView.setCursor(0,24);
    uView.print("100%");
    uView.display();
    analogWrite(3, analogRead(A2)/4);
}