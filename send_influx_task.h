#ifndef _SEND_INFLUX_TASK_H_
#define _SEND_INFLUX_TASK_H_
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>
// InfluxDB v2 server url, e.g. https://eu-central-1-1.aws.cloud2.influxdata.com (Use: InfluxDB UI -> Load Data -> Client Libraries)
#define INFLUXDB_URL "https://influxdb.faniot.ar"
// InfluxDB v2 server or cloud API token (Use: InfluxDB UI -> Data -> API Tokens -> <select token>)
#define INFLUXDB_TOKEN "Kpil_e__xP6JxBls-HSUIFNPEi4tx1uR_vm4QEGE5acCHV5otc_lNZqj0fQqzYijk0Qc7X1pGIv0dPuNca-Qtg=="
// InfluxDB v2 organization id (Use: InfluxDB UI -> User -> About -> Common Ids )
#define INFLUXDB_ORG "FANIOT-ORG"
// InfluxDB v2 bucket name (Use: InfluxDB UI ->  Data -> Buckets)
#define INFLUXDB_BUCKET "Prueba_Enviando_Datos"
// Set timezone string according to https://www.gnu.org/software/libc/manual/html_node/TZ-Variable.html
// Examples:
//  Pacific Time: "PST8PDT"
//  Eastern: "EST5EDT"
//  Japanesse: "JST-9"
//  Central Europe: "CET-1CEST,M3.5.0,M10.5.0/3"
#define TZ_INFO "CET-1CEST,M3.5.0,M10.5.0/3"

void send_influx_launch();
void send_influx_kill();
//bool influx_flag;
#endif