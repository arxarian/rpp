#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int airead(unsigned int par1, double par2, SOCKET sock) {

    //HUDAQHANDLE h;
    double value;
    char msg[100];

    /* open a handle to the first MF624 device in the system */
    //h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        printf("\nData acquisition device not found.\n");
        sendMsg(sock, HUMERR);
        return -1;
    }

    /* read analog input par1 */
    value = HudaqAIRead(h, par1) * 1000;
    printf("\nAnalog channel %d, value read %f mV. Integer read %d mV.\n", par1, value, (int)value);

    sprintf(msg, "airead%d=%d%\r\n", par1, (int)value);
    sendMsg(sock, msg);

    /* close the device handle */
    //HudaqCloseDevice(h);

    return 0;
}

