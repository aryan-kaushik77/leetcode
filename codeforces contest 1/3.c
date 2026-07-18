#include <stdio.h>

static int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);

		int g = gcd(x, y);
		int ok = 1;

		for (int i = 1; i <= n; ++i) {
			int p;
			scanf("%d", &p);
			if (p % g != i % g) {
				ok = 0;
			}
		}

		printf(ok ? "YES\n" : "NO\n");
	}

	return 0;
}
