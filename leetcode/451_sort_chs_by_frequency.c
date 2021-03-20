#define HASH_SIZE 126
typedef struct TagCS {
    char ch;
    int count;
} CharSet;

int Compare(const void *a, const void *b)
{
    CharSet *cs1 = (CharSet *)a;
    CharSet *cs2 = (CharSet *)b;
    return cs2->count - cs1->count;
}

char *frequencySort(char * s) {
    int i;
    int index = 0;
    CharSet chs[HASH_SIZE];
    memset(chs, 0, sizeof(CharSet) * HASH_SIZE);
    for (i = 0; i < strlen(s); i++) {
        chs[s[i]].ch = s[i];
        chs[s[i]].count++;
    }
    qsort(chs, HASH_SIZE, sizeof(CharSet), Compare);
    for (i = 0; i < HASH_SIZE; i++) {
        if (chs[i].count == 0) {
            continue;
        }
        for (int j = 0; j < chs[i].count; j++) {
            s[index++] = chs[i].ch;
        }
    }
    return s;
}
