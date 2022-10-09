#include "WIFI.h"

#include "WIFIDataTypes.h"

WIFI::WIFI() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void WIFI::scan() {
    auto scan_count = WiFi.scanNetworks(/*async*/ false, /*show_hidden*/ true);

    if (scan_count <= 0) {
        return;
    }

    _data.resize(scan_count);
    for (int8_t i = 0; i < scan_count; ++i) {
        auto data = std::make_shared<WIFINetworkInfo>();
        WiFi.getNetworkInfo(i, data->ssid, data->enc_type, data->rssi,
                            data->bssid, data->channel, data->is_hidden);
        _data[i] = data;
    }

    // if (scan_count) {
    //     for (int i = 0; i < scan_count; ++i) {
    //         int32_t channel = WiFi.channel(i);
    //         int32_t rssi = WiFi.RSSI(i);
    //         Serial.print(WiFi.SSID(i) + ": ");
    //         Serial.print(channel);
    //         Serial.print(" ");
    //         Serial.println(rssi);
    //     }
    // }
}

void WIFI::flushData() {}

const WIFINetworkInfoVector& WIFI::data() const { return _data; }