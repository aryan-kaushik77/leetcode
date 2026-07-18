#include <stdio.h>
#include <stdlib.h>

static int query_ops(const int *pref, const char *bad, int l, int r) {
	int ops = pref[r] - pref[l - 1];
	if (l > 1 && bad[l] && bad[l - 1]) {
		++ops;
	}
	return ops;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);

		char *s = (char *)malloc((n + 2) * sizeof(char));
		int *pref0 = (int *)calloc(n + 1, sizeof(int));
		int *pref1 = (int *)calloc(n + 1, sizeof(int));
		char *bad0 = (char *)calloc(n + 1, sizeof(char));
		char *bad1 = (char *)calloc(n + 1, sizeof(char));

		scanf("%s", s + 1);

		for (int i = 1; i <= n; ++i) {
			bad0[i] = (char)(s[i] != ((i & 1) ? '0' : '1'));
			bad1[i] = (char)(s[i] != ((i & 1) ? '1' : '0'));

			pref0[i] = pref0[i - 1] + (bad0[i] && (i == 1 || !bad0[i - 1]));
			pref1[i] = pref1[i - 1] + (bad1[i] && (i == 1 || !bad1[i - 1]));
		}

		while (q--) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);

			int ops0 = query_ops(pref0, bad0, l, r);
			int ops1 = query_ops(pref1, bad1, l, r);

			printf((ops0 < ops1 ? ops0 : ops1) <= k ? "YES\n" : "NO\n");
		}

		free(s);
		free(pref0);
		free(pref1);
		free(bad0);
		free(bad1);
	}

	return 0;
}
