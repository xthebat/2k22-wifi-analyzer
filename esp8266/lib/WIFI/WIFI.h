#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>
#include <Representer.h>

#include "WIFIDataTypes.h"

class WIFI {
   public:
    WIFI();

   public:
    void scan();

    // TODO
    void flushData();

   public:
    const WIFITypes::Data& data() const;

   private:
    WIFITypes::Data _data;
};

class WIFIController {
   public:
    explicit WIFIController(WIFI* wifi = 0);

   public:
    WIFIRepresentation* getRepr(Representer* repr);

   private:
    WIFI* _wifi;
};

#endif