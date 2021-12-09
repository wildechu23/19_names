#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main() {
    //c
    int ptoc;
    int ctop;

    ptoc = open("ptoc", O_RDONLY);
    ctop = open("ctop", O_WRONLY);

    char s[100];
    while(read(ptoc, s, sizeof(s))) {
        s[strlen(s)-1] = '\0';
        strcat(s, "<3");
        s[strlen(s)] = '\0';
        //printf("%s\n", s);
        write(ctop, s, strlen(s)+1);
        s[0] = '\0';
    }

	return 0;	
}
