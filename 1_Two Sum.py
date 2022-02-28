class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        i = 0
        j = len(nums) - 1
        sortedNums = sorted(zip(nums, range(len(nums))))
        while i < j:
            if sortedNums[i][0] + sortedNums[j][0] == target:
                return [sortedNums[i][1], sortedNums[j][1]]
            elif sortedNums[i][0] + sortedNums[j][0] < target:
                i += 1
            elif sortedNums[i][0] + sortedNums[j][0] > target:
                j -= 1
        
         
        
               
