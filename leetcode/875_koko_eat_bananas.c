int minEatingSpeed(int* piles, int pilesSize, int H){
    int l = 1;
    int r = piles[0];
    for (int i = 0; i < pilesSize; i++) {
        if (r < piles[i]) {
        r = piles[i];
        }
    }
    while (l < r) {
        int m = l + (r - l) / 2;
        // printf("l=%d r=%d m=%d\n", l, r, m);
        int remainDay = H;
        for (int i = 0; i < pilesSize; i++) {
            remainDay -= piles[i] / m + ((piles[i] % m > 0) ? 1 : 0);
            // printf("T=%d\n", piles[i] / m + ((piles[i] % m > 0) ? 1 : 0));
        }
        bool canFinish = (remainDay >= 0) ? true : false;
        if (canFinish == true) {
            r = m;
        } else {
            l = m + 1;
        }
        // printf(">> l=%d r=%d\n", l, r);
    }
    return l;
}
