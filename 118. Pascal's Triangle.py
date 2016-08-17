class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        res = [[1], [1, 1]]
        for col in range(3, numRows+1):
            tmp = []
            for i in range(0, col):
                if i == 0 or i == col - 1:
                    tmp.append(1)
                else:
                    tmp.append(res[col - 2][i - 1] + res[col - 2][i])
            res.append(tmp)
        return res