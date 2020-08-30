#include <stdio.h>

#define A_LEN 10

int temp[A_LEN];

void show(int a[])
{
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void margesort(int a[], int a_len, int left, int right)
{
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesort(a, mid, left, mid);
	margesort(a, a_len - mid, mid + 1, right);

	for (i = left; i <= mid; i++)
		temp[i] = a[i];
	for (i = mid + 1, j = right; i <= right; i++, j--)
		temp[i] = a[j];

	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (temp[L] <= temp[R])
		{
			a[i] = temp[L];
			L++;
		}
		else
		{
			a[i] = temp[R];
			R--;
		}
	}
}

int main(void)
{
	int a[] = { 7, 9, 6, 8, 0, 1, 5, 10, 3, 0 };

	int a_len = A_LEN;

	margesort(a, a_len, 0, a_len - 1);

	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);

	return 0;
}
