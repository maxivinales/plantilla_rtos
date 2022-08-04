#ifndef _DALLAS_TASK_H_ 
#define _DALLAS_TASK_H_
#define ONE_WIRE_BUS 22
#include <Arduino.h>
#include <OneWire.h> //check
#include <DallasTemperature.h>
void dallas_launch(void);
void dallas_kill(void);

#endif 
