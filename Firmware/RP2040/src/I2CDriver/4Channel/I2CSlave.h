#ifndef I2C_SLAVE_4CH_H
#define I2C_SLAVE_4CH_H

#include <cstdint>
#include <atomic>
#include <cstring>
#include <pico/time.h>
#include <hardware/gpio.h>
#include <hardware/i2c.h>
#include <pico/i2c_slave.h>

#include "board_config.h"
#include "Gamepad.h"
#include "I2CDriver/4Channel/I2CDriver.h"

class I2CSlave : public I2CDriver
{
public:
    void initialize(uint8_t address) override;
    void process(Gamepad (&gamepads)[MAX_GAMEPADS]) override;
    void notify_tuh_mounted(HostDriver::Type host_type) override;
    void notify_tuh_unmounted(HostDriver::Type host_type) override;
    void notify_xbox360w_connected(uint8_t idx) override {};
    void notify_xbox360w_disconnected(uint8_t idx) override {};

private:
    static I2CSlave* this_instance_;
    PacketIn packet_in_;
    PacketOut packet_out_;
    std::atomic<bool> i2c_disabled_;

    static PacketID get_packet_id(uint8_t* buffer_in);
    static void slave_handler(i2c_inst_t *i2c, i2c_slave_event_t event);
};

#endif // I2C_SLAVE_4CH_H