int atMostNGivenDigitSet(const char **digits, int m, int n)
{
    char num[10], eq[10] = {0}, lt[10] = {0};
    int free[10], leq[10];

    for (int i = 0; i < m; ++i) {
        int dig = *digits[i] - '0';
        eq[dig] = 1;
        for (int j = dig + 1; j <= 9; ++j) {
            ++lt[j];
        }
    }

    char num_digits_cnt = 0;
    while (n) {
        num[num_digits_cnt++] = n % 10;
        n /= 10;
    }

    free[0] = m;
    for (int i = 1; i < num_digits_cnt - 1; ++i) {
        free[i] = m * free[i - 1];
    }

    leq[0] = lt[num[0]] + eq[num[0]];
    for (int i = 1; i < num_digits_cnt; ++i) {
        leq[i] = lt[num[i]] * free[i - 1] + eq[num[i]] * leq[i - 1];
    }

    int res = leq[num_digits_cnt - 1];
    for (int i = 0; i < num_digits_cnt - 1; ++i) {
        res += free[i];
    }

    /*for (int i = 0; i <= 9; ++i) {
        printf("lt[%d] = %hhd, eq[%d] = %hhd\n", i, lt[i], i, eq[i]);
    }*/

    return res;
}
