#include "WIFI.h"

#include "WIFIDataTypes.h"

WIFI::WIFI() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void WIFI::scan(void) {
    int8_t scan_count = WiFi.scanNetworks(false,  // async
                                          true    // show_hidden
    );

    if (scan_count <= 0) {
        return;
    }

    _data.resize(scan_count);
    for (int8_t i = 0; i < scan_count; ++i) {
        auto data = new WIFIDataType;
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

void WIFI::flushData(void) {}

const WIFITypes::Data& WIFI::data() const { return _data; }

WIFIController::WIFIController(WIFI* wifi) : _wifi(wifi ? wifi : new WIFI) {}

WIFIRepresentation* WIFIController::getRepr(Representer* repr) {
    _wifi->scan();
    return repr->convert(_wifi->data());
}