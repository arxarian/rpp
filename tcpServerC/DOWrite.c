#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int dowrite(unsigned int par1, double par2, SOCKET sock) {

    //HUDAQHANDLE h;
    char msg[100];

    printf("Digital output: write to pin %d value %f\n", par1, par2);

    /* open a handle to the first MF624 device in the system */
    //h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        sendMsg(sock, HUMERR);
        printf("\nData acquisition device not found.\n");
        return(-1);
    }

    HudaqDOWriteBit(h, 0, par1, par2);
    printf("Digital output pin %d, value written %d.\n", par1, (int)par2);

    sprintf(msg, "dowrite%d=%d\r\n", par1, (int)par2);
    sendMsg(sock, msg);

    /* close the device handle */
    //HudaqCloseDevice(h);

    return(0);
}

