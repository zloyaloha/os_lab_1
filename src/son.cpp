#include "WriteRead.h"

int main() {
    std::string line;
    while (1) {
        line = ScanString(STDIN_FILENO);
        // if (line == "stop\n") break;
        if (isupper(line[0])) {
            WriteString(STDOUT_FILENO, line);
            WriteString(STDERR_FILENO, "String is valid, check the file\n");
        } else {
            WriteString(STDERR_FILENO, "String is not valid\n");
        }
    }
}
