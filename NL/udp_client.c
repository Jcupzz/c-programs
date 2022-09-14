#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(void)

{

    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    int server_struct_length = sizeof(server_addr);  // NEW
    
    // Clean buffers :
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    // Create socket :
    
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // NEW
   
    printf(" Socket created successfully \n ");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
    //  THERE IS NO CONNECT FUCTION FROM TCP IN UDP.IT IS A MAJOR DIFFERENCE!

    // Get input from the user :
    printf(" Enter message : ");
    gets(client_message);

    // Send the message to server :
    sendto(socket_desc, client_message, strlen(client_message), 0,(struct sockaddr*)&server_addr,server_struct_length); // NEW
   
 
    // Receive the server's response :
    recvfrom(socket_desc, server_message, sizeof(server_message), 0,(struct sockaddr*)&server_addr,&server_struct_length);
    printf(" Server's response : %s \n ", server_message);

    close(socket_desc);
    return 0;
}
