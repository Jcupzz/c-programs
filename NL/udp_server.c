#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(void)

{

    int socket_desc; // NEW
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    int client_struct_length = sizeof(client_addr); // NEW

    // Clean buffers :
    memset(server_message,'\0', sizeof(server_message));
    memset(client_message,'\0', sizeof(client_message));

    // Create socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // NEW
    printf(" Socket created successfully \n ");

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
    // Bind to the set port and IP :
    bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf(" Done with binding \n ");
    
    // Listen for clients :
    printf(" \nListening for incoming connections ..... \n ");
    recvfrom(socket_desc, client_message, sizeof(client_message), 0,(struct sockaddr*)&client_addr,&client_struct_length);
    
    // Print message from client :  
    printf(" Msg from client : %s \n ", client_message);

    // Respond to client :
    strcpy(server_message, " This is the server's message . ");
    sendto(socket_desc, server_message, strlen(server_message), 0,(struct sockaddr*)&client_addr,&client_struct_length);

    // Closing the socket :
    close(socket_desc);


    return 0;
}