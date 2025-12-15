#pragma once

#include <stdint.h>

#define RADIO_PROTOCOL_VERSION 1

// Matches command.schema.json "mode"
typedef enum {
    MODE_MANUAL = 0,
    MODE_AUTO = 1,
    MODE_EMERGENCY_STOP = 2
} rover_mode_t;

// Controller -> Rover packet
typedef struct __attribute__((packed)) {
    uint8_t  version;         // RADIO_PROTOCOL_VERSION
    uint32_t timestamp_ms;    // Unix time (ms)
    uint8_t  mode;            // rover_mode_t
    int16_t  throttle;        // -1000 to +1000
    int16_t  steering;        // -1000 to +1000
} rover_command_packet_t;
