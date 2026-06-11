int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int n=gasSize;
    int arr[n];
    
    int min_index=0;
    int target=0;
    arr[0]=gas[0]-cost[0];
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+gas[i]-cost[i];
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            printf("%d,%d\n",min,target);
            min_index=i;
            
        }
    target=min_index+1;
    }
    // printf("%d,%d",target,min);
    int fuel=0;
    for(int i=target;i<n;i++){
        fuel=fuel+gas[i]-cost[i];
    }
    for (int i=0;i<target;i++){
        fuel=fuel+gas[i]-cost[i];
    }
    
    if (fuel>=0){
        if (target==n){
            // printf("%d,%d",target,min);
            return 0;
            
        }
        else{
            // printf("%d,%d",target,min);
            return target;
            
        }
    }    
    return -1;
}




// qsn where something is added and subtracted at same index
// and we have to find a index for cirxle such that we can complete the circle with cost>=0