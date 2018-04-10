# -*- coding:utf-8 -*-

class Solution:
    def Find(self, target, array):
        for i in range(len(array)):
            if target in array[i]:
                return True
        return False


array = [[1, 2, 3, 4, 5], [2, 4, 6, 8, 10], [3, 6, 9, 12, 15]]
print(Solution().Find(10, array))

