class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not len(nums):
            return
        red = []
        white = []
        blue = []

        for i in nums:
            if i == 0:
                red.append(i)
            elif i == 1:
                white.append(i)
            elif i == 2:
                blue.append(i)

        del nums[:]
        if len(red):
            nums.extend(red)
        if len(white):
            nums.extend(white)
        if len(blue):
            nums.extend(blue)