#include "send_influx_task.h"
#include "dallas.h"
void wifi_launch();

void setup() {
    Serial.begin(115200);
wifi_launch();
dallas_launch();
send_influx_launch();
}
void loop() {
}
