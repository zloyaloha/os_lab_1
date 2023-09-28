#pragma once
#include <iostream>
#include <string>
#include "stdio.h"
#include "unistd.h"
#include <cstdlib>
#include "sys/wait.h"
#include <fstream>
#include <fcntl.h>
#include <sys/stat.h>

void WriteString(int stream, std::string line);
std::string ScanString(int stream);

