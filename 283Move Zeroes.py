class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = 0
        i = 0
        while i < len(nums):
            if 0 != nums[i]:
                if 0 == nums[zero]:
                    nums[i], nums[zero] = nums[zero], nums[i]
                    zero += 1
                i += 1
            elif 0 == nums[i] and 0 != nums[zero]:
                zero = i
            elif 0 == nums[i] and 0 == nums[zero]:
                i += 1