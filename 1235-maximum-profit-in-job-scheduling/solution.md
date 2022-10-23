# 规划兼职工作

&emsp;&emsp;[源码](./solution.cpp)

&emsp;&emsp;这是一个动态规划问题.

&emsp;&emsp;首先, 把数据按照 $end[i]$ 升序排序. 令 $dp[i]$ 为截止到第 $i$ 个工作的最大利润.

&emsp;&emsp;把所有工作从前到后扫描一遍. 对于每一个工作, 只有干或者不干两种情况. 令 $lastindex$ 为**最后一个**使得 $end[lastindex] \leq start[i]$ 的工作的编号. 如果选择干这个工作, 那么 $dp[i]$ 应该等于 $dp[lastindex] + profit[i]$; 如果选择不干这个工作, 那么 $dp[i]$ 应该等于 $dp[i - 1]$.

&emsp;&emsp;在每次迭代中, 使得每个 $dp[i]$ 为两种情况的最大值即可.

&emsp;&emsp;在确定每个工作的 $dp[i]$ 的时候, 需要使用二分查找来确定它的 $lastindex$, 因此总体时间复杂度为 $O(nlogn)$.
