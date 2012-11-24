/*
  G35: An Arduino library for GE Color Effects G-35 holiday lights.
  Copyright © 2011 The G35 Authors. Use, modification, and distribution are
  subject to the BSD license as described in the accompanying LICENSE file.
*/

#include <G35String.h>

#define LIGHT_COUNT (50)
#define G35_PIN (13)

G35String lights(G35_PIN, LIGHT_COUNT);

char messageBuffer[12];
int index = 0;

void setup() {
  lights.enumerate();
  lights.do_test_patterns();
  
  Serial.begin(115200);
  Serial.println('starting up');
}

void loop() {
  while(Serial.available() > 0) {
    char x = Serial.read();
    if (x == '!') index = 0;      // start
    else if (x == '.') process(); // end
    else messageBuffer[index++] = x;
  }

}

void process() {
  Serial.println(messageBuffer);
  
  int cmdid = atoi(messageBuffer);
  
  switch(cmdid) {
    case 0:  lights.do_test_patterns();                                              break;
    case 1:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_RED);       break;
    case 2:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN);     break;
    case 3:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLUE);      break;
    case 4:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_CYAN);      break;
    case 5:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_MAGENTA);   break;
    case 6:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_YELLOW);    break;
    case 7:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_PURPLE);    break;
    case 8:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_ORANGE);    break;
    case 9:  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_WHITE);     break;
    default:                            break;
  }
  
  memset(messageBuffer, 0, sizeof(messageBuffer));
}


