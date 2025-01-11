# arduino-XboxSeriesXControllerESP32 (XboxSeriesXControllerESP32_asukiaaa)

A library to use xbox controller on ESP32.

## Update firmware of controller

This libary is checked with firmware version `5.13.3143.0` for xbox series X controller.
You can check and udpate firmware with using [Xbox accessories](https://www.microsoft.com/en-us/p/xbox-accessories/9nblggh30xj3#activetab=pivot:overviewtab).

## Setup

### Version infromation

For NimBLE 2.1.0 or more, use version 1.1.0 or more of this library.<br />
For NimBle less than 2.1.0 (1.4.3 or less), use version 1.0.9 of this library.

### Arduino IDE

Install XboxSeriesXControllerESP32_asukiaaa from library manager.

### PlatformIO

Specify XboxSeriesXControllerESP32_asukiaaa as lib_deps on platformio.ini

```
lib_deps = XboxSeriesXControllerESP32_asukiaaa
```

## Usage

See [examples](./examples).

## Introduction of receiver library that can use via I2C

If you want to make receiver of Xbox controller, write [firmware about xbox controller](https://github.com/asukiaaa/arduino-ControllerAsI2c/blob/main/examples/slave_target/esp32/wireless-xbox-series-x/wireless-xbox-series-x.ino) to ESP32 then use it by [ControllerAsI2c_asukiaaa](https://github.com/asukiaaa/arduino-ControllerAsI2c) library from other IC via I2C connection.

## Known issue.

The following error occurs on ESP32.
```
lld_pdu_get_tx_flush_nb HCI packet count mismatch (1, 2)
```

It does not occur on ESP32C3 (may be also S3) because BLE5 may be needed to communicate with xbox controller.
If you want to use this library without the error, please use ESP32 which supports BLE5.

Related issues:
- [Connection is not the first time](https://github.com/asukiaaa/arduino-XboxSeriesXControllerESP32/issues/3)
- [BLE service discovery fails on low BLE connections](https://github.com/espressif/esp-idf/issues/8303)
- [Request of some advice to solve lld_pdu_get_tx_flush_nb HCI packet count mismatch (1, 2)](https://github.com/h2zero/NimBLE-Arduino/issues/293)
- [Reset scanning state without resetting esp32](https://github.com/h2zero/NimBLE-Arduino/issues/417)

## License

MIT

## References

- [NimBLE_Client](https://github.com/h2zero/NimBLE-Arduino/blob/master/examples/NimBLE_Client/NimBLE_Client.ino)
- [asukiaaa/arduino-XboxControllerNotificationParser](https://github.com/asukiaaa/arduino-XboxControllerNotificationParser)
- [asukiaaa/arduino-XboxSeriesXHIDReportBuilder](https://github.com/asukiaaa/arduino-XboxSeriesXHIDReportBuilder)
