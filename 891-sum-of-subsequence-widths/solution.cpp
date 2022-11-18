class Solution {
    inline static constexpr int MOD = (int)1e9 + 7;
    inline static int pow_2_n[100000];
    void init()
    {
        /*printf("init\n");*/
        pow_2_n[0] = 1;
        for (int i = 1; i < (int)1e5; ++i) {
            pow_2_n[i] = pow_2_n[i - 1] * 2 % MOD;
        }
    }
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        if (!pow_2_n[0]) {
            init();
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            /*
            ans += nums[i] * (pow_2_n[i] - 1);
            ans -= nums[i] * (pow_2_n[n - i - 1] - 1);
            */
            long long t = pow_2_n[i] - pow_2_n[n - i - 1];
            ans += t * nums[i] % MOD;
            ans %= MOD;
        }
        return ans;
    }
};

/*
3 * 3 + 2 * 1 - 1 * 3 - 2 * 1
*/

/*
[1,2,3]
[1] [2] [3] [1,2] [1,3] [2,3] [1,2,3]
0 0 0 1 2 1 2
*/

