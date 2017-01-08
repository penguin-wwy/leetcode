class Solution(object):
    cans = []
    res = []
    def backTracking(self, cur, now, target):
        if target == 0:
            l = copy.deepcopy(cur)
            self.res.append(l)
        else:
            for i in range(now, len(self.cans)):
                if self.cans[i] > target:
                    continue
                cur.append(self.cans[i])
                self.backTracking(cur, i, target - self.cans[i])
                cur.remove(self.cans[i])
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.res = []
        self.cans = copy.deepcopy(candidates)
        self.cans.sort()
        self.backTracking([], 0, target)
        return self.res