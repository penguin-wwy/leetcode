class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) == 0 and len(b) == 0:
            return ""
        if len(a) == 0:
            return b
        if len(b) == 0:
            return a
        first = []
        second = []
        for i in range(1, len(a) + 1):
            first.append(1 if a[0 - i] == '1' else 0)
        for i in range(1, len(b) + 1):
            second.append((1 if b[0 - i] == '1' else 0))

        flag = 0
        if len(first) < len(second):
            first, second = second, first

        for i in range(0, len(first)):
            if i < len(second):
                sum = first[i] + second[i] + flag
                if sum == 3:
                    continue
                elif sum == 2:
                    first[i] = 0
                    flag = 1
                elif sum == 1:
                    first[i] = 1
                    flag = 0
            else:
                sum = first[i] + flag
                if sum == 2:
                    first[i] = 0
                elif sum == 1:
                    first[i] = 1
                    flag = 0
                    break
        if flag == 1:
            first.append(1)
        res = ""
        for i in range(1, len(first) + 1):
            res += "1" if first[0 - i] == 1 else "0"

        return res