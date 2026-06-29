char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char *ans = (char *)malloc((n + 1) * sizeof(char));

    int depth = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            depth++;

            if (depth > 1)
                ans[j++] = '(';
        }
        else {
            depth--;

            if (depth > 0)
                ans[j++] = ')';
        }
    }

    ans[j] = '\0';
    return ans;
}