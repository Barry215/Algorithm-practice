# -*- coding:utf-8 -*-


class Solution:
    def jumpFloor(self, number):
        a = 1
        b = 1
        while number > 0:
            a, b = b, a + b
            number -= 1
        return a


print(Solution().jumpFloor(3))
