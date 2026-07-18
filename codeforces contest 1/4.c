#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int x = *(const int *)a;
	int y = *(const int *)b;
	if (x < y) {
		return -1;
	}
	if (x > y) {
		return 1;
	}
	return 0;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		long long *a = (long long *)malloc((n + 1) * sizeof(long long));
		int *b = (int *)malloc(m * sizeof(int));

		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}

		for (int i = 0; i < m; ++i) {
			scanf("%d", &b[i]);
		}

		qsort(b, m, sizeof(int), cmp_int);

		long long answer = 0;
		int previous = 0;

		for (int i = 0; i < m; ++i) {
			long long segment_sum = 0;
			for (int j = previous + 1; j <= b[i]; ++j) {
				segment_sum += a[j];
			}
			if (segment_sum < 0) {
				segment_sum = -segment_sum;
			}
			answer += segment_sum;
			previous = b[i];
		}

		for (int j = previous + 1; j <= n; ++j) {
			answer += a[j];
		}

		printf("%lld\n", answer);

		free(a);
		free(b);
	}

	return 0;
}
