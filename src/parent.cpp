#include "WriteRead.h"

#define READ 0
#define WRITE 1

int main() {
    int pipe_fd1[2];
    int pipe_fd2[2];
    WriteString(STDOUT_FILENO, "Type the name of file: \n");
    int fd_file;
    mode_t mode = S_IRWXU;
	int flags = O_WRONLY | O_CREAT | O_APPEND;
    if ((fd_file = open(ScanString(STDIN_FILENO).c_str(), flags, mode)) < 0) {
        WriteString(STDOUT_FILENO, "File isn't opened\n");
        perror("file");
    }
    if (pipe(pipe_fd1) == -1) {
        perror("pipe");
        return -1;
    }
    if (pipe(pipe_fd2) == -1) {
        perror("pipe");
        return -1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        close(pipe_fd2[READ]);
        close(pipe_fd1[WRITE]);
        dup2(pipe_fd2[WRITE], STDERR_FILENO);
        dup2(pipe_fd1[READ], STDIN_FILENO);
        dup2(fd_file, STDOUT_FILENO);
        execl("son.out", "son.out", NULL);
    } else if (pid > 0) {
        std::string input;
        close(pipe_fd1[READ]);
        close(pipe_fd2[WRITE]);
        WriteString(STDOUT_FILENO, "Type string to check: \n");
        WriteString(pipe_fd1[WRITE], ScanString(STDIN_FILENO));
        WriteString(STDOUT_FILENO, ScanString(pipe_fd2[READ]));
        wait(NULL);
        close(pipe_fd1[WRITE]);
        close(pipe_fd2[READ]);
    } else {
        perror("fork");
        return -1;
    }
}
