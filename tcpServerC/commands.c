#include <stdio.h>

#include "AIRead.h"
#include "AOWrite.h"
#include "DIRead.h"
#include "DOWrite.h"
#include "commands.h"
#include "server.h"
/*
void doHelp(int * par, command * cm, SOCKET sock) {
    char msg[100];
    int i = 0;

    do {
        sprintf(msg, "%s\t-\t%s\n", cm[i].name, cm[i].desc);
        sendMsg(sock, msg);
    } while (cm[++i].func != NULL);


    return msg;
}
*/
void quit(unsigned int par1, double par2, SOCKET sock) {

        HudaqCloseDevice(h);
}

command * initCommands(void) {

    static command commands[] = {
        {0, "diread", "reads DIN of digital input channels", diread},
        {1, "dowrite", "writes all bits to a digital output channels", dowrite},
        {2, "airead", "reading aIN of analog input channels", airead},
        {3, "aowrite", "writes to analog output channels", aowrite},
        {4, "quit", "close hummusoft device", quit},
        {5, "", "", NULL}};

    //printf("init complete\n");

    return commands;
}
