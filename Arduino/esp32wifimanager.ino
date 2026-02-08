#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>

#define BOTAO_RESET 0 
#define LED_INTERNO 2 

WiFiManager wm;

// Variáveis para controle de tempo (sem travar o loop)
unsigned long tempoAnterior = 0;
const long intervaloConectado = 5000; // 5 segundos

void setup() {
  Serial.begin(115200);
  pinMode(BOTAO_RESET, INPUT_PULLUP);
  pinMode(LED_INTERNO, OUTPUT);

  // Callback para quando o portal estiver aberto (Modo Configuração)
  wm.setAPCallback(configModeCallback);

  // Reset manual segurando o botão BOOT
  if (digitalRead(BOTAO_RESET) == LOW) {
    delay(3000);
    if (digitalRead(BOTAO_RESET) == LOW) {
      Serial.println("CONFIGURACOES RESETADAS!");
      wm.resetSettings();
    }
  }

  Serial.println("Tentando conectar...");
  if (!wm.autoConnect("ESP32_PROFESSOR", "12345678")) {
    Serial.println("Falha na conexao. Reiniciando...");
    delay(3000);
    ESP.restart();
  }

  Serial.println("CONECTADO COM SUCESSO!");
}

void loop() {
  unsigned long tempoAtual = millis();

  if (WiFi.status() == WL_CONNECTED) {
    // --- ESTADO: CONECTADO ---
    // Pisca 2 vezes a cada 5 segundos (Heartbeat)
    if (tempoAtual - tempoAnterior >= intervaloConectado) {
      tempoAnterior = tempoAtual;
      feedbackConectado();
    }
  } else {
    // --- ESTADO: DESCONECTADO ---
    // Piscada longa (Estilo Blink clássico lento)
    feedbackDesconectado();
  }

  // O código dos alunos vem aqui sem ser travado pelos LEDs
}

// --- FUNÇÕES DE FEEDBACK VISUAL ---

void feedbackConectado() {
  Serial.println("Status: Conectado (Heartbeat)");
  // Duas piscadas rápidas
  digitalWrite(LED_INTERNO, HIGH); delay(100);
  digitalWrite(LED_INTERNO, LOW);  delay(100);
  digitalWrite(LED_INTERNO, HIGH); delay(100);
  digitalWrite(LED_INTERNO, LOW);
}

void feedbackDesconectado() {
  Serial.println("Status: Sem Conexão (Blink Longo)");
  // Piscada longa de 1 segundo (estilo alerta)
  digitalWrite(LED_INTERNO, HIGH);
  delay(1000);
  digitalWrite(LED_INTERNO, LOW);
  delay(1000);
}

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Modo Configuração Ativo!");
  // Enquanto o aluno estiver no portal, o LED pisca rápido para avisar
  for(int i=0; i<10; i++) {
    digitalWrite(LED_INTERNO, HIGH); delay(50);
    digitalWrite(LED_INTERNO, LOW);  delay(50);
  }
}