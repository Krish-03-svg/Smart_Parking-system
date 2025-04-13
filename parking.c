// Smart Parking system Code 
#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
#define sensor1 8
#define sensor2 9
#define sensor3 10
#define sensor4 11
#define closegate 6
#define opengate 7

// Custom character for parking area is filled
byte park[8] = {
    0b10001,
    0b10001,
    0b01010,
    0b00100,
    0b01010,
    0b10001,
    0b10001,
};

// Custom character for parking area is empty
byte npark[8] = {
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b11111,
};
int pA1, pA2, pA3, pA4;

void setup()
{
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    pinMode(opengate, OUTPUT);
    pinMode(closegate, OUTPUT);
    lcd.createChar(0, park);
    lcd.createChar(1, npark);

    lcd.begin(16, 2);
    lcd.print("gate opening");
    digitalWrite(opengate, HIGH);
    digitalWrite(closegate, LOW);
    delay(1000);
    digitalWrite(opengate, LOW);
    digitalWrite(closegate, LOW);
    lcd.clear();
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("PA1 PA2 PA3 PA4");
    pA1 = digitalRead(sensor1);
    pA2 = digitalRead(sensor2);
    pA3 = digitalRead(sensor3);
    pA4 = digitalRead(sensor4);

    // For parking area 1
    lcd.setCursor(0, 1);
    if (pA1 == 1)
        lcd.write(byte(1));
    else
        lcd.write(byte(0));

    // For parking area 2
    lcd.setCursor(5, 1);
    if (pA2 == 1)
        lcd.write(byte(1));
    else
        lcd.write(byte(0));

    // For parking area 3
    lcd.setCursor(9, 1);
    if (pA3 == 1)
        lcd.write(byte(1));
    else
        lcd.write(byte(0));

    // For parking area 4
    lcd.setCursor(13, 1);
    if (pA4 == 1)
        lcd.write(byte(1));
    else
        lcd.write(byte(0));

    if (pA1 == 0 && pA2 == 0 && pA3 == 0 && pA4 == 0)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("gate closing");
        digitalWrite(closegate, HIGH);
        digitalWrite(opengate, LOW);
        delay(1000);
        digitalWrite(closegate, LOW);
        digitalWrite(opengate, LOW);
        lcd.setCursor(0, 1);
        lcd.print("OCCUPIED");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No Occupancy");
    }
}
