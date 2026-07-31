#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "server.h"
#include "router.h"

void startServer()
{
    int server_fd;
    int client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd == 0)
    {
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 5) < 0)
    {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }

    printf("=====================================\n");
    printf(" CityCare Hospital Server Started\n");
    printf(" Running on Port %d\n", PORT);
    printf("=====================================\n");

    while(1)
    {
        client_socket = accept(server_fd,
                               (struct sockaddr *)&address,
                               (socklen_t *)&addrlen);

        if(client_socket < 0)
        {
            perror("Accept Failed");
            continue;
        }

        memset(buffer, 0, BUFFER_SIZE);

        read(client_socket, buffer, BUFFER_SIZE);

        printf("\nRequest Received:\n\n%s\n", buffer);

        handleRequest(client_socket, buffer);

        close(client_socket);
    }
}