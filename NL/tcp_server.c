#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(void)

{

    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];

    // Clean buffers :
    memset(server_message,'\0', sizeof(server_message));
    memset(client_message,'\0', sizeof(client_message));

    // Create socket:
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    printf(" Socket created successfully \n ");

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind to the set port and IP :
    bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf(" Done with binding \n ");
    
    // Listen for clients :
    listen(socket_desc, 1);
    printf(" \nListening for incoming connections ..... \n ");
    
    // Accept an incoming connection :
    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);

   // Receive client's message :
    recv(client_sock, client_message, sizeof(client_message), 0);
    printf(" Msg from client : %s \n ", client_message);
    
    // Respond to client :
    strcpy(server_message, " This is the server's message . ");
    send(client_sock, server_message, strlen(server_message), 0);

    // Closing the socket :
    close(client_sock);
    close(socket_desc);

    return 0;
}