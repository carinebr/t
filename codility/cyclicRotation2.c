#include <stdio.h>
#include <stdlib.h>

static int solution(int * A, int N, int K);


int cyclicRotationLesson2()
{
    int A[]={3, 4, 5, 6, 7, 8, 9};
    solution(A, 7, 2);
    solution(A, 7, 0);
    solution(A, 7, 3);
    solution(A, 7, 4);
    solution(A, 7, 5);
    solution(A, 7, 14);
    solution(A, 7, 16);
    return 0;
}

static int solution(int* A, int N, int K)
{
    int i, pos;
    printf("================================================\n");
    int* tA = malloc(N*sizeof(int));

    if(N == 0 || K == 0)
        return 0;
    for (i = 0; i < N; i++)
        printf("%d ,", A[i]);
    printf("\n");
    for (i=0; i< N; i++)
    {
        pos = i + K;
        if (pos>=N)
            pos = pos%N;
        tA[pos] = A[i];
    }
    //tester
    for (i = 0; i < N; i++)
        printf("%d ,", tA[i]);
    printf("\n");
    free(tA);
    return 0;
}
