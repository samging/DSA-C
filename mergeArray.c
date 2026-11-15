int compare(const void *a, const void *b) {
    int num1 = *((int*)a);
    int num2 = *((int*)b);
    return num1 - num2;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int clip = 0 ,clip2 = 0;
    int count, count2;

    for (count = 0; count < nums1Size; ++count) {
        if (nums1[count] != 0) {
            ++clip;
        }
    }

    for(count2 = 0; count2 < nums2Size; ++count2){
        if(nums2[count2] != 0) {
            ++clip2;
        }
    }

    int *list = malloc(sizeof(int) * (m + n));  
    if (list == NULL) {
        perror("Error --- `list` Allocation failed ---");
        return;
    }
    
    int kk = 0;
    for(count = 0; count < m; ++count) {
        list[kk++] = nums1[count];
    }
    
    for(count2 = 0; count2 < n; ++count2) {
        list[kk++] = nums2[count2];
    }

    qsort(list, m + n, sizeof(int), compare);  

    for(int jj = 0; jj < m + n; ++jj){
        nums1[jj] = list[jj];  
    }

    free(list);
}
