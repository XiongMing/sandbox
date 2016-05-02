#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int *a, int low, int high, int *tmp)
{
	int i, j, k;
	int mid;
	if (low < high) {
		mid = (low + high)/2;
		merge_sort(a, low, mid, tmp);
		merge_sort(a, mid + 1, high, tmp);

		// merge array
		i = low, j = mid + 1, k = 0;
		while (i <= mid && j <= high) {
			if (a[i] <= a[j]) {
				tmp[k++] = a[i++];
			} else {
				tmp[k++] = a[j++];
			}
		}
		while (i <= mid)
			tmp[k++] = a[i++];
		while (j <= high)
			tmp[k++] = a[j++];
		for (i = 0; i < k; i++) {
			a[low + i] = tmp[i];
		}
	}
}

void print_array(int *a, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int *new_array(int count)
{
	int *a = (int*)malloc(count*sizeof(int));
	while (--count >= 0) {
		a[count] = rand();
	}
	return a;
}

int main(int argc, char *argv[])
{
	int count;
	int *a, *tmp;

	srand(time(NULL));
	count = 200000;
	a = new_array(count);
	tmp = new_array(count);
	merge_sort(a, 0, count-1, tmp);
	free(a);

	return 0;
}
