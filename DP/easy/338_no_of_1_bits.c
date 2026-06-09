/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int *ans = malloc((n + 1) * sizeof(int));
    if (!ans) return NULL;

    ans[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            ans[i] = ans[i / 2];
        } else {
            ans[i] = ans[i - 1] + 1;
        }
    }

    *returnSize = n + 1;
    return ans;
}

