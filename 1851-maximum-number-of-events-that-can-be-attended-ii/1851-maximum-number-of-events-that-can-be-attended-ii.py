class Solution(object):
    def maxValue(self, events, k):
        """
        :type events: List[List[int]]
        :type k: int
        :rtype: int
        """
        events.sort(key=lambda x: x[1])
        n = len(events)

        # Extract end days to binary search non-overlapping events
        end_days = [event[1] for event in events]

        # Initialize DP table
        dp = [[0] * (k + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            start_i, end_i, value_i = events[i - 1]
            # Find the last event that ends before this one starts
            prev = bisect_right(end_days, start_i - 1)
            for j in range(1, k + 1):
                # Option 1: skip current event
                # Option 2: take current event + max value from previous non-overlapping
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value_i)

        return dp[n][k]