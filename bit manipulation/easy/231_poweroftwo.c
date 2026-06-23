bool isPowerOfTwo(int n) {
    if(n<=0){
        return false;
    }
    if(n==1){
        return true;
    }
    while(n>1){
        int x=n%2;
        n=n/2;
        if(x==1){
            return false;
        }
    }
    return true;
}