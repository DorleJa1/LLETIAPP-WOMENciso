PRESENTACIÓN: https://canva.link/9nse01dv6ml337p
ARTICULO CIENTIFICO: https://repository.uaeh.edu.mx/revistas/index.php/investigium/article/view/14640/14434

# 💧 LLETI-App — Monitoreo y control inteligente del nivel de agua

## 📌 Descripción

**LLETI-App** es un prototipo de Internet de las Cosas (IoT) desarrollado para **medir, monitorear y controlar el nivel de agua** en un tanque de almacenamiento.

El sistema utiliza un **sensor ultrasónico**, un **ESP8266**, una pantalla LCD, LEDs y un relevador para controlar una bomba de agua. Además, utiliza **Blynk** para visualizar el nivel y controlar el sistema de forma remota.

El proyecto está basado en el estudio de un prototipo de monitoreo y control automático de llenado de sistemas de almacenamiento de agua.
[Artículo de referencia](https://repository.uaeh.edu.mx/revistas/index.php/investigium/article/view/14640/14434)

---

## 🎯 Objetivo

Desarrollar una solución sencilla y de bajo costo que permita:

* Medir el nivel de agua.
* Mostrar el nivel localmente.
* Enviar información mediante Wi-Fi.
* Consultar el nivel de agua desde una aplicación.
* Controlar una bomba de agua.
* Evitar desbordamientos y desperdicio de agua.

La propuesta busca transformar un sistema tradicional de almacenamiento en una infraestructura **conectada, inteligente y segura**.

---

## 🛠️ Tecnologías utilizadas

* ESP8266
* Arduino / C++
* Sensor ultrasónico
* LCD I2C 16x2
* LEDs indicadores
* Relevador
* Bomba de agua
* Wi-Fi
* Blynk
* IoT

El prototipo utiliza hardware accesible y permite una futura evolución hacia análisis de datos, inteligencia artificial y alertas inteligentes.

---

## ⚙️ ¿Cómo funciona?

1. El sensor ultrasónico mide la distancia entre el sensor y el agua.
2. El ESP8266 procesa la medición.
3. El sistema clasifica el nivel como:

   * 🟢 Lleno
   * 🟢 Alto
   * 🟡 Medio
   * 🟠 Bajo
   * 🔴 Muy bajo
4. El nivel se muestra en la pantalla LCD.
5. Los LEDs indican visualmente el estado del tanque.
6. El ESP8266 envía los datos mediante Wi-Fi a **Blynk**.
7. Desde Blynk se puede consultar el nivel y activar o apagar la bomba mediante un relevador.

El prototipo demuestra la capacidad de **medir, clasificar, mostrar, enviar información remotamente y controlar la bomba**.

---

## 🔐 Ciberseguridad

Al conectar el sistema a Internet, el tanque forma parte de una infraestructura IoT. Por esta razón, el proyecto contempla aspectos de seguridad como:

* Protección de credenciales.
* Control de acceso.
* Autenticación.
* Protección de comunicaciones.
* Principio de mínimo privilegio.
* Detección de comportamientos anormales.

La propuesta toma como referencia el **NIST Cybersecurity Framework 2.0**, considerando las funciones:

**Identify → Protect → Detect → Respond → Recover**.

---

## 🧠 Futuras mejoras

El prototipo puede evolucionar mediante el análisis de los datos históricos para:

* Detectar anomalías.
* Identificar patrones de consumo.
* Detectar posibles fugas.
* Predecir niveles de agua.
* Generar alertas inteligentes.
* Anticipar cuándo será necesario llenar el tanque.

La visión es que el sistema no solamente **mida**, sino que también pueda **aprender, detectar y proteger**.

---

## 📂 Contenido del repositorio

```text
LLETI-App/
│
├── LLETI-App.ino
├── README.md
└── docs/
    └── articulo-proyecto.pdf
```

---

## 🔧 Configuración

Antes de cargar el programa al ESP8266, configura tus datos de conexión:

```cpp
char auth[] = "TU_BLYNK_AUTH_TOKEN";
char ssid[] = "TU_WIFI";
char pass[] = "TU_PASSWORD";
```

**No publiques tus credenciales reales de Wi-Fi ni tu token de Blynk en GitHub.**

---

## 👩‍💻 Autora

**Dorle Jasive Miroslava Orduña López**

Proyecto de tecnologías de la información, IoT y ciberseguridad.

---

## 📚 Referencia

Orduña López, D. J. M., & Lara Almaraz, R.
*Estudio preliminar de prototipo de monitoreo y control de llenado automático de sistema de almacenamiento de agua para unidades habitacionales con el empleo de Internet de las Cosas.*

[Repositorio UAEH – Artículo](https://repository.uaeh.edu.mx/revistas/index.php/investigium/article/view/14640/14434)

---

## 💧 Visión del proyecto

> **No se trata solamente de medir el agua, sino de utilizar la tecnología para administrarla de manera inteligente, eficiente y segura.**

