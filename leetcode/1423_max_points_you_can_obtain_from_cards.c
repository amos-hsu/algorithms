int maxScore(int* cardPoints, int cardPointsSize, int k){
    int l = 0;
    int r = cardPointsSize - k;
    int sum = 0;
    int sumInWin = 0;
    int minSumInWin = INT_MAX;  // 长度cardPointsSize - k的窗口内的最小值
    for (int i = 0; i < cardPointsSize; i++) {
        sum += cardPoints[i];
        if (i < cardPointsSize - k) {
            sumInWin += cardPoints[i];
        }
    }
    // printf(">> sum=%d sumInWin=%d\n", sum, sumInWin);
    minSumInWin = sumInWin;
    while (r < cardPointsSize) {
        sumInWin = sumInWin - cardPoints[l] + cardPoints[r];
        minSumInWin = fmin(minSumInWin, sumInWin);
        // printf("sumInWin=%d minSumInWin=%d\n", sumInWin, minSumInWin);
        r++;
        l++;
    }
    return sum - minSumInWin;
}