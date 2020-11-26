// 判断第一个字符串能不能由第二个字符串的字母组成，第二个字符串的字母只能使用一次
// 方法一：
// 暴力解法，在第二个字符串遍历查找第一个字符串的字符，
// 如果找到，将匹配的字符删除（与末尾换位），找不到则退出
bool canConstruct(char * ransomNote, char * magazine){
    int magazineLen = strlen(magazine);
    bool flag = false;
    int i, j;
    for (i = 0; i < strlen(ransomNote); i++) {
        for(j = 0; j < magazineLen; j++) {
            if (ransomNote[i] == magazine[j]) {
                magazine[j] = magazine[magazineLen - 1];
                magazineLen -= 1;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            return false;
        }
        flag = false;
    }
    return true;
}

// 方法二：哈希法
bool canConstruct(char * ransomNote, char * magazine){
    int ransomNoteLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);
    if (ransomNoteLen > magazineLen) {
        return false;
    }
    int hash[26] = { 0 };  // 模拟哈希
    int i;
    for (i = 0; i < magazineLen; i++) {
        hash[magazine[i] - 'a'] += 1;
    }
    for (i = 0; i < ransomNoteLen; i++) {
        hash[ransomNote[i] - 'a'] -= 1;
        if (hash[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
