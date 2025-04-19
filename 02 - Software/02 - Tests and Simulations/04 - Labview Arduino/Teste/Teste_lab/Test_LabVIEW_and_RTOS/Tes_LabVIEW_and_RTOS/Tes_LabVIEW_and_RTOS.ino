#include <Arduino_FreeRTOS.h>

void LED_Blink_13(void *pvParameters);
void LED_Blink_9(void *pvParameters);
void LabviewTask(void *pvParameters);

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial antes do scheduler

  xTaskCreate(LED_Blink_13, "Blink13", 128, NULL, 2, NULL);
  xTaskCreate(LED_Blink_9, "Blink9", 128, NULL, 2, NULL);
  xTaskCreate(LabviewTask, "LabviewTask", 512, NULL, 1, NULL);
  
  vTaskStartScheduler();
}

void loop() {
  // Não utilizado
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

void LabviewTask(void *pvParameters) {
  while(true) {
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.println(voltage);
    vTaskDelay(pdMS_TO_TICKS(100));  // Espera 500ms antes da próxima leitura
  }
}
