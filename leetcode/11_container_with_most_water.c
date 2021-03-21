int maxArea(int* height, int heightSize){
    int l = 0;
    int r = heightSize - 1;
    int max = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            max = fmax(max, fmin(height[l], height[r]) * (r - l));
            l++;
        } else {
            max = fmax(max, fmin(height[l], height[r]) * (r - l));
            r--;
        }
    }
    return max;
}
