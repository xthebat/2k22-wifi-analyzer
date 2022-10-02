#ifndef PERIPH_H
#define PERIPH_H

#include <HardwareSerial.h>

class Periph {};

class UART : public Periph {
   public:
    explicit UART(uint32_t baud_rate);

   public:
    // TODO
    template <typename Func, typename... Args>
    void scanDecorate(Func func, Args... args);

   public:
    void print(const String& str) const;
    void println(const String& str) const;
    void swap(void) const;

   private:
    uint32_t _baud_rate;
};

class UARTObject {
   public:
    static UART* Instance(uint32_t baud_rate);

   protected:
    UARTObject();

   private:
    static UART* _instance;
};

// TODO
class GPIO : public Periph {
   public:
    GPIO(uint8_t pin_number, uint8_t mode);

   public:
    void pinToggle(void) const;

   public:
    void pinDigitalWrite(uint8_t pin, uint8_t val) const;
    int pinDigitalRead(uint8_t pin) const;

    // TODO
    int pinAnalogRead(uint8_t pin) const;
    void pinAnalogReference(uint8_t mode) const;
    void pinAnalogWrite(uint8_t pin, int val) const;
    void pinAnalogWriteMode(uint8_t pin, int val, bool openDrain) const;
    void pinAnalogWriteFreq(uint32_t freq) const;
    void pinAnalogWriteResolution(int res) const;
    void pinAnalogWriteRange(uint32_t range) const;

   private:
    uint8_t _pin_number;
    uint8_t _mode;
};

#endif