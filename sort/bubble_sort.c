#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *a, int count)
{
	int i, j, min, tmp;
	for (i = 0; i < count; i++) {
		min = i;
		for (j = i + 1; j < count; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}

		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
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
	int *a;

	srand(time(NULL));
	count = 200000;
	a = new_array(count);
	bubble_sort(a, count);
	free(a);

	return 0;
}
