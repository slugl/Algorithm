#include <stdio.h>
#define MAX 1005

int arr[MAX] = {0};
int lis[MAX] = {0};
int lds[MAX] = {0};

int main (void) {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
		lis[i] = 1;
		lds[i] = 1;
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && lis[j] + 1 > lis[i]) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	for (int i = num; i >= 1; i--) {
		for (int j = num; j > i; j--) {
			if (arr[i] > arr[j] && lds[j] + 1 > lds[i]) {
				lds[i] = lds[j] + 1;
			}
		}
	}

	int max = 1;
	for (int i = 1; i < num; i++) {
		if (lis[i] + lds[i] - 1 > max) {
			max = lis[i] + lds[i] - 1;
		}
	}
	
	printf("%d\n", max);

	return 0;
}