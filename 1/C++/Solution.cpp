#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool Find(int target, vector<vector<int> > array)
    {
        int row = (int)array.size();
        int col = (int)array[0].size();
        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < col)
        {
            if (target < array[i][j])
            {
                i--;
            }
            else if (target > array[i][j])
            {
                j++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int c[] = {3, 6, 9, 12, 15};

    //通过数组地址初始化
    vector<int> vec1(a, a + 5);
    vector<int> vec2(b, b + 5);
    vector<int> vec3(c, c + 5);

    vector<vector<int> > array;

    array.push_back(vec1);
    array.push_back(vec2);
    array.push_back(vec3);

    Solution solution;

    cout << boolalpha << solution.Find(8, array) << endl;

    return 0;
}