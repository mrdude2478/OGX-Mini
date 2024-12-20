#ifndef _PS3_DEVICE_H_
#define _PS3_DEVICE_H_

#include <cstdint>
#include <array>

#include "USBDevice/DeviceDriver/DeviceDriver.h"
#include "Descriptors/PS3.h"

class PS3Device : public DeviceDriver 
{
public:
    void initialize() override;
    void process(const uint8_t idx, Gamepad& gamepad) override;
    uint16_t get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen) override;
    void set_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize) override;
    bool vendor_control_xfer_cb(uint8_t rhport, uint8_t stage, tusb_control_request_t const *request) override;
    const uint16_t* get_descriptor_string_cb(uint8_t index, uint16_t langid) override;
    const uint8_t* get_descriptor_device_cb() override;
    const uint8_t* get_hid_descriptor_report_cb(uint8_t itf)  override;
    const uint8_t* get_descriptor_configuration_cb(uint8_t index) override;
    const uint8_t* get_descriptor_device_qualifier_cb() override;

private:
    PS3::InReport report_in_;
    PS3::OutReport report_out_;
    PS3::BTInfo bt_info_;
    uint8_t ef_byte_;
    bool new_report_out_{false};
};

#endif // _PS3_DEVICE_H_
