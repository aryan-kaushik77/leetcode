#include <limits.h>

long reversing(long x){
    long z = 0;
    while (x >= 10){
        long y = x % 10;
        x = (x - y) / 10;
        z = z * 10 + y;
    }
    z = z * 10 + x;
    if (z > INT_MAX || z < INT_MIN) return 0;
    return z;
}

long reverse(long x){
    if (x == 0){
        return 0;
    } else if (x > 0){
        return reversing((long)x);
    } else {
        long lx = -(long)x;
        long y = reversing(lx);
        return (y == 0) ? 0 : -y;
    }
}