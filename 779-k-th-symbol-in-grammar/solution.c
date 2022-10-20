/*recursive, time O(n), space O(n)*/
int kthGrammar(int n, int k)
{
    if (n <= 2) {
        return k - 1;
    }
    int quarter_len = 1 << (n - 3);
    int half_len = quarter_len << 1;
    if (k > half_len) {
        if (k > half_len + quarter_len) {
            k -= half_len + quarter_len;
        } else {
            k -= quarter_len;
        }
    }
    return kthGrammar(n - 1, k);
}

/*popcount, time O(log k), space O(1)*/
int kthGrammar(int n, int k)
{
    return __builtin_popcount(k - 1) & 1;
}

/*while-loop & xor, time O(log k), space O(1)*/
int kthGrammar(int n, int k)
{
    int res = 0;
    --k;
    while (k) {
        res ^= k;
        k >>= 1;
    }
    return res & 1;
}
