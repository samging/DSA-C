int removeDuplicates(int* nums, int numsSize) {
    int uniqueIndex = 1;  
    
    for (int i = 1; i < numsSize; ++i) {
        
        if (nums[i] != nums[i - 1]) {
            nums[uniqueIndex] = nums[i];  
            uniqueIndex++;  
        }
    }
    
    return uniqueIndex;  
}
