int findNumber(int toFind, int *nums, int numsSize, int startIndex){
    for(int i = startIndex; i < numsSize; i++){
        if(nums[i] == toFind){
            return i;
        }
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  
    for(int i = 0; i < numsSize; i++){
            int secIndex = findNumber(target - nums[i], nums, numsSize, i+1);
            if(secIndex != -1){
                int *list =  (int*)malloc(sizeof(int) * 2);
                *returnSize = 2;
                list[0] = i;
                list[1] = secIndex;
                return list;
        }

    }
    *returnSize = 0;
    return NULL;
}

