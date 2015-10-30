#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
#include<queue>
using namespace std;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	map<int, queue<char *> > myMap;
	char *str;
	int temp[4];
	while (m --)
	{
		int cnt = 0;
		temp[0] = temp[1] = temp[2] = temp[3] = 0;
		str = (char*)malloc(sizeof(char) * (n+1));
		scanf("%s", str);
		for (int i = strlen(str) - 1; i >=0; i--)
		{
			switch (str[i])
			{
			case 'T': cnt += temp[2];
			case 'G': cnt += temp[1];
			case 'C': cnt += temp[0];
			}
			switch (str[i])
			{
			case 'A':temp[0]++; break;
			case 'C':temp[1]++; break;
			case 'G':temp[2]++; break;
			}
		}
		queue<char *> q = myMap[cnt];
		q.push(str);
	//	myMap[cnt] = q;
	}
	map<int, queue<char*> >::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		queue<char *> q = it->second;
		while (!q.empty())
		{
			printf("%s\n",q.front());
			q.pop();
		}
	}
	return 1;
}