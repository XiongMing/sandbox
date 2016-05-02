#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_sort(int *a, int count)
{
	int i, j, tmp;
	for (i = 1; i < count; i++) {
		tmp = a[i];
		for (j = i; j > 0; j--) {
			if (a[j-1] > tmp) {
				a[j] = a[j-1];
			} else {
				break;
			}
		}
		a[j] = tmp;
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
	insert_sort(a, count);
	free(a);

	return 0;
}
