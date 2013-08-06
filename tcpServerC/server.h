#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <winsock.h>

static const char HUMERR[] = "Data acquisition device not found.\n";

int sendMsg(SOCKET sock, char * msg);
char * recvMsg(SOCKET sock);

#endif // SERVER_H_INCLUDED
