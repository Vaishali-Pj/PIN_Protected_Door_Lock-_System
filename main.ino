#include <Keypad.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// #define DEBUG 1

Servo myServo;

// LCD object (check I2C address: usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  

const int buzzerPin = 4;  // Buzzer on GPIO 21

// Keypad setup
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {16, 17, 18, 19};
byte colPins[COLS] = {33, 32, 25, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";  
String input = "";

// Buzzer beep function
void beep(int duration) {
  digitalWrite(buzzerPin, HIGH);
  delay(duration);
  digitalWrite(buzzerPin, LOW);
}

void setup() {
  #ifdef DEBUG
  Serial.begin(115200);
  #endif

  pinMode(buzzerPin, OUTPUT);

  // Servo
  myServo.attach(15);
  myServo.write(0); // Locked

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello!!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter PIN:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    #ifdef DEBUG
    Serial.print(key);
    #endif

    beep(100); // Short beep on keypress

    if (key == '#') { // Submit PIN
      lcd.clear();
      if (input == password) {
        #ifdef DEBUG
        Serial.println(" -> Access Granted");
        #endif
        lcd.setCursor(0,0);
        lcd.print(" Access Granted ");
        beep(500);
        myServo.write(90);   // Unlock
        delay(5000);
        myServo.write(0);    // Lock again
      } else {
        #ifdef DEBUG
        Serial.println(" -> Wrong Password");
        #endif
        lcd.setCursor(0,0);
        lcd.print(" Access Denied  ");
        for(int i=0; i<3; i++) {
          beep(150);
          delay(150);
        }
      }
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter PIN:");
      input = "";
    }
    else if (key == '*') { // Clear
      input = "";
      #ifdef DEBUG
      Serial.println(" -> Cleared");
      #endif
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter PIN:");
      beep(200);
    }
    else {
      input += key;
      lcd.setCursor(0,1);
      lcd.print(input); // Show entered digits
    }
  }
}
