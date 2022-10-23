class Solution {
private:
    typedef pair<int, pair<int, int>> Job;
    vector<Job> jobs;
    vector<int> dp;
public:
    int jobScheduling(const vector<int> &starts, const vector<int> &ends, const vector<int> &profits) noexcept
    {
        int n = starts.size();
        jobs.clear();
        jobs.push_back({0, {0, 0}});
        dp.clear();
        dp.push_back(0);
        for (int i = 0; i < n; ++i) {
            jobs.push_back({ends[i], {starts[i], profits[i]}});
        }
        sort(jobs.begin(), jobs.end());
        /*for (int i = 0; i <= n; ++i) {
            cout << jobs[i].first << ' ';
        } cout << '\n';*/
        for (int i = 1; i <= n; ++i) {
            Job comp = {jobs[i].second.first, {INT_MAX, INT_MAX}};
            int previous_end_idx = upper_bound(jobs.begin(), jobs.end(), comp) - jobs.begin() - 1;
            dp.push_back(max(dp[i - 1], dp[previous_end_idx] + jobs[i].second.second));
            /*cout << comp.first << ' ' << previous_end_idx << '\n';
            cout << dp[i] << '\n';*/
        }
        return dp[n];
    }
};
