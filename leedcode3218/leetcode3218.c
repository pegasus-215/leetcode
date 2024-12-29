

#include <stdio.h>

void my_bubble_sort(int* data, int data_len)
{
	int swap;
	for (int i = data_len - 1; i >= 0; i--)
	{
		for (int j = data_len - 1; j >= 1; j--)
		{
			if (data[j] > data[j - 1])
			{
				swap = data[j];
				data[j] = data[j - 1];
				data[j - 1] = swap;
			}
		}
	}
}


int minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize) {
	my_bubble_sort(horizontalCut, horizontalCutSize);
	my_bubble_sort(verticalCut, verticalCutSize);

	//printf("horizontalCutSize:%d", horizontalCutSize);
	//printf("verticalCutSize:%d", verticalCutSize);

	int i = 0, j = 0, sum = 0;

	if (m == 1 && n == 1)
		return 0;
	else
	{
		while (1)
		{
			if (i < horizontalCutSize && j < verticalCutSize)
			{
				if (horizontalCut[i] > verticalCut[j])
				{
					sum += horizontalCut[i];

					for (int index = j; index < verticalCutSize; index++)
					{
						sum += verticalCut[index];
					}

					i++;
				}
				else
				{
					sum += verticalCut[j];

					for (int index = i; index < horizontalCutSize; index++)
					{
						sum += horizontalCut[index];
					}

					j++;
				}
			}
			else if (i == horizontalCutSize && j < verticalCutSize)
			{
				for (int index = j; index < verticalCutSize; index++)
				{
					sum += verticalCut[index];
				}
				break;
			}
			else if (i < horizontalCutSize && j == verticalCutSize)
			{
				for (int index = i; index < horizontalCutSize; index++)
				{
					sum += horizontalCut[index];
				}
				break;
			}
		}

		return sum;
	}
}

#define m 3
#define n 2

void main()
{
	int h[m] = { 1, 3 };
	int v[n] = { 5 };
	int sum = 0;

	sum = minimumCost(m, n, h, m - 1, v, n - 1);

	printf("sum:%d\n", sum);
}

//void main()
//{
//	int a[4] = {3, 1, 2, 4};
//	my_bubble_sort(a, 4);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("a[i]:%d\n", a[i]);
//	}
//}

