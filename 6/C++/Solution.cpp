#include <iostream>
#include <vector>
using namespace std;

//  两种情况
//  1、单行或者单列，一旦坐标数位之和小于k，之后的格子就走不到了，返回结果。  
//  2、只要行列数大于等于2，除了不符合要求的格子，其他的都能访问到

class Solution
{
  public:
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!bigger(threshold, i, j))
                    ++res;
                else if (rows == 1 || cols == 1)
                    return res;
        return res;
    }
    bool bigger(int num, int m, int n)
    {
        int sum = 0;
        while (m)
        {
            sum += m % 10;
            m /= 10;
        }
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return (num < sum);
    }
};

int main()
{
    Solution solution;
    cout << solution.movingCount(18, 50 ,50) << endl;

    return 0;
}