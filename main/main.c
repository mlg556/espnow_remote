// neopixelc3 MAC: 84:f7:03:a1:12:30
// xiao MAC: 34:85:18:03:44:b4

#include <stdio.h>

#include "esp_log.h"
#include "esp_mac.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "espnow.h"
#include "espnow_storage.h"
#include "espnow_utils.h"

static const char *tag = "espnow_test";

static void app_wifi_init() {
    esp_event_loop_create_default();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_NONE));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void app_main(void) {
    espnow_storage_init();

    app_wifi_init();

    uint8_t mac[6] = {0};

    esp_read_mac(mac, ESP_MAC_WIFI_STA);

    while (1) {
        ESP_LOGI(tag, "mac addr: " MACSTR "", MAC2STR(mac));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    // espnow_config_t espnow_config = ESPNOW_INIT_CONFIG_DEFAULT();
    // espnow_init(&espnow_config);
}