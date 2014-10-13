/* LED Blink Example. Based on the blink example from:
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2008 PJRC.COM, LLC
 * Copyright (c) 2014 Jeremy Shaw
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "Arduino.h"
#include "avr_emulation.h"
#include <util/delay.h>

// Teensy 3.1 has the LED on pin 13
const int ledPin = 13;
#define LED_ON    digitalWrite(ledPin, HIGH)
#define LED_OFF   digitalWrite(ledPin, LOW)

#define DIT 80    /* unit time for morse code */

// lookup table for all 26 letters.  Upper 5 bits are the pulses
// to send (MSB first), and the lower 3 bits are the number of
// bits to send for this letter.
const unsigned char PROGMEM morse_code_table[] = {
    0xF8 + 5, // 0: ----- 1111 1101
    0x78 + 5, // 1: .---- 0111 1101
    0x38 + 5, // 2: ..--- 0011 1101
    0x18 + 5, // 3: ...-- 0001 1101
    0x08 + 5, // 4: ....- 0000 1101
    0x00 + 5, // 5: ..... 0000 0101
    0x80 + 5, // 6: _.... 1000 0101
    0xC0 + 5, // 7: --... 1100 0101
    0xE0 + 5, // 8: ---.. 1110 0101
    0xF0 + 5, // 9: ----. 1111 0101
    0x00, // :
    0x00, // ;
    0x00, // <
    0x00, // =
    0x00, // >
    0x00, // ?
    0x00, // @
    0x40 + 2, // A: .-
    0x80 + 4, // B: -...
    0xA0 + 4, // C: -.-.
    0x80 + 3, // D: -..
    0x00 + 1, // E: .
    0x20 + 4, // F: ..-.
    0xC0 + 3, // G: --.
    0x00 + 4, // H: ....
    0x00 + 2, // I: ..
    0x70 + 4, // J: .---
    0xA0 + 3, // K: -.-
    0x40 + 4, // L: .-..
    0xC0 + 2, // M: --
    0x80 + 2, // N: -.
    0xE0 + 3, // O: ---
    0x60 + 4, // P: .--.
    0xD0 + 4, // Q: --.-
    0x40 + 3, // R: .-.
    0x00 + 3, // S: ...
    0x80 + 1, // T: -
    0x20 + 3, // U: ..-
    0x10 + 4, // V: ...-
    0x60 + 3, // W: .--
    0x90 + 4, // X: -..-
    0xB0 + 4, // Y: -.--
    0xC0 + 4, // Z: --..
};

void print (char *s)
{
    return;
}

void pchar(char *c)
{
   return;
}

// blink a single character in Morse code
void morse_character(char c)
{
    unsigned char code, count;

    if (c == ' ') {
        print("Space\n");
        _delay_ms(DIT * 7);
        return;
    }
    if (c < '0' || c > 'Z') {
        print("Opps, unsupported character: ");
        pchar(c);
        print("\n");
        return; 
    } 
    print("Char ");
    pchar(c);
    pchar(':');
    code = pgm_read_byte(morse_code_table + (c - '0'));
    for (count = code & 0x07; count > 0; count--) {
        LED_ON;
        if (code & 0x80) {
            print(" dah");
            _delay_ms(DIT * 3);
        } else {
            print(" dit");
            _delay_ms(DIT);
        }
        LED_OFF;
        _delay_ms(DIT);
        code = code << 1;
    }
    print("\n");
    _delay_ms(DIT * 4);
}

// blink an entire message in Morse code
// the string must be in flash memory (using PSTR macro)
void morse_P(const char *s)
{
    char c;

    while (1) {
        c = *s++;
        if (!c) break;
        morse_character(c);
    }
    _delay_ms(DIT * 4);
    print("\n");
}


// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loopBlink() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second
}

void loop() {
  morse_P("ARDUINO");
//  loopBlink();
}
