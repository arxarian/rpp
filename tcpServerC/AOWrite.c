#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int aowrite(unsigned int par1, double par2, SOCKET sock) {

    HUDAQHANDLE h;
    char msg[100];

    printf("Analog output: write to channel %d value %f\n", par1, par2);

    /* open a handle to the first MF624 device in the system */
    h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        sendMsg(sock, HUMERR);
        printf("\nData acquisition device not found.\n");
        return(-1);
    }

    HudaqAOWrite(h, par1, par2);
    printf("Analog output channel %d, value written %f V.\n", par1, par2);

    sprintf(msg, "aowrite%d=%f\r\n", par1, par2);
    sendMsg(sock, msg);

    /* close the device handle */
    HudaqCloseDevice(h);

    return(0);
}

