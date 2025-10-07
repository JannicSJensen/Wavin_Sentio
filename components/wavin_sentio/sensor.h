#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "wavin_sentio.h"

namespace esphome {
namespace wavin_sentio {

enum SensorType : uint8_t {
  BATTERY = 0,
  TEMPERATURE = 1,
  FLOOR_TEMPERATURE = 2,
  COMFORT_SETPOINT = 3,
  HUMIDITY = 4,
};

class WavinSentioSensor : public sensor::Sensor, public Component {
 public:
  WavinSentioSensor() = default;

  void setup() override;
  void loop() override;
  void dump_config() override;
  void update();

  float get_setup_priority() const override { return setup_priority::DATA; }

  // Configuration methods
  void set_parent(WavinSentio *parent) { this->parent_ = parent; }
  void set_channel(uint8_t channel) { this->channel_ = channel; }
  void set_sensor_type(SensorType type) { this->sensor_type_ = type; }

  // Getters
  uint8_t get_channel() const { return this->channel_; }
  SensorType get_sensor_type() const { return this->sensor_type_; }

 protected:
  WavinSentio *parent_{nullptr};
  uint8_t channel_{0};
  SensorType sensor_type_{SensorType::TEMPERATURE};
};

}  // namespace wavin_sentio
}  // namespace esphome