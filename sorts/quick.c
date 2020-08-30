#include <stdio.h>

void show(int a[])
{
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void quicksort(int a[], int left, int right)
{

	int p;	//中央値
	int L = left, R = right;		//ループ中で変化するleft、right
	int temp;
	p = a[(left + right) / 2];

	while (1)
	{
		while (a[L] < p) L++; while (a[R] > p)
			R--;

		if (L >= R)
			break;

		temp = a[R];
		a[R] = a[L];
		a[L] = temp;

		L++;
		R--;
	}

	show(a);

	if (left < L - 1) quicksort(a, left, L - 1); if (right > R + 1)
		quicksort(a, R + 1, right);

}

int main(void)
{
	int a[] = { 7, 9, 6, 8, 0, 1, 5, 10, 3, 0};
	int a_len = 10;

	quicksort(a, 0, a_len - 1);

	return 0;
}
