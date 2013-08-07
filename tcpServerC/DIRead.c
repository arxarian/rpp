#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int diread(unsigned int par1, double par2, SOCKET sock) {

    HUDAQHANDLE h;
    unsigned value;

    char msg[100];

    /* open a handle to the first MF624 device in the system */
    h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        printf("\nData acquisition device not found.\n");
        sendMsg(sock, HUMERR);
        return -1;
    }

    /* read bit */
    value = HudaqDIReadBit(h, 0, par1);
    sprintf(msg, "diread%d=%d%\r\n", par1, value);
    sendMsg(sock, msg);
    printf("\nValue read from digital bit %d: %d ", par1, value);

    /* close the device handle */
    HudaqCloseDevice(h);

    return 0;
}

