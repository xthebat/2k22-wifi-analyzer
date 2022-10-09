#ifndef WIFINETWORKINFO_H
#define WIFINETWORKINFO_H

#include <WString.h>

#include <cstdint>

#include <map>
#include <vector>
#include <memory>

#include "WIFIDataTypes.h"

struct WIFINetworkInfo {
    String ssid {};
    WIFIEncryptionType enc_type {};
    int32_t rssi = 0;
    uint8_t* bssid = nullptr;
    int32_t channel = 0;
    bool is_hidden = false;
};

typedef std::shared_ptr<WIFINetworkInfo> WIFINetworkInfoPtr;

typedef std::vector<WIFINetworkInfoPtr> WIFINetworkInfoVector;

#endif