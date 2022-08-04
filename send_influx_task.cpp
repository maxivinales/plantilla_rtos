#include "send_influx_task.h"
//#include "wifi.h"
#include "dallas.h"
#define APP_CORE 1
#define PRO_CORE 0
 TaskHandle_t TaskHandle_influx;
extern  TaskHandle_t TaskHandle_temperatura;
extern  QueueHandle_t msg_queue;//nombre de la cola
extern float item;
extern float tempC;

//static QueueHandle_t msg_queue;


//******************************************************////
InfluxDBClient *client;
Point *sensor;
//*******************************************************////
void send_influx_task(void *parameter)
{
client = new InfluxDBClient(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert); // lanzo influx
sensor = new Point("Heladera");                //inicializo mi objeto y reservo memoria para el mismo
while (1){
sensor->clearFields();

float prueba=5.5;
if (xQueueReceive(msg_queue, (void *)&item, 0) == pdTRUE){
  sensor->addField("temperatura", item);/*<<<<<<----------Poner aqui el dato de Dallas**********************************************************/

//Serial.println(item);
}
vTaskDelay(1000/portTICK_PERIOD_MS);

  Serial.print("Writing: ");
  Serial.println(sensor->toLineProtocol());

//  if (wifiMulti.run() != WL_CONNECTED) {
//  Serial.println("Wifi connection lost");
//  }

 if (!client->writePoint(*sensor)) {
    Serial.print("InfluxDB write failed: ");
    Serial.println(client->getLastErrorMessage());
  }
vTaskDelay(pdMS_TO_TICKS(100));

}
}
void send_influx_launch(){
xTaskCreatePinnedToCore( // Use xTaskCreate() in vanilla FreeRTOS
send_influx_task, // Function to be called
"send_influx_task", // Name of task
20000, // Stack size (bytes in ESP32, words in FreeRTOS)
NULL, // Parameter to pass
1, // Task priority
&TaskHandle_influx, // Task handle
PRO_CORE); // Run on one core for demo purposes (ESP32 only)
}
        
        
void influx_kill(void){
if (TaskHandle_influx != NULL){
vTaskDelete(TaskHandle_influx);
TaskHandle_influx = NULL;
}
}

