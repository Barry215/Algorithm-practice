# -*- coding:utf-8 -*-


class Solution:
    def getResult(self, n, m):
        l = [i for i in range(n)]
        p = 0
        while len(l) != 1:
            p = (p + m - 1) % len(l)
            l.pop(p)
        return l[0] + 1


print(Solution().getResult(5, 3))
