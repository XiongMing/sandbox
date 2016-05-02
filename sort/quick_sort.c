#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *a, int low, int high)
{
	int first, last, key;
	if (low < high) {
		key = a[low];
		first = low;
		last = high;
		while (first < last) {
			while (first < last && a[last] > key) last--;
			a[first] = a[last];
			while (first < last && a[first] < key) first++;
			a[last] = a[first];
		}
		a[first] = key;

		quick_sort(a, low, first -1);
		quick_sort(a, first + 1, high);
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
	while (--count > 0) {
		a[count] = rand();
	}
	return a;
}

int main(int argc, char *argv[])
{
	int count;
	int *a;

	srand(time(NULL));
	count = 200000;
	a = new_array(count);
	quick_sort(a, 0, count-1);
	free(a);

	return 0;
}
