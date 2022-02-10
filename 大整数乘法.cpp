#include<iostream>
using namespace std;

int main()
{
	char a[205];
	char b[205];
	int aa[205];
	int bb[205];
	int m[205][205];
	int lentha = 0, lenthb = 0;
	int result[405];
	int temp = 0;
	int re = 0;

	cin >> a >> b;

	for (lentha = 0; a[lentha] != '\0'; lentha++)
	{
		aa[lentha] = a[lentha] - '0';
	}
	for (lenthb = 0; b[lenthb] != '\0'; lenthb++)
	{
		bb[lenthb] = b[lenthb] - '0';
	}
	for (int i = lentha - 1; i >= 0; i--)
	{
		for (int j = lenthb - 1; j >= 0; j--)
			m[i][j] = aa[lentha - 1 - i] * bb[lenthb - 1 - j];  //Bug: 注意这里m[i][j]应该反过来记录，因为输入从高位输入，但m从个位开始
	}
	for (int s = 0; s <= lentha + lenthb - 2; s++)  //Bug: 注意是"lentha + lenthb - 2"而不是"lentha + lenthb - 1". 注意循环的结束边界条件
	{
		re = 0;

		for (int t = 0; t <= s; t++)
		{
			if ((t <= lentha - 1) && (s - t <= lenthb - 1))  //Bug: 检查边界条件
				re = re + m[t][s - t];
		}
		re = re + temp;
		temp = (re - re % 10) / 10;
		result[s] = re % 10;
	}
	if (temp != 0) cout << temp;  //Bug: 首位有进位
	for (int k = lentha + lenthb - 2; k >= 0; k--)
		cout << result[k];

	return 0;
}
