/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

void sleepTime() {
    ThisThread::sleep_for(500ms);
}

int main()
{
    DigitalIn keyZero(PB_0);
    keyZero.mode(PullDown);

    DigitalIn keySeven(PB_7);
    keySeven.mode(PullDown);

    PortOut lights(PortC, 0b1111);
    lights = 0;

    int mode = 0;

    while (true) {
        if (keyZero && keySeven) {
            mode = 0;
        } else if (!keyZero && keySeven) {
            mode = 3;
        } else if (keyZero && !keySeven) {
            mode = 2;
        } else {
            mode = 1;
        }

        switch (mode) {
            case 0:
                lights = 0;
                break;
            case 1:
                lights = 0b0001; // >>
                sleepTime();
                lights = 0b0010;
                sleepTime();
                lights = 0b0100;
                sleepTime();
                lights = 0b1000;
                sleepTime();
                break;
            case 2:
                lights = 0b0011;
                sleepTime();
                lights = 0b0110;
                sleepTime();
                lights = 0b1100;
                sleepTime();
                lights = 0b1001;
                sleepTime();
                break;
            case 3:
                lights = 0b0001;
                sleepTime();
                lights = 0b1000;
                sleepTime();
                lights = 0b0100;
                sleepTime();
                lights = 0b0010;
                sleepTime();
                break;
        }
    }

}
