#ifndef _BLUEPAD_32_H_
#define _BLUEPAD_32_H_

#include <cstdint>
#include <array>

#include "Gamepad/Gamepad.h"
#include "board_config.h"

/*  NOTE: Everything bluepad32/uni needs to be wrapped
    and kept away from tinyusb due to naming conflicts */

namespace bluepad32 
{
    void run_task(Gamepad(&gamepads)[MAX_GAMEPADS]);
} 

#endif // _BLUEPAD_32_H_