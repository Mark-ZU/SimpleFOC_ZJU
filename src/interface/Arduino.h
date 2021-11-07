#ifndef __ARDUINO_H__
#define __ARDUINO_H__
#include <string>
#include <cmath>
#include <WString.h>
#include <Print.h>
#include <Stream.h>
template<typename T>
T min(T a,T b){
    return std::min(a,b);
}

// Arduino.h
#ifdef __cplusplus
extern "C"{
#endif
#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define CHANGE 1
#define FALLING 2
#define RISING 3
#define digitalPinToInterrupt(p) (p)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#define round(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x) * (x))

    typedef unsigned int word;

    typedef bool boolean;
    typedef uint8_t byte;
    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, uint8_t val);
    int digitalRead(uint8_t pin);
    int analogRead(uint8_t pin);
    void analogReference(uint8_t mode);
    void analogWrite(uint8_t pin, int val);

    unsigned long millis(void);
    unsigned long micros(void);
    void delay(unsigned long ms);
    void delayMicroseconds(unsigned int us);
    unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
    unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

    void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
    void detachInterrupt(uint8_t interruptNum);

#ifdef __cplusplus
} // extern "C"
#endif
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

//
bool isDigit(int c);
#endif // __ARDUINO_H__