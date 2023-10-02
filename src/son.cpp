#include "WriteRead.h"

int main() {
    std::string line;
    line = ScanString(STDIN_FILENO);
    if (isupper(line[0])) {
        WriteString(STDOUT_FILENO, line);
        WriteString(STDERR_FILENO, "String is valid, check the file\n");
    } else {
        WriteString(STDERR_FILENO, "String is not valid\n");
    }
}
