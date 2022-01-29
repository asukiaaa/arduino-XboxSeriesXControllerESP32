
#include <XboxSeriesXControllerESP32.hpp>

XboxSeriesXControllerESP32::Core xboxController("44:16:22:5e:b2:d4");

void setup() {
  Serial.begin(115200);
  Serial.println("Starting NimBLE Client");
  xboxController.begin();
}

void loop() {
  xboxController.onLoop();
  if (xboxController.isConnected()) {
    Serial.print(xboxController.xboxNotif.joyLHori);
  } else {
    Serial.print("not connected");
  }
  Serial.println(" at " + String(millis()));
  delay(500);
}
