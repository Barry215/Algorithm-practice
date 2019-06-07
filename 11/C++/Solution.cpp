#include <iostream>
#include <cmath>
using namespace std;
int m, n, ans;
//欧几里得算法
//两个正整数a和b（a>b），它们的最大公约数等于a除以b的余数c和b之间的最大公约数。
int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}
int main()
{
	cin >> n >> m;
	//最大公约数和最小公倍数的乘积就是原两个数的积
	for (int i = 1; i <= sqrt(m * n); i++)
	{
		//判断另外一个数是不是和i的最大公约数是n
		if ((n * m) % i == 0 && gcd(i, (n * m) / i) == n)
			ans++;
	}
	cout << ans * 2; //最后乘以二是因为只遍历了一半
	return 0;
}