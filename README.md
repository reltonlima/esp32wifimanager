📝 ESP32 Smart Connect: WiFi Manager & Visual Feedback
Este projeto demonstra a implementação profissional de gerenciamento de redes Wi-Fi em dispositivos ESP32 WROOM, eliminando a necessidade de credenciais estáticas (hardcoded) no código-fonte. O firmware transforma o ESP32 em uma solução dinâmica e amigável para o usuário final, utilizando a biblioteca WiFiManager.

🚀 Funcionalidades Integradas
Captive Portal Automático: Caso nenhuma rede conhecida seja encontrada, o ESP32 cria um Access Point (AP) próprio para configuração via navegador.

Factory Reset via Hardware: Implementação de reset de fábrica utilizando o botão físico (BOOT/GPIO 0), permitindo a troca de redes sem necessidade de novo upload de código.

Heartbeat Visual (Status do LED):

Conectado: Duas piscadas rápidas (flash) a cada 5 segundos (Economia de energia + sinal de "estou vivo").

Desconectado: Piscada longa (1s On / 1s Off) estilo "Blink" clássico para alerta visual imediato.

Modo Configuração: Strobo rápido para indicar que o portal está aberto.

Non-Blocking Logic: Utilização de millis() para controle de tempo, garantindo que o LED não trave o processamento das tarefas principais.

🛠️ Por que utilizar o WiFiManager?
Em um cenário de IoT (Internet of Things) real, o desenvolvedor não tem acesso à rede do cliente final. O uso desta biblioteca é fundamental por três motivos principais:

Segurança: Evita expor senhas de Wi-Fi em repositórios públicos (GitHub).

Portabilidade: O dispositivo pode ser levado para qualquer ambiente e configurado por uma pessoa leiga através do smartphone.

Experiência do Usuário (UX): Transforma um protótipo técnico em um produto comercializável, com interface de configuração intuitiva.

📋 Pré-requisitos e Bibliotecas
Para compilar este projeto, você precisará da Arduino IDE 2.0+ ou PlatformIO e das seguintes dependências:

WiFiManager by tzapu (Instalar via Library Manager)

Bibliotecas Nativas do Core ESP32 (WiFi, WebServer, DNSServer).

💻 Como utilizar
Clone este repositório.

Abra na sua IDE de preferência.

Selecione a placa ESP32 Dev Module.

Suba o firmware para o seu módulo.

Ao ligar, procure a rede Wi-Fi "ESP32_PROFESSOR" no seu celular e configure a sua rede local.

🤝 Contribuições
Este é um projeto com fins didáticos e práticos. Sinta-se à vontade para:

Abrir Issues com dúvidas ou sugestões de melhoria.

Enviar um Pull Request com novas funcionalidades (como integração com MQTT ou telas OLED).

Dar uma ⭐️ no repositório se este código te ajudou!