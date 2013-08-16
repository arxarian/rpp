#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

typedef struct command {
    int ID;
    char * name;
    char * desc;
    int (*func) (unsigned int, double, SOCKET sock);
} command;

command * initCommands(void);
//void doHelp(int * par, command * cm, SOCKET sock);
void quit(unsigned int par1, double par2, SOCKET sock);

#endif // COMMANDS_H_INCLUDED
