#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#include <PS2Keyboard.h>

// Keyboard pins
const int DataPin = 3;
const int IRQpin =  2;

PS2Keyboard keyboard;

// ARDUINO NANO 
// #define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328, can use other pins
// MOSI (DI) => 11
// MISO (DO) => 12
// CLK       => 13
// CS        => 10
TMRpcm tmrpcm;   // create an object for use in this sketch

long previous=0;


void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  } else
    Serial.println("SD OK");    
  
  tmrpcm.play("inicio.wav"); //the sound file "inicio" will play each time the arduino powers up, or is reset

  previous=millis();

  tmrpcm.volume(0);
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else if (c == 'j') {
      Serial.print(c);
      tmrpcm.play("prin.wav"); //the sound file "prin" will play each time the 'c' button is pressed
    } else if (c == 'f') {
      Serial.print(c);
      tmrpcm.play("pred_sup.wav"); //the sound file "pred_sup" will play each time the 'q' button is pressed
    } else if (c == 'd') {
      Serial.print(c);
      tmrpcm.play("admin.wav"); //the sound file "admin" will play each time the 'c' button is pressed 
    } else if (c == 's') {
      Serial.print(c);
      tmrpcm.play("refei.wav"); //the sound file "refei" will play each time the 'c' button is pressed 
    } else if (c == 'a') {
      Serial.print(c);
      tmrpcm.play("portaria.wav"); //the sound file "portaria" will play each time the 'c' button is pressed 
    } else if (c == 'u') {
      Serial.print(c);
      tmrpcm.play("ginasio.wav"); //the sound file "ginasio" will play each time the 'c' button is pressed 
    } else if (c == 'r') {
      Serial.print(c);
      tmrpcm.play("sest.wav"); //the sound file "sest" will play each time the 'c' button is pressed 
    } else if (c == 'e') {
      Serial.print(c);
      tmrpcm.play("prefei.wav"); //the sound file "prefei" will play each time the 'c' button is pressed 
    } else if (c == 'w') {
      Serial.print(c);
      tmrpcm.play("semaforo.wav"); //the sound file "semaforo" will play each time the 'c' button is pressed 
    } else if (c == 'q') {
      Serial.print(c);
      tmrpcm.play("rampa.wav"); //the sound file "rampa" will play each time the 'c' button is pressed 
    } else if (c == 'm') {
      Serial.print(c);
      tmrpcm.play("luz.wav"); //the sound file "luz" will play each time the 'c' button is pressed 
    } else if (c == 'v') {
      Serial.print(c);
      tmrpcm.play("rampa_a.wav"); //the sound file "rampa_a" will play each time the 'c' button is pressed 
    } else if (c == 'c') {
      Serial.print(c);
      tmrpcm.play("castro.wav"); //the sound file "castro" will play each time the 'c' button is pressed 
    } else if (c == 'x') {
      Serial.print(c);
      tmrpcm.play("noel.wav"); //the sound file "noel" will play each time the 'c' button is pressed 
    } else if (c == 'z') {
      Serial.print(c);
      tmrpcm.play("Parana.wav"); //the sound file "Parana" will play each time the 'c' button is pressed 
    } else if (c == 'h') {
      Serial.print(c);
      tmrpcm.play("guape.wav"); //the sound file "guape" will play each time the 'c' button is pressed 
    } else if (c == 'g') {
      Serial.print(c);
      tmrpcm.play("alvares.wav"); //the sound file "alvares" will play each time the 'c' button is pressed 
    }else if (c == 'n') {
      Serial.print(c);
      tmrpcm.play("inicio.wav"); //the sound file "inicio" will play each time the arduino powers up, or the 'c' button is pressed 
    }  else {
      
      // otherwise, just print all normal characters
      Serial.print(c);
    }
  }
}
