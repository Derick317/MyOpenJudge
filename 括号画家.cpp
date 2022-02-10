//括号画家
#include<iostream>
#include<stack>
using namespace std;

bool beautiful(char* s);

int main()
{
	char s[10005];

	cin >> s;
	if (beautiful(s))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
bool beautiful(char* s)
{
	stack<char> chstack;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
			chstack.push(*s);
		else
		{
			if (chstack.empty())
				return 0;
			if (chstack.top() == '(' && *s != ')')
				return 0;
			if (chstack.top() == '[' && *s != ']')
				return 0;
			if (chstack.top() == '{' && *s != '}')
				return 0;
			chstack.pop();
		}
		s++;  //Bug: while 循环一定要记得更新循环参数，并且这句话一定要放对地方
	}
	return 1;
}
