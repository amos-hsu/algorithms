char * intToRoman(int num){
    char *table[4][10] = {
        { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
        { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
        { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
        { "", "M", "MM", "MMM" }
    };
    if (num == 0) {
        return "0";
    }
    char *res = malloc(sizeof(char) * 16);
    int idx = 0;
    int pow = 1000;
    for (int i = 3; num != 0 && i >= 0; i--) {
        // printf(">> %d/1000=%d table[%d]=%s\n", num, num/pow, i, table[i][num/pow]);
        for (int j = 0; j < strlen(table[i][num / pow]); j++) {
            res[idx++] = table[i][num / pow][j];
        }
        num = num - num / pow * pow;
        pow = pow / 10;
    }
    res[idx] = '\0';
    return res;
}