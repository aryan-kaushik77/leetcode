char* slice(char *str, int start, int end) {
    int len = strlen(str);

    // Handle invalid indices
    if (start < 0) start = 0;
    if (end > len) end = len;
    if (start >= end) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int size = end - start;

    char *result = (char *)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < size; i++) {
        result[i] = str[start + i];
    }

    result[size] = '\0';

    return result;
}
char* largestOddNumber(char* num) {
    int max=-1;
    int len=strlen(num);
    for(int i=0;i<len;i++){
        int k=num[i]-'0';
        if(k%2!=0){
            max=i;
        }
    
    }
    return slice(num,0,max+1);
}
