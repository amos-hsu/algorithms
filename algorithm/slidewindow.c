
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // 从这里开始，窗口右边界刷新为r，c是窗口右边界将移入窗口的字符
        char c = s[right];
        // 窗口右边界右移，左闭右开区间
        right++;
        // 进行窗口内数据的一系列更新, 可根据条件计算一系列窗口状态值，注意为左闭右开区间，窗口长度为 (r - l)
        // ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {   // 注意不要越界
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}

