#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define READ 0
#define WRITE 1

int main() {
    int ptoc;
    int ctop;

	mkfifo("ptoc", 0644);
    mkfifo("ctop", 0644);

    ptoc = open("ptoc", O_WRONLY);
    ctop = open("ctop", O_RDONLY);
    
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), stdin)) {
        char s[100];
        write(ptoc, buffer, sizeof(buffer));
        read(ctop, s, sizeof(s));
        
        printf("%s\n", s);
    }

	return 0;	
}
