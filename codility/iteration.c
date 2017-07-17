#include <stdio.h>
#include<limits.h>

static int solution(unsigned int in_n);


int iteration()
{
    solution(17);
    solution(1);
    solution(1041);
    solution(1141);
    solution(1241);
    solution(1341);
    solution(1441);
    solution(0);
    solution(INT_MAX - 2);
    solution(INT_MAX);
    return 0;
}

static int solution(unsigned int in_n)
{
    int pos, temp = 0, consecutiveZeros=0, flagOpen = 0;
    printf("interation function\n");
    if (in_n > INT_MAX)
        return 0;
    printf("================================================\n");
    //loop over the in_n
    for (pos = 0 ; pos != 16 ; pos++)
    {
        if (in_n & (1 << pos))
        {
            printf("1");
            if (temp)
            {
                if (temp > consecutiveZeros)
                    consecutiveZeros=temp;
                temp = 0;
            }
            else
                flagOpen = 1;
        }
        else //0
        {
            printf("0");
            if (flagOpen)
                temp++;
        }
    }

    printf("\ninput : %d \n", in_n);
    printf("consecutive zeros: %d\n", consecutiveZeros);
    return 0;
}
