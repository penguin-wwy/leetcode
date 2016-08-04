class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s1 = []
        self.s2 = []
        
    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.s1.append(x)
        if len(self.s2) == 0:
            self.s2.append(x)
        elif self.s2[-1] >= x:
            self.s2.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if self.s1[-1] == self.s2[-1]:
            self.s2 = self.s2[:-1]
        self.s1 = self.s1[:-1]
        

    def top(self):
        """
        :rtype: int
        """
        return self.s1[-1]
        
    def getMin(self):
        """
        :rtype: int
        """
        if len(self.s2) == 0:
            return []
        return self.s2[-1]