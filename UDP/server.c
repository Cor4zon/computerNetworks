/************* UDP SERVER CODE *******************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>

#define symbols "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void num_base(int num, int base){
    if (num)
    {
        int tmp = num % base;
        num = num / base;
        num_base(num, base);
        printf("%c", symbols[tmp]);
    }
}

void calc_results(int num){
    printf("\nBinary:");
    num_base(num, 2);
    printf("\nOctal:");
    num_base(num, 8);
    printf("\nDecimal:");
    printf("%d", num);
    printf("\nHexademical:");
    num_base(num, 16);
    printf("\n 19nd variant: ");
    num_base(num, 19);
}

int main() {
    int udpSocket, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
    int i;

    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    addr_size = sizeof(serverStorage);


    nBytes = recvfrom(udpSocket, buffer, 1024, 0, (struct sockaddr *) &serverStorage, &addr_size);
    printf("Number received from client: %s\n",buffer);
    calc_results(atoi(buffer));

    close(udpSocket);
    return 0;
}