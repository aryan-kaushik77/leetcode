#include <stdio.h>

static int max_erase_time(const char *s) {
	int best = 0;
	int current = 0;

	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '#') {
			++current;
			if (current > best) {
				best = current;
			}
		} 
        else {
			current = 0;
		}
	}

	return (best + 1) / 2;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}
	while (t--) {
		int n;
		char s[16];
		scanf("%d %s", &n, s);
		printf("%d\n", max_erase_time(s));
	}

	return 0;
}
