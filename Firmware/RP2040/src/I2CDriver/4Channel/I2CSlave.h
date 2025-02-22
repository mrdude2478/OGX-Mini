#ifndef I2C_SLAVE_4CH_H
#define I2C_SLAVE_4CH_H

#include <cstdint>
#include <atomic>
#include <cstring>
#include <hardware/i2c.h>
#include <pico/i2c_slave.h>

#include "board_config.h"
#include "Gamepad/Gamepad.h"
#include "I2CDriver/4Channel/I2CDriver.h"

class I2CSlave : public I2CDriver
{
public:
    ~I2CSlave() = default;
    void initialize(uint8_t address) override;
    void process(Gamepad (&gamepads)[MAX_GAMEPADS]) override;
    void notify_tuh(bool mounted, HostDriverType host_type) override;

private:
    static I2CSlave* instance_;

    PacketIn packet_in_;
    PacketOut packet_out_;
    std::atomic<bool> new_pad_in_{false};
    std::atomic<bool> tuh_mounted_{false};

    static PacketID get_packet_id(uint8_t* buffer_in);
    static void slave_handler(i2c_inst_t *i2c, i2c_slave_event_t event);
};

#endif // I2C_SLAVE_4CH_H