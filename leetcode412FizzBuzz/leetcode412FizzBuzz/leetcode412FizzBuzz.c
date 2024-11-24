/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
    int n = 3;
    char** addr_ptr = (char**)malloc(n * (sizeof(char*)));

    int* returnSize = (int*)malloc(sizeof(int));

    *returnSize = 0;

    char temp[6];

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
        {
            *returnSize = *returnSize + (int)sizeof("FizzBuzz");
            *(addr_ptr + i) = (char*)malloc(9);
            strcpy_s(*(addr_ptr + i), 9, "FizzBuzz");
        }
        else if ((i + 1) % 3 == 0)
        {
            *returnSize = *returnSize + (int)sizeof("Fizz");
            *(addr_ptr + i) = (char*)malloc(5);
            strcpy_s(*(addr_ptr + i), 5, "Fizz");
        }
        else if ((i + 1) % 5 == 0)
        {
            *returnSize = *returnSize + (int)sizeof("Buzz");
            *(addr_ptr + i) = (char*)malloc(5);
            strcpy_s(*(addr_ptr + i), 5, "Buzz");
        }
        else
        {
            *returnSize = *returnSize + 6 + 1;
            *(addr_ptr + i) = malloc(6);
            sprintf_s(temp, 6, "%d", i + 1);
            strcpy_s(*(addr_ptr + i), 6, temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d:%s.\n", i + 1, *(addr_ptr + i));
    }

    printf("the total size is %d bytes.\n", *returnSize);
    
}