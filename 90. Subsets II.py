class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not len(nums):
            return [[]]

        self.res = [[]]
        self.dfs([], 0, nums)
        return self.res

    def dfs(self, path, pos, nums):
        if pos == len(nums):
            return

        for i in range(pos, len(nums)):
            path.append(nums[i])
            tmp = sorted(path)
            if not tmp in self.res:
                self.res.append(tmp)
                del tmp
            self.dfs(path, i + 1, nums)
            path.pop()