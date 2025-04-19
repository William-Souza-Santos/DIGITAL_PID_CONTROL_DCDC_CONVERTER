#include <Arduino_FreeRTOS.h>

void LED_Blink(void *pvParameters);
void LED_Blink_9(void *pvParameters);

void setup() {
  xTaskCreate(LED_Blink_13, "Blink13", 128, NULL, 2, NULL);
  xTaskCreate(LED_Blink_9, "Blink9", 128, NULL, 2, NULL);
  
  vTaskStartScheduler();
}

void loop() {
  // Not used
}

void LED_Blink_13(void *pvParameters) {
  pinMode(13, OUTPUT);

  while(true) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void LED_Blink_9(void *pvParameters) {
  pinMode(9, OUTPUT);

  while(true) {
    digitalWrite(9, HIGH);
    vTaskDelay(pdMS_TO_TICKS(500)); // Pisca mais rápido
    digitalWrite(9, LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
