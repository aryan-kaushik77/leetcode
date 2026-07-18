#include <stdio.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n;
		scanf("%d", &n);

		long long prefix = 0;
		int ok = 1;

		for (int i = 1; i <= n; ++i) {
			long long x;
			scanf("%lld", &x);
			prefix += x;
			if (prefix < (long long)i * (i + 1) / 2) {
				ok = 0;
			}
		}

		printf(ok ? "YES\n" : "NO\n");
	}

	return 0;
}
// do it againnn