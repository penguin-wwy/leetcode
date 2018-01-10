class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == '' or s == ' ':
            return s.strip()
        s_list = s.split(' ')
        ret = ''
        for ss in s_list:
            if ss == '':
                continue
            ret = ' ' + ss + ret
        return ret.strip()