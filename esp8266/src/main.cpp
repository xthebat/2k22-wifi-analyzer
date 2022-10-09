#include <Arduino.h>
#include <Periph.h>
#include <WIFI.h>

#define LED 2

WIFI *wifi;
Representer *repr;
UART *uart;

void setup() {
    wifi = new WIFI;
    repr = new CSVRepresenter;
    uart = UARTObject::Instance(115200);

    pinMode(LED, OUTPUT);
}

void loop() {
    if (wifi && repr && uart) {
        digitalWrite(LED, LOW);

        wifi->scan();
        auto representation = repr->convert(wifi->data());

        TextStream stream;
        UartStream uart_stream;
        WIFINetworkInfoCSVWriter writer;
        for (auto &it : wifi->data()) {
            writer.write(it, uart_stream);
        }
        auto text = stream.get_text();

        uart_stream.flush();


        if (representation) {
            uart->println(representation->repr());
        }
        // uart->scanDecorate(wifi->getRepr, repr);

        digitalWrite(LED, HIGH);

        delay(1000);
    }
}