#include <stdio.h>
#define MAX 100005

int main (void) {
	int list[MAX];
	int num;
	scanf("%d", &num);

	for (int i=1; i<=num; i++) {
		scanf("%d", &list[i]);
	}

	int max[MAX] = {0};
	max[num] = list[num];
	int temp = max[num];
	for(int i=num-1; i>=1; i--) {
		if (max[i+1] < 0) {
			max[i] = list[i];
		}
		else {
			max[i] = list[i] + max[i + 1];
		}
		if (max[i] > temp) {
			temp = max[i];
		}
	}

	printf("%d\n", temp);
	return 0;
}