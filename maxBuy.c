int maxProfit(int *prices, int pricesSize) {
    if(pricesSize == 0){return 0;}
    int minPrice = prices[0];
    int maxProfit = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        } else{
            int differencePrice = prices[i] - minPrice;
            if(differencePrice > maxProfit){
                maxProfit = differencePrice;
            } 
        }
    }
    return maxProfit;
}
