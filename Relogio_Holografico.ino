#include <WiFi.h>
#include <WebServer.h>

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>


// Imagens a serrem apresentadas
int imagem1[][3] = {
{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{246,239,235},{223,205,208},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{251,246,240},{151,111,162},{104,51,146},{212,192,204},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{252,249,241},{158,119,165},{94,42,149},{102,52,151},{106,56,149},{213,196,208},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{254,251,243},{164,126,166},{89,37,150},{164,114,130},{214,146,92},{111,58,145},{106,56,151},{216,199,211},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{253,251,245},{170,133,167},{90,37,150},{158,106,131},{251,209,118},{254,193,114},{215,135,79},{112,60,147},{109,59,151},{217,201,214},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,254,247},{182,147,168},{89,36,150},{154,102,133},{250,204,110},{255,243,214},{254,252,251},{253,194,124},{213,140,90},{102,52,153},{110,61,151},{230,217,218},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{254,245,230},{208,136,94},{161,108,128},{248,201,112},{255,242,209},{255,255,255},{255,255,255},{254,250,240},{167,114,136},{94,43,154},{154,101,125},{246,221,172},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{252,244,232},{246,157,64},{252,187,81},{254,225,162},{255,255,255},{255,255,255},{255,253,247},{170,136,175},{90,39,154},{152,101,133},{250,203,109},{255,244,215},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{252,243,233},{244,155,66},{249,183,81},{253,225,167},{255,255,255},{255,253,249},{174,141,176},{91,38,149},{148,97,134},{248,201,108},{255,242,208},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{252,243,233},{244,155,66},{249,183,81},{253,226,167},{255,254,251},{180,149,179},{92,38,149},{140,90,140},{249,203,109},{255,241,204},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{252,243,232},{244,153,62},{249,183,80},{253,226,166},{254,247,235},{199,129,97},{103,52,151},{122,70,142},{227,202,180},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{254,251,247},{246,180,113},{249,183,82},{253,239,204},{254,251,249},{251,183,104},{199,124,89},{103,52,149},{192,151,148},{255,255,248},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{253,247,239},{251,232,201},{255,255,255},{255,255,255},{253,246,237},{247,166,80},{227,157,84},{248,206,124},{253,251,248},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{247,176,102},{234,154,67},{162,121,152},{249,248,251},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{253,225,189},{200,130,98},{189,169,212},{255,255,254},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{250,241,231},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{247,244,249},{248,245,250},{245,242,248},{229,221,236},{240,235,244},{252,251,253},{246,244,251},{228,220,235},{243,239,246},{247,244,249},{253,252,253},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{242,238,245},{197,178,214},{197,179,214},{201,185,218},{175,149,199},{200,182,216},{182,158,204},{203,186,219},{170,143,196},{209,194,221},{181,156,203},{204,188,219},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{239,234,244},{229,221,237},{216,203,228},{198,180,215},{185,163,206},{200,182,217},{184,161,205},{201,184,217},{186,164,206},{203,186,218},{177,152,201},{203,186,219},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,254,255},{254,254,255},{253,253,253},{247,244,249},{252,251,253},{247,244,249},{253,252,254},{247,244,249},{253,252,253},{250,248,251},{249,247,251},{252,252,253},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255}



// Porta do servidor web (pode ser alterada se necessário)
const int port = 80;





const char *ssid = "relogio";
const char *password = "holografico";

WebServer server(80);

int largura = 29;
int LED_COUNT = 36;

int LED_PIN = 15, sensor = 36;
int detect = 0, cont = 0;


int numSetores = 3*largura, estado = 1, j = 0, N_giro = 0;
unsigned long int tempoSensor = 0, tempo = 0, t_giro[5] = {0,0,0,0,0}, t_arco = 0, M_giro_antes = 0, M_giro_atual = 0;


int imagemIndex = 0;

// NeoPixel
uint8_t green = 0, red = 0, blue = 0;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
/*
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
*/


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(sensor, INPUT);

  strip.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();   // Turn OFF all pixels ASAP
  strip.setBrightness(255);

  
  Serial.begin(115200);


  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }


  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);
  server.on("/led/on", HTTP_GET, handleLedOn);
  server.on("/led/off", HTTP_GET, handleLedOff);
  server.on("/send", HTTP_POST, handleSend);
  server.begin();
}

void loop() {
  
if (analogRead(sensor) == 0) {
    detect += 1;

    if (detect == 1) {
      if (N_giro == 5){ N_giro = 0;}
      Serial.println("");
      Serial.println(";");
      Serial.println("detectou");
      t_giro[N_giro]  = micros() - tempoSensor;
      M_giro_atual = sqrt((t_giro[0]*t_giro[0] + t_giro[1]*t_giro[1] + t_giro[2]*t_giro[2] + t_giro[3]*t_giro[3] + t_giro[4]*t_giro[4])) / 5;
      M_giro_atual = filtro(M_giro_antes,M_giro_atual);
      M_giro_antes = M_giro_atual;
      t_arco = M_giro_atual / numSetores;
      N_giro += 1; 
      Serial.println(t_giro[N_giro]);
      Serial.println(t_arco);
      Serial.println(";");
      Serial.println("");
    } else if(detect == 2) {
      tempoSensor = micros();
      tempo = micros();
      server.handleClient();

    } 
  } else {
  detect = 0;
  }


  if (millis() >= (tempo + t_arco)) {
    tempo += t_arco;
    aux_tempo1 = millis();



  
}

 
unsigned long int filtro(unsigned long int y0,unsigned long int y1){
  unsigned long int y2 ;
  y2 = 0,9*y0 + 0,1*y1;
  return y2;
}
 

void handleRoot() {
  String page = "<html><body>";
  page += "<h1>Números:</h1>";
  // Exibir os 5 números
  for (int i = 0; i < 5; i++) {
    page += "<p>" + String(i+1) + ": " + String(t_giro[i]) + "</p>";
  }
  page += "<h2>Controlar LED:</h2>";
  page += "<a href='/led/on'>Ligar LED</a><br>";
  page += "<a href='/led/off'>Desligar LED</a><br>";
  page += "<h2>Enviar String:</h2>";
  page += "<form method='post' action='/send'>";
  page += "<input type='text' name='inputString'><br>";
  page += "<input type='submit' value='Enviar'>";
  page += "</form>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}

void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);
  server.send(200, "text/plain", "LED ligado");
}

void handleLedOff() {
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "LED desligado");
}

void parseStringToIntMatrix(String inputString, int imagem[1080][4]) {
  // Remova os caracteres '{' e '}' da string
  inputString.remove(0, 1);
  inputString.remove(inputString.length() - 1, 1);
  
  // Divida a string em tokens separados por vírgula
  int rowIndex = 0;
  int colIndex = 0;
  String token;
  while (inputString.length() > 0) {
    int commaIndex = inputString.indexOf(',');
    if (commaIndex != -1) {
      token = inputString.substring(0, commaIndex);
      inputString.remove(0, commaIndex + 1);
    } else {
      token = inputString;
      inputString = "";
    }
    // Converter o token para int e atribuí-lo à matriz
    imagem[rowIndex][colIndex] = token.toInt();
    // Avançar para a próxima coluna
    colIndex++;
    // Se atingiu a última coluna, avançar para a próxima linha
    if (colIndex >= 4) {
      colIndex = 0;
      rowIndex++;
    }
  }
}

void handleSend() {
  if (server.hasArg("inputString")) {
    String inputString = server.arg("inputString");
    int imagem[1080][4]; // Matriz para armazenar os valores da imagem
    parseStringToIntMatrix(inputString, imagem);
    // Agora você pode usar a matriz 'imagem' conforme necessário
    Serial.println("Matriz imagem criada com sucesso.");
    server.send(200, "text/plain", "Matriz imagem criada com sucesso.");
  } else {
    server.send(400, "text/plain", "Requisição inválida");

  }
  
}


unsigned long int filtro(unsigned long int y0,unsigned long int y1){
  unsigned long int y2 ;
  y2 = 0,9*y0 + 0,1*y1;
  return y2;
}
