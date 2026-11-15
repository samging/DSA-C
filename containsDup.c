bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize < 2 || k <= 0) return false;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j <= i + k && j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    
    return false;
}
