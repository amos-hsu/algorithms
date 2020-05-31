// 方法一：横向扫描，依次找第1个字符串和第N个字符串的公共前缀，即可得到最长公共前缀
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0 || strs == NULL) return "";  // 边界条件：字符数组为空
    char *ans = strs[0];
    int i, j, minLen = strlen(ans);
    for (i = 0; i < strsSize; i++) {               // 优化：找到最小长度，减少比较字数
        if (minLen > strlen(strs[i])) minLen = strlen(strs[i]);
    }
    int low = 0;
    int high = minLen;
    for (i = 0; i < strsSize; i++) {
        for (j = 0; j < minLen; j++) {
            if (ans[j] != strs[i][j]) {  // 迭代，找到第一个不相同的字符位置
                break;
            }
        }
        if (j == 0) return "";  // 截断字符串前，边界条件：公共前缀长度为0
        ans[j] = '\0';  // 截断 ans 字符串
    }
    return ans;
}

// 方法二：优化为二分查找
bool IsCommonPrefix(char **strs, int strsSize, int len)
{
    int i, j;
    for (i = 0; i < strsSize; i++)
        for (j = 0; j <= len && j < strlen(strs[0]); j++)
            if (strs[0][j] != strs[i][j])  // 迭代，找到第一个不相同的字符位置
                return false;          // 出现不相同字符，[0, len]非公共前缀
    return true;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0 || strs == NULL) return "";  // 边界条件：字符数组为空
    char *ans = strs[0];
    int i, j, minLen = strlen(ans);
    for (i = 0; i < strsSize; i++) {               // 找到最小长度，减少比较字数
        if (minLen > strlen(strs[i])) minLen = strlen(strs[i]);
    }
    int low = 0, high = minLen, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (IsCommonPrefix(strs, strsSize, mid) == true) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    ans[low] = '\0';
    return ans;
}