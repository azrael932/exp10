#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;
const int LED_PIN = 13;
bool should_blink = false;

void startBlinkCallback(const std_msgs::Empty& msg) {
  should_blink = true;
}

ros::Subscriber<std_msgs::Empty> blink_sub("start_blink", &startBlinkCallback);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  nh.initNode();
  nh.subscribe(blink_sub);
}

void loop() {
  if (should_blink) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
  nh.spinOnce();
}
