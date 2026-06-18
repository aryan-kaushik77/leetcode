int maxProfit(int* prices, int pricesSize) {
    int profit=0;
    int A[pricesSize];
    A[0]=0;
    int min=prices[0];
    for (int i=1;i<pricesSize;i++){
        if(prices[i]<min){
            min=prices[i];
            profit=0;
        }
        else{
            profit=prices[i]-min;
        }
        if (A[i-1]>profit){
            A[i]=A[i-1];
        }
        else{
            A[i]=profit;
        }
    }
    return A[pricesSize-1];
}