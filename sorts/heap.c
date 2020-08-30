#include <stdio.h>

#define A_LEN 10

void show(int a[])
{
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapsort(int a[], int a_len)
{
	int childL, parent;

	while (a_len > 0)
	{
		printf("a_len = %d\n", a_len);
		parent = a_len - 1;

		while (parent >= 0)
		{
			childL = parent * 2 + 1;			//parentの左の子の添え字

			if (childL < a_len)
			{
				if (a[childL] < a[childL + 1] && childL + 1 < a_len)		//左右で大きいほうを左の子にする
					swap(&a[childL], &a[childL + 1]);

				if (a[childL] > a[parent])			//子が親より大きければ入れ替え
					swap(&a[childL], &a[parent]);
			}

			show(a);
			parent--;
		}
		swap(&a[0], &a[a_len - 1]);
		show(a);

		a_len--;
	}
}


int main(void)
{
	int a[A_LEN] = { 7, 9, 6, 8, 0, 1, 5, 10, 3, 2 };

	int a_len = A_LEN;

	show(a);

	heapsort(a, a_len);

	show(a);

	return 0;
}
