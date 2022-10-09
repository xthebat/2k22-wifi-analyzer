#ifndef REPRESENTER_H
#define REPRESENTER_H

// #include "WIFI.h"
#include <WIFINetworkInfo.h>
#include <WString.h>
#include <iostream>


class Stream {
public:
    virtual int32_t write(uint8_t byte) = 0;
};


class TextStream : public Stream {
private:
    std::string *text;
public:
    TextStream() {

    }

    int32_t write(uint8_t byte) override {

    }
};


class UartStream : public Stream {
private:
//    UartHandler *_uart;
public:
//    UartStream(UartHandler *uart) : _uart(uart) {
//
//    }

    int32_t write(uint8_t byte) override {

    }
};


template <typename T> class Writer {
public:
    virtual int32_t write(const T &data, Stream &stream) = 0;
};

class WIFINetworkInfoCSVWriter : public Writer<WIFINetworkInfoPtr> {
public:
    int32_t write(const WIFINetworkInfoPtr &data, Stream &stream) override {

    }
};

#endif