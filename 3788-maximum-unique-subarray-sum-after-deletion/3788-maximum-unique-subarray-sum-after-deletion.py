import collections

class Solution(object):
  def maxSum(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    unique_nums = set(nums)
    
    positive_sum = sum(num for num in unique_nums if num > 0)
    
    if positive_sum > 0:
      return positive_sum
    else:
      return max(unique_nums)