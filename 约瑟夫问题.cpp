// OpenJudge 2746
// 约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。
//就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

struct monkey
{
	int id;
	monkey* next;
};

monkey* head;

monkey* creat(int);  //建立一个函数，以创建含 num 个节点的循环链表，返回链表头指针
int main()
{
	int n, m;
	monkey* king = NULL;  //用来标记猴王的地址
	monkey* preking = NULL;  //用来标记king前面那个猴子


	for (cin >> n >> m; n > 0 || m > 0; cin >> n >> m)
	{
		preking = king = creat(n);
		for (int i = 1; i <= n - 1; i++)
			preking = preking->next;

		while (king->next != king)
		{
			for (int i = 1; i <= m - 1; i++)  //往后数 m 个猴子
			{
				king = king->next;
				preking = preking->next;
			}
			preking->next = king->next;
			delete king;
			king = preking->next;  //删除 king 所指猴子
		}


		cout << king->id << endl;
	}
	

	/*for (int i = 1; i <= n + 5; i++)
	{
		cout << king->id<<endl;
		king = king->next;
	}*/
	return 0;
}

monkey* creat(int num)
{
	head = NULL;
	monkey* p = NULL, *q = NULL;
	for (int i = 1; i <= num; i++)
	{
		p = new monkey;
		p->id = i;
		if (head == NULL)  //说明链表为空
			head = p;
		else
			q->next = p;
		q = p;
	}
	q->next = head;
	return head;
}
