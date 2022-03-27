#include <XboxSeriesXControllerESP32_asukiaaa.hpp>

XboxSeriesXControllerESP32_asukiaaa::Core xboxController("44:16:22:5e:b2:d4");

void setup() {
  Serial.begin(115200);
  Serial.println("Starting NimBLE Client");
  xboxController.begin();
}

static float calcMin0MaxPlus(int32_t joystickValue, int32_t joystickMax) {
  auto halfMax = joystickMax / 2;
  return (double)(joystickValue - halfMax) / halfMax;
}

void loop() {
  xboxController.onLoop();
  if (xboxController.isConnected()) {
    Serial.println(xboxController.xboxNotif.joyLHori);
    Serial.println(xboxController.xboxNotif.joyLVert);
    uint16_t joystickMax = XboxControllerNotificationParser::maxJoy;
    Serial.println(calcMin0MaxPlus(xboxController.xboxNotif.joyLHori, joystickMax));
    Serial.println(-calcMin0MaxPlus(xboxController.xboxNotif.joyLVert, joystickMax));
  } else {
    Serial.print("not connected");
  }
  Serial.println(" at " + String(millis()));
  delay(500);
}
