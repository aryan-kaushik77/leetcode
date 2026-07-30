void commonPrefix(char *a, char *b) {
    int i = 0;

    while (a[i] && b[i] && a[i] == b[i])
        i++;

    a[i] = '\0';      // Shorten a to the common prefix
}
char *longestCommonPrefix(char **strs, int strsSize) {

    if (strsSize == 0)
        return "";

    for (int i = 1; i < strsSize; i++) {
        commonPrefix(strs[0], strs[i]);

        if (strs[0][0] == '\0')
            return "";
    }

    return strs[0];
}