#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char message[] = "hi from parent";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) { 
        read(fd[0], buffer, sizeof(buffer));
        printf("child received: %s\n", buffer);
    } else { 
        write(fd[1], message, strlen(message) + 1);
    }
    return 0;
}
