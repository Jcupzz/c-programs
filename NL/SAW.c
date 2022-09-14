#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int i = 1, noframes = 10, x, x1 = 10;
    printf("Number of frames is %d\n", noframes);
    while (noframes > 0)
    {
        printf("\nSending frame %d", i);
        srand(x1++);
        x = rand() % 10;
        if (x % 2 == 0)
        {
            printf("\nWaiting for 1 seconds");
            sleep(1);
            printf("\nMissing Acknowledgement %d\nSending frame %d", i, i);
        }
        printf("\nAcknowledgement received for frame %d\n", i);
        noframes -= 1;
        i++;
    }
    printf("\nEnd of stop and wait protocol");
    return (0);
}
