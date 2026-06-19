bool lemonadeChange(int* bills, int billsSize) {
    int five=0;
    int ten=0;
    int twenty=0;
    for (int i=0;i<billsSize;i++){
        if (bills[i]==5){
            five++;
        }
        else if (bills[i]==10){
            if (five==0){
                return false;
            }
            ten++;
            five--;
        }
        else{
            if (five>=1 && ten>=1){
                twenty++;
                ten--;
                five--;
            }
            else if(five>=3){
                twenty++;
                five=five-3;
            }
            else{
                return false;
            }
        }

        }
    return true;
}