#include "dallas.h"

#define APP_CORE 1
#define PRO_CORE 0
//check
//check

OneWire oneWire(ONE_WIRE_BUS); //ok
DallasTemperature sensors(&oneWire);//ok
TaskHandle_t TaskHandle_temperatura;//tarea
QueueHandle_t msg_queue;//nombre de la cola
const uint8_t msg_queue_len=5;//tamaño de la cola
float item;
float tempC;
 void dallas_task(void *parameter){
       while(1) {
        sensors.begin(); 
        Serial.print(" Requesting temperatures..."); 
        sensors.requestTemperatures(); // Send the command to get temperature readings 
        Serial.println("DONE"); 
        /********************************************************************/
        Serial.print("Temperature is: "); 
        tempC = sensors.getTempCByIndex(0);
        Serial.println(tempC);
        //if (xQueueSend(msg_queue, (void *)&tempC, 0) !=pdTRUE){
        //    Serial.println("Queue full");
        }
        //Serial.print(tempC); 
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
    
    void dallas_launch(void){
        msg_queue=xQueueCreate(msg_queue_len, sizeof(float));
        xTaskCreatePinnedToCore( // Use xTaskCreate() in vanilla FreeRTOS
        dallas_task, // Function to be called
        "dallas_task", // Name of task
        20000, // Stack size (bytes in ESP32, words in FreeRTOS)
        NULL, // Parameter to pass
        1, // Task priority
        &TaskHandle_temperatura, // Task handle
        APP_CORE); // Run on one core for demo purposes (ESP32 only)
        }
        void dallas_kill(void){
        if (TaskHandle_temperatura != NULL)
        {
        vTaskDelete(TaskHandle_temperatura);
        TaskHandle_temperatura = NULL;
        }
        }


