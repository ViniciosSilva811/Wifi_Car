/* ------------------------------------------------------------------------------------ *\
|                                                                                        |
|                                                                                        |
|                                                                                        |
|                                                                                        |
|                                   Código do Receptor                                   |
|                                                                                        |
|                                                                                        |
|                                                                                        |
|                                                                                        |
\* ------------------------------------------------------------------------------------ */
// ------------------------------------------------------------------------------------ //

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ------------------------------------------------------------------------------------ //

void tratar_requisicoes();
void buscar_por_requisicoes();

// ------------------------------------------------------------------------------------ //

const char* ssid     = "Receptor";
const char* password = "b2de12a7_2kjda95fbdfa61Wr-";

// ------------------------------------------------------------------------------------ //

ESP8266WebServer servidor(80);

// --------------------------------------- SETUP -------------------------------------- //

void setup() {
	Serial.begin(115200);

	WiFi.mode(WIFI_AP);
	WiFi.softAP(ssid, password, 1, true);

	servidor.on("/", tratar_requisicoes);
	servidor.onNotFound(tratar_requisicoes);
	servidor.begin();

	Serial.println("Servidor Inicializado!");
	Serial.print("IP: ");
	Serial.println(WiFi.softAPIP());
}

// --------------------------------------- LOOP --------------------------------------- //

void loop() {
	buscar_por_requisicoes();
}

// ------------------------------------------------------------------------------------ //

void tratar_requisicoes() {
	if(servidor.hasArg("comando")){
		Serial.println(servidor.arg("comando"));
	}

	servidor.send(200, "text/html", "");
}

// ------------------------------------------------------------------------------------ //

void buscar_por_requisicoes() {
	servidor.handleClient();
}
// ------------------------------------------------------------------------------------ //
