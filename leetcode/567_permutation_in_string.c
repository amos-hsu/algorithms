bool checkInclusion(string t, string s) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;  // 统计t包含的字符，作为need表

        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {  // 窗口右边界包含在need表，则进入window，并根据windows和need对比是否需要更新valid
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (right - left >= t.size()) {  // 窗口长度大于t长度则需要缩写窗口
                // 在这里判断是否找到了合法的子串, valid数等于need表长度则表示匹配成功，返回true
                if (valid == need.size())
                    return true;
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {         // 窗口左边界包含在need表，需要弹出window，并且注意刷新valid信息
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        // 未找到符合条件的子串
        return false;
    }