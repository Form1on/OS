#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pid.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) { 
        dprintf(fd, "Child PID: %d\n", getpid());
    } else {
        dprintf(fd, "Parent PID: %d\n", getpid());
    }
    close(fd);
    return 0;
}
