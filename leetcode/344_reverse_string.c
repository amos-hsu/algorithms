// 双指针
void reverseString(char* s, int sSize){
    int low = 0, high = sSize - 1;
    char ch;
    while (low < high) {
        ch = s[low];
        s[low++] = s[high];
        s[high--] = ch;
    }
}