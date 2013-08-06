#include <stdio.h>
#include <winsock.h>

int sendMsg(SOCKET sock, char *msg) {

    int len = strlen(msg);
    int ret = send(sock, msg, len, 0);
    if (ret == 0) return 1;
    else if (ret == SOCKET_ERROR) {
        printf("send() failed: %d\n", WSAGetLastError());
        return 2;
    }
    return 0;
}

char * recvMsg(SOCKET sock) {//receiving until "\n"

    int ret;
// TODO (ar#1#): recvMsg prijima, ale nepredava pridana data ...
//sendall
//receiveall

/*    ret = recv(sock, szBuff, DEFAULT_BUFFER, 0);
    if (ret == 0) break;// Graceful close
    else if (ret == SOCKET_ERROR) {
        printf("recv() failed: %d\n", WSAGetLastError());
        break;
    }



    szBuff[ret] = '\0';
    if(strcmp(szBuff, "\r\n") == 0) continue;
*/
    return 0;
}
