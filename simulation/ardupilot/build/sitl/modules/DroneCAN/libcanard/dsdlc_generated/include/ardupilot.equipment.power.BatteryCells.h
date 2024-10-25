#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_MAX_SIZE 51
#define ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_SIGNATURE (0x5C8B1ABD15890EA4ULL)
#define ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_ID 20012

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class ardupilot_equipment_power_BatteryCells_cxx_iface;
#endif

struct ardupilot_equipment_power_BatteryCells {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = ardupilot_equipment_power_BatteryCells_cxx_iface;
#endif
    struct { uint8_t len; float data[24]; }voltages;
    uint16_t index;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t ardupilot_equipment_power_BatteryCells_encode(struct ardupilot_equipment_power_BatteryCells* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool ardupilot_equipment_power_BatteryCells_decode(const CanardRxTransfer* transfer, struct ardupilot_equipment_power_BatteryCells* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _ardupilot_equipment_power_BatteryCells_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryCells* msg, bool tao);
static inline void _ardupilot_equipment_power_BatteryCells_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryCells* msg, bool tao);
void _ardupilot_equipment_power_BatteryCells_encode(uint8_t* buffer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryCells* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 5, &msg->voltages.len);
    *bit_ofs += 5;
    for (size_t i=0; i < msg->voltages.len; i++) {
        {
            uint16_t float16_val = canardConvertNativeFloatToFloat16(msg->voltages.data[i]);
            canardEncodeScalar(buffer, *bit_ofs, 16, &float16_val);
        }
        *bit_ofs += 16;
    }
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->index);
    *bit_ofs += 16;
}

void _ardupilot_equipment_power_BatteryCells_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct ardupilot_equipment_power_BatteryCells* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->voltages.len);
    *bit_ofs += 5;
    for (size_t i=0; i < msg->voltages.len; i++) {
        {
            uint16_t float16_val;
            canardDecodeScalar(transfer, *bit_ofs, 16, true, &float16_val);
            msg->voltages.data[i] = canardConvertFloat16ToNativeFloat(float16_val);
        }
        *bit_ofs += 16;
    }

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->index);
    *bit_ofs += 16;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct ardupilot_equipment_power_BatteryCells sample_ardupilot_equipment_power_BatteryCells_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(ardupilot_equipment_power_BatteryCells, ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_ID, ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_SIGNATURE, ARDUPILOT_EQUIPMENT_POWER_BATTERYCELLS_MAX_SIZE);
#endif
#endif
