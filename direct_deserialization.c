#include <stdio.h>
#include <string.h>
#include <stdint.h>

enum sensor_states {
    SUCCESS = 0,
    FAILED,
    NOT_USED
};

typedef struct struct_sensor {
    uint8_t state;
    float value;
} struct_sensor;

typedef struct struct_version {
    uint8_t major;
    uint8_t minor;
} struct_version;

typedef struct struct_message {
    uint8_t id; // must be unique for each sender board
    struct_sensor sensor_1;
    struct_sensor sensor_2;
    struct_version ver;
    uint32_t intervall;
} struct_message;

int main() {
    // Create and initialize a struct_message
    struct_message msg;
    msg.id = 1;
    msg.sensor_1.state = SUCCESS;
    msg.sensor_1.value = 23.5;
    msg.sensor_2.state = FAILED;
    msg.sensor_2.value = 0.0;
    msg.ver.major = 1;
    msg.ver.minor = 0;
    msg.intervall = 1000;

    // Create a buffer to hold the serialized data
    char buffer[sizeof(struct_message)];

    // Copy the struct_message into the buffer
    memcpy(buffer, &msg, sizeof(struct_message));

    // Access the buffer as a struct_message pointer
    struct_message *received_msg = (struct_message *)buffer;

    // Print the deserialized data
    printf("Received Message:\n");
    printf("ID: %d\n", received_msg->id);
    printf("Sensor 1 - State: %d, Value: %.2f\n", received_msg->sensor_1.state, received_msg->sensor_1.value);
    printf("Sensor 2 - State: %d, Value: %.2f\n", received_msg->sensor_2.state, received_msg->sensor_2.value);
    printf("Version - Major: %d, Minor: %d\n", received_msg->ver.major, received_msg->ver.minor);
    printf("Intervall: %d\n", received_msg->intervall);

    return 0;
}
