/*
============================================================================    
Name : 34fs.c
Author : B Rahul
Description : Write a program to create a concurrent server.
a. use fork
(server program)
Date: 11th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 10

// Function to handle a client connection
void handle_client(int client_socket) {
    char buffer[256];

    while (1) {
        int bytes_received = read(client_socket, buffer, sizeof(buffer));
        if (bytes_received <= 0) {
            // Client disconnected or an error occurred
            close(client_socket);
            exit(EXIT_SUCCESS); // Terminate the child process
        }

        // Null-terminate the received data
        buffer[bytes_received] = '\0';
        printf("Received from client %d: %s", client_socket, buffer);

        // Echo the received data back to the client
        write(client_socket, buffer, bytes_received);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_count = 0;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(16000);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 16000...\n");

    while (1) {
        // Accept a new connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("Accepting failed");
            continue;
        }

        printf("Client %d connected\n", client_socket);

        // Fork a new process to handle the client
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("Fork failed");
            close(client_socket);
            continue;
        }

        if (child_pid == 0) {
            // Child process
            close(server_socket); // Close the server socket in the child process
            handle_client(client_socket);
        } else {
            // Parent process
            close(client_socket); 
            client_count++;
            if (client_count >= MAX_CLIENTS) {
                printf("Maximum number of clients reached. Rejecting new connections.\n");
                close(client_socket);
            }
        }
    }

    close(server_socket);

    return 0;
}
