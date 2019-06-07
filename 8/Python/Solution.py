# -*- coding:utf-8 -*-


class Solution:
    def nQueens(self, n):
        result = [0] * n
        results = []
        n_row = 0
        while n_row < n:
            pos = self.findLegalPosition(result, n_row, n)
            # print pos
            if pos is not None:
                result[n_row] = pos
                if n_row == n - 1:
                    results.append(result[:])

            if pos is None or n_row == n - 1:
                while 1:
                    n_row -= 1
                    if n_row < 0:
                        #print results
                        return len(results)

                    pos = self.findLegalPosition(
                        result, n_row, n, back_tracing=True)
                    if pos:
                        result[n_row] = pos
                        break
            n_row += 1

    def findLegalPosition(self, arr, n_row, n, back_tracing=False):
        start = 0
        if back_tracing:
            start = arr[n_row] + 1
        for col in range(start, n):
            ok = True
            for row in range(n_row):
                if arr[row] == col:
                    ok = False
                    break
                if n_row - row == abs(col - arr[row]):
                    ok = False
                    break
            if ok:
                return col
        return None


print(Solution().nQueens(8))
