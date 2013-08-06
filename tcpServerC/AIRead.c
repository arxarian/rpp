#include <stdio.h>
#include <winsock.h>
//#include <string.h>

#include "hudaqlib.h"
#include "server.h"

int airead(unsigned int par1, double par2, SOCKET sock) {

    HUDAQHANDLE h;
    unsigned i;
    double value;

    char msg[100];

    /* open a handle to the first MF624 device in the system */
    h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        //sendMsg(sock, HUMERR);
        sendMsg(sock, HUMERR);
        printf("\nData acquisition device not found.\n");
        return(-1);
    }

    /* read all the 8 analog inputs in a loop, print their values */
    //for (i=0; i<8; i++) {
        value = HudaqAIRead(h, par1);
        sprintf(msg, "%f", value);
        sendMsg(sock, msg);
        printf("Analog channel %d, value read %fV.\n", par1, value);
    //}

    /* close the device handle */
    HudaqCloseDevice(h);

    return(0);
}

