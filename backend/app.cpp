#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd,(struct sockaddr*)&address,sizeof(address));
    listen(server_fd,3);

    while(true){
        int new_socket = accept(server_fd,nullptr,nullptr);
        std::string response =
        "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nServed by backend\n";
        send(new_socket,response.c_str(),response.size(),0);
        close(new_socket);
    }
}
