#ifndef WIFIDATATYPES_H
#define WIFIDATATYPES_H

#include <WString.h>

#include <cstdint>

#include <map>
#include <vector>

enum class WIFIEncryptionType {

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

#endif