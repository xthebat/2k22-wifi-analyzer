#include <Arduino.h>
#include <Periph.h>
#include <WIFI.h>

#define LED 2

WIFIController *wifi;
Representer *repr;
UART *uart;

void setup() {
    wifi = new WIFIController(new WIFI);
    repr = new CSVRepresenter;
    uart = UARTObject::Instance(115200);

    pinMode(LED, OUTPUT);
}

void loop() {
    if (wifi && repr && uart) {
        digitalWrite(LED, LOW);
        auto representation = wifi->getRepr(repr);

        if (representation) {
            uart->println(representation->repr());
        }
        // uart->scanDecorate(wifi->getRepr, repr);

        digitalWrite(LED, HIGH);

        delay(1000);
    }
}