#include "Periph.h"

#include <Arduino.h>

UART::UART(uint32_t baud_rate) : _baud_rate(baud_rate) {
    Serial.begin(baud_rate);
    Serial.swap();
    Serial.flush();
}

template <typename Func, typename... Args>
void UART::scanDecorate(Func func, Args... args) {
    println("Scanning networks...");
    func(args...);
    println("Scan complete...\n");
}

void UART::print(const String& str) const { Serial.print(str); }

void UART::println(const String& str) const { Serial.println(str); }

void UART::swap(void) const { Serial.swap(); }

UART* UARTObject::_instance = 0;

UART* UARTObject::Instance(uint32_t baud_rate) {
    if (_instance == 0) {
        _instance = new UART(baud_rate);
    }

    return _instance;
}

GPIO::GPIO(uint8_t pin_number, uint8_t mode)
    : _pin_number(pin_number), _mode(mode) {
    pinMode(pin_number, mode);
}

void GPIO::pinToggle(void) const {
    digitalWrite(_pin_number, LOW);
    digitalWrite(_pin_number, HIGH);
}

void GPIO::pinDigitalWrite(uint8_t pin, uint8_t val) const {
    digitalWrite(pin, val);
}

int GPIO::pinDigitalRead(uint8_t pin) const { return digitalRead(pin); }

int GPIO::pinAnalogRead(uint8_t pin) const { return 0; }

void GPIO::pinAnalogReference(uint8_t mode) const {}

void GPIO::pinAnalogWrite(uint8_t pin, int val) const {}

void GPIO::pinAnalogWriteMode(uint8_t pin, int val, bool openDrain) const {}

void GPIO::pinAnalogWriteFreq(uint32_t freq) const {}

void GPIO::pinAnalogWriteResolution(int res) const {}

void GPIO::pinAnalogWriteRange(uint32_t range) const {}