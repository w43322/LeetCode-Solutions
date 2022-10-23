class Solution {
private:
    long long check(vector<int>& nums, vector<int>& cost, int k)
    {
        long long res = 0;
        auto n = nums.size();
        for (int i = 0; i < n; ++i) {
            res += (long long)cost[i] * abs(nums[i] - k);
        }
        return res;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = 1, r = 1000000;
        int mid1, mid2;
        long long check1, check2;
        do {
            mid1 = l + (r - l) / 3;
            mid2 = l + 2 * (r - l) / 3;
            check1 = check(nums, cost, mid1);
            check2 = check(nums, cost, mid2);
            //cout << l << ' ' << mid1 << ' ' << mid2 << ' ' << r << '\n';
            //cout << "chk: " << check1 << ' ' << check2 << '\n';
            if (check1 < check2) {
                r = mid2;
            } else {
                l = mid1 + 1;
            }
        } while (mid1 < mid2);
        return check1;
    }
};
