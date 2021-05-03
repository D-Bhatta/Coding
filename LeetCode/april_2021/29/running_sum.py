class Solution:
    def runningSum(self, nums):
        rn_sum = [nums[0]]
        for i in range(1, len(nums)):
            rn_sum.append(rn_sum[-1] + nums[i])
        return rn_sum

s = Solution()

assert s.runningSum([1,2,3,4]) == [1,3,6,10]
assert s.runningSum([1,1,1,1,1]) == [1,2,3,4,5]
assert s.runningSum([3,1,2,10,1]) == [3,4,6,16,17]
