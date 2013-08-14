#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int dowrite(unsigned int par1, double par2, SOCKET sock) {

    HUDAQHANDLE h;
    char msg[100];

    /* open a handle to the first MF624 device in the system */
    h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        sendMsg(sock, HUMERR);
        printf("\nData acquisition device not found.\n");
        return(-1);
    }

    HudaqDOWriteBit(h, 0, par1, par2);

    /* write 0xFF to whole digital channel at once */
    //HudaqDOWrite(h,0,0xFF);//nebo par1 misto 0xFF

    //printf("\n0xFF was writen to digital output. Press any key to continue.");
    //getchar();

    /* write 0x00 to whole digital channel at once */
    //HudaqDOWrite(h,0,0x0);
    //printf("\n0x00 has been writen to digital output.");

    /* close the device handle */
    HudaqCloseDevice(h);

    return(0);
}

