#include "Representer.h"

String& CSVWIFIRepresentation::repr(void) { return _repr; }

String& PrintWIFIRepresentation::repr(void) { return _repr; }

CSVRepresenter::CSVRepresenter() {}

WIFIRepresentation* CSVRepresenter::convert(const WIFITypes::Data& wifi) {
    String object;
    CSVWIFIRepresentation* repr = new CSVWIFIRepresentation;

    repr->repr() = WIFIHeaders.at(WIFIFieldsID::ID) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::SSID) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::ENC_TYPE) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::RSSI) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::BSSID) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::CHANNEL) + ";" +
                   WIFIHeaders.at(WIFIFieldsID::IS_HIDDEN) + "\r\n";

    uint8_t idx = 0;
    for (const auto& it : wifi) {
        repr->repr() += String(idx) + ";" + it->ssid + ";" +
                        String(it->enc_type) + ";" + String(it->rssi) + ";" +
                        String(it->ssid) + ";" + String(it->channel) + ";" +
                        String(it->is_hidden) + "\r\n";
        idx++;
    }

    return repr;
}

PrintRepresenter::PrintRepresenter() {}

WIFIRepresentation* PrintRepresenter::convert(const WIFITypes::Data& wifi) {
    return nullptr;
}
