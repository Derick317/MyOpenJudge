#include<iostream>
using namespace std;

int main()
{
	int a[50001] = { 0 };  //动物所在连通分支编号
	int b[50001] = { 0 };  //动物在其连通分支内的角色
	int at[50001] = { 0 };  //表示一个动物所指向的动物
	int head[25001] = { 0 };  //每个连通分支打头的那只动物，即没有任何动物指向它，但它指向了某只动物
	int foot[25001] = { 0 };  //每个连通分支结尾的那只动物，即它没有指向任何动物，但某只动物指向它
	int num[25001] = { 0 };  //每个连通分支中现有动物数
	int m = 0, x = 0, y = 0, n = 0, k = 0;
	int lie = 0;  //谎话数
	int group = 0;  //表示现在已经用过多少个连通分支
	
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> m >> x >> y;
		if (x > n || y > n || (m == 2 && x == y))  //判断是不是第2种或第3种谎话
			lie++;
		else
		{
			if (a[x] == 0 && a[y] == 0)
			{
				group++;
				a[x] = a[y] = group;
				b[y] = 1;
				b[x] = m;
				at[x] = y;  //x→y
				head[group] = x;
				foot[group] = y;
				num[group] = 2;
			}
			else if (a[x] == 0 && a[y] != 0)
			{
				a[x] = a[y];
				b[x] = b[y] + m - 1;
				at[foot[a[y]]] = x;  //y所在连通分支结尾的动物→x
				foot[a[y]] = x;
				num[a[y]]++;
			}
			else if (a[x] != 0 && a[y] == 0)
			{
				a[y] = a[x];
				b[y] = b[x] + m + m - 2;
				at[foot[a[x]]] = y;  //x所在连通分支结尾的动物→y
				foot[a[x]] = y;
				num[a[x]]++;
			}
			else if (a[x] != 0 && a[y] != 0)  //a[x]和a[y]都出现过
			{
				if (m == 1)  //说法1（a[x]和a[y]同类）
				{
					if (a[x] == a[y])  //x和y位于同一个连通分支
					{
						if (b[x] % 3 != b[y] % 3)
							lie++;
					}
					else     //x和y位于不同连通分支
					{
						if (num[a[x]] < num[a[y]])  //x所在连通分支包含的动物数比y少，所以把x所在连通分支移到y去
						{
							a[0] = a[x];  //记录下x所在连通分支编号
							b[0] = b[x];
							at[foot[a[y]]] = head[a[0]];  //y所在连通分支结尾的动物→x原先所在连通分支打头的动物
							for (int j = head[a[0]]; j; j = at[j])
							{
								a[j] = a[y];
								b[j] = b[j] + b[y] % 3 - b[0] % 3 + 3;
							}
							foot[a[y]] = foot[a[0]];
							num[a[y]] = num[a[y]] + num[a[0]];
						}
						else  //y所在连通分支包含的动物数比x少，所以把y所在连通分支移到x去
						{
							a[0] = a[y];
							b[0] = b[y];
							at[foot[a[x]]] = head[a[0]];
							for (int j = head[a[0]]; j; j = at[j])
							{
								a[j] = a[x];
								b[j] = b[j] + b[x] % 3 - b[0] % 3 + 3;
							}
							foot[a[x]] = foot[a[0]];
							num[a[x]] = num[a[x]] + num[a[0]];
						}
					}
				}
				else  //说法2（a[x]和a[y]不同类）
				{
					if (a[x] == a[y])  //x和y位于同一个连通分支
					{
						if ((b[x] % 3 - b[y] % 3 != 1) && (b[x] % 3 - b[y] % 3 != -2))
							lie++;
					}
					else               //x和y位于不同连通分支
					{
						if (num[a[x]] < num[a[y]])  //x所在连通分支包含的动物数比y少，所以把x所在连通分支移到y去
						{
							a[0] = a[x];  //记录下x所在连通分支编号
							b[0] = b[x];
							at[foot[a[y]]] = head[a[0]];  //y所在连通分支结尾的动物→x原先所在连通分支打头的动物
							for (int j = head[a[0]]; j; j = at[j])
							{
								a[j] = a[y];
								b[j] = b[j] + b[y] % 3 - b[0] % 3 + 4;
							}
							foot[a[y]] = foot[a[0]];
							num[a[y]] = num[a[y]] + num[a[0]];
						}
						else  //y所在连通分支包含的动物数比x少，所以把y所在连通分支移到x去
						{
							a[0] = a[y];
							b[0] = b[y];
							at[foot[a[x]]] = head[a[0]];
							for (int j = head[a[0]]; j; j = at[j])
							{
								a[j] = a[x];
								b[j] = b[j] + b[x] % 3 - b[0] % 3 + 2;
							}
							foot[a[x]] = foot[a[0]];
							num[a[x]] = num[a[x]] + num[a[0]];
						}
					}
				}
			}
		}
	}
	cout << lie << endl;

	return 0;
}
