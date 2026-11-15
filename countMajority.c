int countNumber(int number, int * numbers, int size){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(number == numbers[i]){
            counter++;
        }
    }
    return counter;
}

bool existNumber(int searchedNumber, int * numbers, int size){
    for(int k = 0; k < size; k++){
        if(searchedNumber == numbers[k]){
            return true;
        }
    }
    return false;
}

int majorityElement(int* nums, int numsSize) {
    int minOccurance = floor(numsSize / 2);
    int triedNumbers[numsSize];
    int t = 0;
    
    for(int i = 0; i < numsSize; i++){
        if(!existNumber(nums[i], triedNumbers, t)){
            //printf("%d\n", triedNumbers[0]);
            //printf("%d\n", triedNumbers[1]);
            //printf("%d\n", triedNumbers[2]);
            //printf("\n--------------");
            //printf("%d\n bez>>", *triedNumbers);
            
            int count = countNumber(nums[i], nums, numsSize);
            triedNumbers[t++] = nums[i];
            if(count > minOccurance){
                return nums[i];
            }
        }
    }
    return 0;
}
