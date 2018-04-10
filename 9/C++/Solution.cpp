#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
	int getResult(int n, int m)
	{
		int last = 0;
		for (int i = 2; i <= n; i++)
		{
			last = (last + m) % i;
		}
		// 实际编号为(1~n)
		return last + 1;
	}
};

int main()
{
	Solution solution;
	cout << solution.getResult(5, 3) << endl;

	return 0;
}