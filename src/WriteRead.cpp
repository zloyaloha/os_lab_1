#include "WriteRead.h"
#include <iostream>
#include <string>
#include "stdio.h"
#include "unistd.h"
#include <cstdlib>
#include "sys/wait.h"
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h>

std::string ScanString(int stream) {
    char c;
    std::string line;
    while (1) {
        if (c == '\n') break;
        read(stream, &c, sizeof(char));
        line.push_back(c);
    }
    return line;
}

void WriteString(int stream, std::string line) {
    write(stream, line.c_str(), line.size());
}