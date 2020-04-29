const byte SP_PIN = 5;
#include <Keypad.h>

#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define WHOLE 1 //全分符
#define HALF 0.5 //半分符
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625
int tune[] = { NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4};


const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = 
{
{'0','4','8', 'C'}, 
{'1','5','9', 'D'},
{'2', '6', 'A', 'E'}, 
{'3', '7', 'B', 'F'}
};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {7, 8, 9, 10};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {11, 12, 13, 14};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );
void setup()
{
pinMode (SP_PIN,OUTPUT);
Serial.begin(9600);
}

void loop() 
{

char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY)
{
        int x=key-'0';
        tone(5, tune[x]);
      delay(500);  //改為固定的值(例如0.5 sec)
      noTone(5);
       
}

}
