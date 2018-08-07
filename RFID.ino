#include <SPI.h>
#include <RFID.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

SoftwareSerial mySerial(18, 19);

int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;
int Buzzer = 8;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  lcd.begin(16, 2);
  mySerial.begin(9600);
  pinMode(Buzzer, OUTPUT);

}


void loop()
{

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your tags");
  digitalWrite(Buzzer, LOW);


  if (rfid.isCard()) 
  {
    if (rfid.readCardSerial()) 
    {
       {
          serNum0 = rfid.serNum[0];
          serNum1 = rfid.serNum[1];
          serNum2 = rfid.serNum[2];
          serNum3 = rfid.serNum[3];
          serNum4 = rfid.serNum[4];
       
        /* With a new cardnumber, show it in Serial Monitor. */

        Serial.println(" ");
        Serial.println("Card found");
        serNum0 = rfid.serNum[0];
        serNum1 = rfid.serNum[1];
        serNum2 = rfid.serNum[2];
        serNum3 = rfid.serNum[3];
        serNum4 = rfid.serNum[4];

        //Serial.println(" ");
        Serial.println("Cardnumber:");
        Serial.print("Dec: ");
        Serial.print(rfid.serNum[0], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[1], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[2], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[3], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[4], DEC);
        Serial.println(" ");

        Serial.print("Hex: ");
        Serial.print(rfid.serNum[0], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[1], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[2], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[3], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[4], HEX);
        Serial.println(" ");






      }

    }
  }
  rfid.halt();
  delay(1500);
}
