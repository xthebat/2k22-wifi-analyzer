#ifndef REPRESENTER_H
#define REPRESENTER_H

// #include "WIFI.h"
#include <WIFIDataTypes.h>
#include <WString.h>

struct WIFIRepresentation {
    virtual String& repr(void) = 0;
};

class CSVWIFIRepresentation : public WIFIRepresentation {
   public:
    String& repr(void) override;

   private:
    String _repr;
};

class PrintWIFIRepresentation : public WIFIRepresentation {
   public:
    String& repr(void) override;

   private:
    String _repr;
};

class Representer {
   public:
    virtual WIFIRepresentation* convert(const WIFITypes::Data& wifi) = 0;
};

class CSVRepresenter : public Representer {
   public:
    CSVRepresenter();

   public:
    WIFIRepresentation* convert(const WIFITypes::Data& wifi) override;

   private:
    CSVWIFIRepresentation* repr;
};

class PrintRepresenter : public Representer {
   public:
    PrintRepresenter();

   public:
    WIFIRepresentation* convert(const WIFITypes::Data& wifi) override;

   public:
    PrintWIFIRepresentation* repr;
};

#endif