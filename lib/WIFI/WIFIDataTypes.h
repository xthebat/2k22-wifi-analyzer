#ifndef WIFIDATATYPES_H
#define WIFIDATATYPES_H

#include <WString.h>

#include <map>
#include <vector>

struct WIFIDataType {
    String ssid;
    uint8_t enc_type;
    int32_t rssi;
    uint8_t* bssid;
    int32_t channel;
    bool is_hidden;
};

enum class WIFIFieldsID {
    ID = 0,
    SSID,
    ENC_TYPE,
    RSSI,
    BSSID,
    CHANNEL,
    IS_HIDDEN,
};

const std::map<WIFIFieldsID, String> WIFIHeaders = {
    {WIFIFieldsID::ID, "id"},
    {WIFIFieldsID::SSID, "ssid"},
    {WIFIFieldsID::ENC_TYPE, "enc_type"},
    {WIFIFieldsID::RSSI, "rssi"},
    {WIFIFieldsID::BSSID, "bssid"},
    {WIFIFieldsID::CHANNEL, "channel"},
    {WIFIFieldsID::IS_HIDDEN, "is_hidden"},
};

namespace WIFITypes {
using Data = std::vector<WIFIDataType*>;
}

#endif