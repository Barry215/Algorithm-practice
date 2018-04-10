# -*- coding:utf-8 -*-

import collections


class Solution:
    #利用字典类型记录出现次数
    def MoreThanHalfNum_Solution(self, numbers):
        tmp = collections.Counter(numbers)
        x = len(numbers) / 2
        for k, v in tmp.items():
            if v > x:
                return k
        return 0


print(Solution().MoreThanHalfNum_Solution([1,2,3,2,2,2,5,4,2]))
