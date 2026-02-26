#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Served by backend container" << std::endl;
    while(true) sleep(10);
    return 0;
}