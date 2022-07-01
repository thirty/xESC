#ifndef SRC_XESC_2040_DATATYPES_H
#define SRC_XESC_2040_DATATYPES_H

#include <cstdint>

#define XESC2040_MSG_TYPE_STATUS 1
#define XESC2040_MSG_TYPE_CONTROL 2
#define XESC2040_MSG_TYPE_SETTINGS 3



#pragma pack(push, 1)
struct Xesc2040StatusPacket {
    uint8_t message_type;
    uint32_t seq;
    uint8_t fw_version_major;
    uint8_t fw_version_minor;
    double voltage_input;        // input voltage (volt)
    double temperature_pcb;      // temperature of printed circuit board (degrees Celsius)
    double temperature_motor;      // temperature of printed circuit board (degrees Celsius)
    double current_input;        // input current (ampere)
    double duty_cycle;           // duty cycle (0 to 1)
    uint32_t tacho;
    int32_t fault_code;
    uint16_t crc;
} __attribute__((packed));
#pragma pack(pop)

#pragma pack(push, 1)
struct Xesc2040ControlPacket {
    uint8_t message_type;
    double duty_cycle;           // duty cycle (0 to 1)
    uint16_t crc;
} __attribute__((packed));
#pragma pack(pop)

#pragma pack(push, 1)
struct Xesc2040SettingsPacket {
    uint8_t message_type;
    uint8_t hall_table[8];
    float motor_current_limit;
    float acceleration;
    bool has_motor_temp;
    float min_motor_temp;
    float max_motor_temp;
    float min_pcb_temp;
    float max_pcb_temp;
    uint16_t crc;
} __attribute__((packed));
#pragma pack(pop)

#endif //SRC_XESC_2040_DATATYPES_H