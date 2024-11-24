#include <stdio.h>
#include <stdlib.h>

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int maxD = 0;

    for (int i = 0; i < nums1Size; i++)
    {

        if (nums2Size - 1 - i > maxD)
        {

            for (int j = nums2Size - 1; j >= i; j--)
            {

                if (j - i > maxD)
                {

                    if (*(nums1 + i) <= *(nums2 + j))
                    {

                        if (j - i > maxD)
                        {

                            maxD = j - i;
                            break;
                        }
                    }
                }
                else
                    break;
            }
        }
        else
            return maxD;
    }

    return maxD;
}

int file2ptr(int* ptr, FILE* file_ptr)
{
    int num = 0;

    while (fscanf_s(file_ptr, "%d", ptr))
    {
        num++;

        if (getc(file_ptr == EOF))
            break;
    }

    return num;
}

void main()
{
    FILE * num1_ptr, *num2_ptr;
    int nums1Size, nums2Size, maxD;

    fopen_s(&num1_ptr, "C:\\Users\\Miste\\Documents\\MyCode\\C\\leetcode1855\\nums1.txt", "r+");
    fopen_s(&num2_ptr, "C:\\Users\\Miste\\Documents\\MyCode\\C\\leetcode1855\\nums2.txt", "r+");

    int* nums1 = (int*)malloc(100000 * 4);
    int* nums2 = (int*)malloc(100000 * 4);

    nums1Size = file2ptr(nums1, num1_ptr);
    nums2Size = file2ptr(nums2, num2_ptr);
    
    maxD = maxDistance(nums1, nums1Size, nums2, nums2Size);
    printf("maxD:%d.\n", maxD);
}