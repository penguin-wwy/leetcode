class Solution(object):
    number = [None, None, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    def Cartesian_product(self, old, new):
        res = []
        for string in old:
            for char in new:
                res.append(string + char)
        return res
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        res = []
        num = []
        for i in digits:
            num.append(ord(i) - ord('0'))

        for c in self.number[num[0]]:
            res.append(c)
        for i in range(1, len(num)):
            res = self.Cartesian_product(res, self.number[num[i]])
        return res