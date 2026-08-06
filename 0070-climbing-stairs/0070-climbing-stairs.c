int climbStairs(int n) {
    int A[n+1];
    A[0]=1;
    A[1]=1;
    
    for (int i=2;i<n+1;i++){
        A[i]=A[i-1]+A[i-2];
    }
    return A[n];
}