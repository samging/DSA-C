int _isHappy(int *array, int sizeArray);
int numberSlicer(int to_slice, int *sizeArray, int *slicedNumber) {
    int temp = to_slice;
    *sizeArray = 0;

    while (temp > 0) {
        temp /= 10;
        (*sizeArray)++;
    }

    for (int i = *sizeArray - 1; i >= 0; i--) {
        slicedNumber[i] = to_slice % 10;
        to_slice /= 10;
    }

    return _isHappy(slicedNumber, *sizeArray); 
}

int _isHappy(int *array, int sizeArray) {
    int result = 0;
    for (int i = 0; i < sizeArray; i++) {
        result += array[i] * array[i];
    }
    return result;
}

bool isHappy(int n) {
    int inputNumber = n;
    int _PC = 0; 
    int outputRes;
    int slicedNumber[10]; 
    int iArray;           

    printf("Checking if %d is a happy number...\n", inputNumber);

    while (_PC < 100) { 
        outputRes = numberSlicer(inputNumber, &iArray, slicedNumber);
        if (outputRes == 1) {
            printf("Number is happy.\n");
            return true;
            break;
        }
        inputNumber = outputRes; 
        _PC++;
    }

    if (_PC == 100) {
        printf("Number is not happy (loop detected).\n");
        return false;
    }

    return 0;
}
