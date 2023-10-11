/*
============================================================================    
Name : 34ts.c
Author : Siddharth V. Pillai
Description : Write a program to create a concurrent server.
b. use pthread_create
(server program)
Date: 9th Oct, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

// Function to handle a client connection
void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[MAX_MESSAGE_SIZE];

    while (1) {
        int bytes_received = read(client_socket, buffer, sizeof(buffer));
        if (bytes_received <= 0) {
            // Client disconnected or an error occurred
            close(client_socket);
            pthread_exit(NULL); // Terminate the thread
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
    pthread_t thread_id;
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

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, &client_socket) != 0) {
            perror("Thread creation failed");
            continue;
        }

        // Close the thread when it's done
        pthread_detach(thread_id);

        // Limit the number of clients
        if (++client_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached. Rejecting new connections.\n");
            close(client_socket);
        }
    }

    // Close the server socket (not reached in this example)
    close(server_socket);

    return 0;
}
