int GetCnt(int num)
{
    if (num >> 7 == 0) {
        return 1;
    }
    if (num >> 3 == 30) {
        return 4;
    }
    if (num >> 4 == 14) {
        return 3;
    }
    if (num >> 5 == 6) {
        return 2;
    }
    return 0;
}

bool CheckRearValid(int num)
{
    if (num >> 6 == 2) {
        return true;
    }
    return false;
}

bool validUtf8(int* data, int dataSize){
    int cnt = 0;
    for (int i = 0; i < dataSize; i++) {
        if (cnt == 0) {
            cnt = GetCnt(data[i]) - 1;
            // printf("cnt=%d\n", cnt);
        } else {
            if (!CheckRearValid(data[i])) {
                return false;
            }
            cnt--;
            if (cnt < 0) {
                return false;
            }
        }
    }
    if (cnt != 0) {
        return false;
    }
    return true;
}