# -*- coding:utf-8 -*-


class Solution:
    def Find(self, m, array):
        i = 0
        j = len(array) - 1
        res = 0
        while i < j:
            sum = array[i] + array[j]
            if sum > m:
                j -= 1
            elif sum < m:
                i += 1
            else:
                res += 1
                j -= 1
                i += 1

        return res


print(Solution().Find(14, [1,3,5,6,8,13,16]))
