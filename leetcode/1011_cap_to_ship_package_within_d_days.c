bool CanFinish(int* weights, int weightsSize, int D, int cap)
{
    int i = 0;
    for (int d = 1; d <= D; d++) {
        int w = 0;
        while (cap - w >= weights[i]) {
            if (i == weightsSize - 1) return true;
            w += weights[i];
            i++;
        }
    }
    return false;
}

int shipWithinDays(int* weights, int weightsSize, int D){
    int left = weights[0];  // max of weights
    int right = 0;          // sum of weights
    for (int i = 0; i < weightsSize; i++) {
        right += weights[i];
        if (left < weights[i]) {
            left = weights[i];
        }
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        printf("l=%d r=%d m=%d\n", left, right, mid);
        if (CanFinish(weights, weightsSize, D, mid) == true) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}