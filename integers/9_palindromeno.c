#include <limits.h>

int reversing(long x){
    long z = 0;
    while (x >= 10){
        int y = x % 10;
        x = (x - y) / 10;
        z = z * 10 + y;
    }
    z = z * 10 + x;
    if (z > INT_MAX || z < INT_MIN) return 0;
    return (int)z;
}

int reverse(int x){
    if (x == 0){
        return 0;
    } else if (x > 0){
        return reversing((long)x);
    } else {
        long lx = -(long)x;
        int y = reversing(lx);
        return (y == 0) ? 0 : -y;
    }
}
bool isPalindrome(int x) {
    long y=reverse(x);
    printf("%d",y);
    if(x<0){
        return false;
    }
    if(y==x){
        return true;
    }
    return false;
}