#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
	int Find(int m, vector<int> vec)
	{
		int i = 0;
		int j = vec.size() - 1;
		int res = 0;
		while (i < j)
		{
			int sum = vec[i] + vec[j];
			if (sum > m)
			{
				j--;
			}
			else if (sum < m)
			{
				i++;
			}
			else
			{
				res++;
				i++;
				j--;
			}
		}
		return res;
	}
};

int main()
{
	int array[] = {1, 3, 5, 6, 8, 13, 16};
	vector<int> vector(array, array + 7);
	Solution solution;
	cout << solution.Find(14, vector) << endl;

	return 0;
}