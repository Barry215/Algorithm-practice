#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    //排序方法
    int MoreThanHalfNum_Solution_1(vector<int> numbers)
    {
        int size = numbers.size() / 2;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i + size < numbers.size(); i++)
        {
            if (numbers[i] == numbers[i + size])
            {
                return numbers[i];
            }
        }
        return 0;
    }

    //抵消法，如果存在此数，则必须满足其个数>其他数之和
    int MoreThanHalfNum_Solution_2(vector<int> numbers)
    {
        int n = numbers.size();
        if (n == 0)
        {
            return 0;
        }
        int num = numbers[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (numbers[i] == num)
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count == 0)
            {
                num = numbers[i];
                count = 1;
            }
        }

        // 验证
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] == num)
            {
                count++;
            }
        }
        if (count * 2 > n)
        {
            return num;
        }
        return 0;
    }
};

int main()
{
    int array[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    vector<int> vector(array, array + 9);

    Solution solution;

    cout << solution.MoreThanHalfNum_Solution_1(vector) << endl;
    cout << solution.MoreThanHalfNum_Solution_2(vector) << endl;

    return 0;
}