#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>

#include "commands.h"
#include "server.h"

#define DEFAULT_PORT        8890
#define DEFAULT_BUFFER      4096

command *cm;

int parseLine(char *line, int *par1Add, double *par2Add) {

    int i = 0;
    char *com, *par1, *par2;

    com = strtok(line," ");
    par1 = strtok(NULL, " ");
    par2 = strtok(NULL, " ");
    if(strtok (NULL, " ") != NULL) return -2;
    *par1Add = atoi(par1);
    *par2Add = atof(par2); //printf("char2: %s\n", par2);printf("char2.0: %f\n", *par2Add);

    do {
        if(strcmp(cm[i].name, com) == 0){
           return i;
        }
    } while (cm[++i].func != NULL);

    return -1;
}

int printCommands(SOCKET sock) {
    int i = 0;
    char msg[100];

    do {
        sprintf(msg, "%s\t-\t%s\r\n", cm[i].name, cm[i].desc);
        sendMsg(sock, msg);
    } while (cm[++i].func != NULL);
    return 0;
}

int clientConnected(SOCKET sClient) {

    SOCKET sock=sClient;
    char szBuff[DEFAULT_BUFFER];
    int ret, exeCommand, par1;
    double par2;

    //printCommands(sClient);
    sendMsg(sock, "server\n");

    while(1) {

        //szBuff = recvMsg(sClient);
        ret = recv(sock, szBuff, DEFAULT_BUFFER, 0);
        if (ret == 0) break;// Graceful close
        else if (ret == SOCKET_ERROR) {
            printf("recv() failed: %d\n", WSAGetLastError());
            break;
        }

    szBuff[ret] = '\0';
    if(strcmp(szBuff, "\r\n") == 0) continue;

        printf("rec: '%s'\n", szBuff);
        exeCommand = parseLine(szBuff, &par1, &par2);//printf("char2.1: %f\n", par2);
        if(exeCommand == -1) {
            sendMsg(sock, "command not found\r\n");
        }
        else if(exeCommand == -2) {
            sendMsg(sock, "bad parameter\r\n");
        }
        else {
            cm[exeCommand].func(par1, par2, sock);
            printf("%s %d %f\r\n", cm[exeCommand].name, par1, par2);
        }

    }
    return 0;
}

int startServer()
{
    WSADATA       wsd;
    SOCKET        sListen, sClient;
    int           iAddrSize;
    struct sockaddr_in local, client;

    //winsock init
    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0) {
        printf("Failed to load Winsock!\n");
        return 1;
    }

    //listening socket
    sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sListen == SOCKET_ERROR) {
        printf("socket() failed: %d\n", WSAGetLastError());
        return 1;
    }

    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_family = AF_INET;//host by order
    local.sin_port = htons(DEFAULT_PORT);

    if (bind(sListen, (struct sockaddr *)&local, sizeof(local)) == SOCKET_ERROR) {
        printf("bind() failed: %d\n", WSAGetLastError());
        return 1;
    }

    listen(sListen, 8);
    printf("Server is listening at port: %d\n", DEFAULT_PORT);

    while (1) {
        iAddrSize = sizeof(client);
        sClient = accept(sListen, (struct sockaddr *)&client, &iAddrSize);

        if (sClient == INVALID_SOCKET) {
            printf("accept() failed: %d\n", WSAGetLastError());
        }
        printf("Accepted client: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        clientConnected(sClient);
        printf("Client disconnected\n");
    }

    closesocket(sListen);
    WSACleanup();

    return 0;
}

int main()
{
    cm = initCommands();
    h = HudaqOpenDevice("MF614", 1, 0);

    startServer();

    return 0;
}
