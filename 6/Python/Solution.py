# -*- coding:utf-8 -*-


class Solution:
    def check(self, threshold, x, y):
        return sum(map(int, str(x)+str(y))) <= threshold

    def movingCount(self, threshold, rows, cols):
        res = 0
        for i in range(rows):
            for j in range(cols):
                if self.check(threshold, i, j):
                    res += 1

        return res


print(Solution().movingCount(18, 50, 50))
