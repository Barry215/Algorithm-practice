# -*- coding:utf-8 -*-

class Solution:
    #动态规划方法，每次计算一小块最优解，计算下一个时，把之前的解当做一个整体再进行计算
    def FindGreatestSumOfSubArray(self, array):
        res = max(array)
        temp = array[0]
        for i in array:
            temp = max(temp + i, i)
            res = max(res, temp)
            
        return res

print(Solution().FindGreatestSumOfSubArray([1, -2, 3, 10, -4, 7, 2, -5]))

