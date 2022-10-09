#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>
#include <Representer.h>

#include "WIFIDataTypes.h"
#include "WIFINetworkInfo.h"

class WIFI {
public:
    WIFI();

public:
    void scan();

    // TODO
    void flushData();

public:
    const WIFINetworkInfoVector &data() const;

private:
    WIFINetworkInfoVector _data;
};

#endif