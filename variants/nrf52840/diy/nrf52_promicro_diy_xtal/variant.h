#ifndef _VARIANT_PROMICRO_DIY_
#define _VARIANT_PROMICRO_DIY_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

// #define USE_LFXO // Board uses 32khz crystal for LF
#define USE_LFRC // Board uses RC for LF

#define PROMICRO_DIY_XTAL
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
NRF52 PRO MICRO PIN ASSIGNMENT

| Pin   | Function   |   | Pin     | Function     |
|-------|------------|---|---------|--------------|
| Gnd   |            |   | vbat    |              |
| P0.06 | Serial2 RX |   | vbat    |              |
| P0.08 | Serial2 TX |   | Gnd     |              |
| Gnd   |            |   | reset   |              |
| Gnd   |            |   | ext_vcc | *see 0.13    |
| P0.17 | Free pin   |   | P0.31   | BATTERY_PIN  |
| P0.20 | GPS_RX     |   | P0.29   | Free pin     |
| P0.22 | GPS_TX     |   | P0.02   | MISO         |
| P0.24 | GPS_EN     |   | P1.15   | MOSI         |
| P1.00 | BUTTON_PIN |   | P1.13   | CS           |
| P0.11 | SCL        |   | P1.11   | SCK          |
| P1.04 | SDA        |   | P0.10   | DIO0/IRQ     |
| P1.06 | Free pin   |   | P0.09   | RESET        |
|       |            |   |         |              |
|       | Mid board  |   |         | Internal     |
| P1.01 | Free pin   |   | 0.15    | LED          |
| P1.02 | Free pin   |   | 0.13    | 3V3_EN       |
| P1.07 | Free pin   |   |         |              |
*/

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

// Pin 13 enables 3.3V periphery. If the Lora module is on this pin, then it should stay enabled at all times.
#define PIN_3V3_EN (0 + 13) // P0.13

// Analog pins
#define BATTERY_PIN (0 + 31) // P0.31 Battery ADC
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
// Definition of milliVolt per LSB => 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096
#define VBAT_MV_PER_LSB (0.73242188F)
// Voltage divider value => 1.5M + 1M voltage divider on VBAT = (1.5M / (1M + 1.5M))
#define VBAT_DIVIDER (0.6F)
// Compensation factor for the VBAT divider
#define VBAT_DIVIDER_COMP (1.73)
// Fixed calculation of milliVolt from compensation value
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER VBAT_DIVIDER_COMP // REAL_VBAT_MV_PER_LSB
#define VBAT_RAW_TO_SCALED(x) (REAL_VBAT_MV_PER_LSB * x)

// WIRE IC AND IIC PINS
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (32 + 4) // P1.04
#define PIN_WIRE_SCL (0 + 11) // P0.11

// LED
#define PIN_LED1 (0 + 15) // P0.15
#define LED_BUILTIN PIN_LED1
// Actually red
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1 // State when LED is lit

// Button
#define BUTTON_PIN (32 + 0) // P1.00

// GPS
#define PIN_GPS_TX (0 + 22) // P0.22
#define PIN_GPS_RX (0 + 20) // P0.20

#define PIN_GPS_EN (0 + 24) // P0.24
#define GPS_POWER_TOGGLE
#define GPS_UBLOX
// define GPS_DEBUG

// UART interfaces
#define PIN_SERIAL1_RX PIN_GPS_TX
#define PIN_SERIAL1_TX PIN_GPS_RX

#define PIN_SERIAL2_RX (0 + 6) // P0.06
#define PIN_SERIAL2_TX (0 + 8) // P0.08

// Serial interfaces
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO (0 + 2)   // P0.02
#define PIN_SPI_MOSI (32 + 15) // P1.15
#define PIN_SPI_SCK (32 + 11)  // P1.11

// LORA MODULES
// Adafruit RFM95W uses the Semtech SX127x/RFM95 driver path, not SX126x/LLCC68.
#define USE_RF95

// LORA CONFIG - Adafruit RFM95W / SX127x
#define LORA_CS (32 + 13)       // P1.13 -> RFM95W CS
#define LORA_DIO0 (0 + 10)      // P0.10 -> RFM95W G0 / DIO0 / IRQ
#define LORA_RESET (0 + 9)      // P0.09 -> RFM95W RST
#define LORA_DIO1 RADIOLIB_NC   // Not required by Meshtastic RF95Interface
#define LORA_DIO2 RADIOLIB_NC   // Not required by Meshtastic RF95Interface

// Adafruit RFM95W uses the PA_BOOST output path and supports up to 20 dBm.
// Do not define USE_RF95_RFO for this module, or RadioLib will use the lower-power RFO path.
#define RF95_MAX_POWER 20
#define RF95_ALLOW_20DBM_TX_POWER

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
