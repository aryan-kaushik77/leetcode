int maxProfit(int* prices, int pricesSize) {
    int profit=0;
    int min=prices[0];
    int i=1;
    while(i<pricesSize){
        if(prices[i]<min){
            min=prices[i];
            i++;
        }
        else{
            profit=profit+(prices[i]-min);
            printf("%d",profit);
            min=prices[i];
            i++;
            
        }
    }
    return profit;
}