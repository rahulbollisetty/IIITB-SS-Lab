/*
============================================================================    
Name : 34client.c
Author : B Rahul
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 11th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[256];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(16000); // Use the same port as the server
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter a message to send to the server (or type 'quit' to exit): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Send the message to the server
        write(client_socket, buffer, strlen(buffer));

        // Check if the client wants to quit
        if (strncmp(buffer, "quit", 4) == 0)
            break;

        // Receive and display the response from the server
        int bytes_received = read(client_socket, buffer, sizeof(buffer));
        if (bytes_received <= 0) {
            perror("Server disconnected or an error occurred");
            break;
        }

        // Null-terminate the received data
        buffer[bytes_received] = '\0';

        printf("Received from server: %s", buffer);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}