#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
	int jumpFloor(int number)
	{
		int plans[number];
		plans[1] = 1;
		plans[2] = 2;
		for (int cur = 3; cur <= number; cur++)
		{
			plans[cur] = plans[cur - 1] + plans[cur - 2];
		}
		return plans[number];
	}
};

int main()
{
	Solution solution;
	cout << solution.jumpFloor(3) << endl;

	return 0;
}