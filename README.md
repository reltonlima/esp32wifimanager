📝 ESP32 Smart Connect: WiFi Manager & Visual Feedback
<br/>Este projeto demonstra a _implementação profissional_ de gerenciamento de redes Wi-Fi em dispositivos __ESP32 WROOM__, eliminando a necessidade de credenciais estáticas (hardcoded) no código-fonte. O firmware transforma o ESP32 em uma solução dinâmica e amigável para o usuário final, utilizando a biblioteca _WiFiManager_.

🚀 **Funcionalidades Integradas**
<br>Captive Portal Automático: Caso nenhuma rede conhecida seja encontrada, o ESP32 cria um **Access Point (AP)** próprio para configuração via navegador.

**Factory Reset via Hardware:**
<br>Implementação de reset de fábrica utilizando o botão físico (BOOT/GPIO 0), permitindo a troca de redes sem necessidade de novo upload de código.

**Heartbeat Visual (Status do LED):**

**Conectado:** 
<br>Duas piscadas rápidas (flash) a cada 5 segundos (Economia de energia + sinal de "estou vivo").

**Desconectado:** 
<br>Piscada longa (1s On / 1s Off) estilo "Blink" clássico para alerta visual imediato.

**Modo Configuração:**
<br>Strobo rápido para indicar que o portal está aberto.

**Non-Blocking Logic:**
<br>Utilização de millis() para controle de tempo, garantindo que o LED não trave o processamento das tarefas principais.

🛠️ **Por que utilizar o WiFiManager?**
<br>Em um cenário de IoT (Internet of Things) real, o desenvolvedor não tem acesso à rede do cliente final. O uso desta biblioteca é fundamental por três motivos principais:

**Segurança:** 
<br>Evita expor senhas de Wi-Fi em repositórios públicos (GitHub).

**Portabilidade:**
<br>O dispositivo pode ser levado para qualquer ambiente e configurado por uma pessoa leiga através do smartphone.

**Experiência do Usuário (UX):**
<br>Transforma um protótipo técnico em um produto comercializável, com interface de configuração intuitiva.

📋 **Pré-requisitos e Bibliotecas**
<br>Para compilar este projeto, você precisará da Arduino IDE 2.0+ ou PlatformIO e das seguintes dependências:

__WiFiManager by tzapu__ (Instalar via Library Manager)

Bibliotecas Nativas do Core ESP32 (WiFi, WebServer, DNSServer).

💻 **Como utilizar**
<br>Clone este repositório.

Abra na sua IDE de preferência.

Selecione a placa ESP32 Dev Module.

Suba o firmware para o seu módulo.

Ao ligar, procure a rede Wi-Fi **"ESP32_PROFESSOR"** no seu celular e configure a sua rede local.

🤝 **Contribuições**
Este é um projeto com fins didáticos e práticos. Sinta-se à vontade para:

Abrir Issues com dúvidas ou sugestões de melhoria.

Enviar um Pull Request com novas funcionalidades __(como integração com MQTT ou telas OLED)__.

Dar uma ⭐️ no repositório se este código te ajudou!
