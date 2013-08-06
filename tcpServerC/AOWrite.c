#include <stdio.h>
#include <winsock.h>

#include "hudaqlib.h"
#include "server.h"

int aowrite(unsigned int par1, double par2, SOCKET sock) {

    HUDAQHANDLE h;
    unsigned int i;
    //double value;

    char msg[100];
    printf("Analog output: write to channel %d value %f\n", par1, par2);

    /* open a handle to the first MF624 device in the system */
    h = HudaqOpenDevice("MF614", 1, 0);
    if (h==0) {
        sendMsg(sock, HUMERR);
        printf("\nData acquisition device not found.\n");
        return(-1);
    }

    /* write all the 8 analog outputs in a loop */
    /* the voltage written to the output is computed as (channel number - 5) */
    //for (i=0; i<8; i++)
    //{
    //value = i-5.0;
    //HudaqAOWrite(h, i, value);
    HudaqAOWrite(h, par1, par2);
    printf("Analog output channel %d, value written %fV.\n", par1, par2);
    //}

    /* close the device handle */
    HudaqCloseDevice(h);

    return(0);
}

