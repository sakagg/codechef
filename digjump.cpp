#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

void printqueue(queue<int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}


int dfs(char str[], int pos[][100000], int sizes[])
{
	int visited[100100] = {0};
	int what = strlen(str) - 1;
	queue<int> q;
	int level = 1;
	int num, tmp;
	int size, found;
	q.push(0);
	q.push(-1);
	if(what==0)
		return 0;
	visited[0] = 1;
	while(q.size() > 1)
	{
		num = q.front();
		q.pop();
		if(num==-1)
		{
			level++;
			q.push(-1);
		}
		else
		{
			tmp = str[num] - '0';
			if(sizes[tmp])
			{
				found = 0;
				size = sizes[tmp];
				for(int i=0; i<size; i++)
					if(!visited[pos[tmp][i]])
					{
						q.push(pos[tmp][i]);
						if(pos[tmp][i] == what)
						{
							found = 1;
							break;
						}
						else
							visited[pos[tmp][i]] = 1;
					}
				if(found)
					break;
				sizes[tmp] = 0;
			}
//			tmp = num - (str[num-1] - '0');
			tmp = num - 1;
			if(num>0 && !visited[tmp])
			{
				q.push(tmp);
				if(tmp==what)
					break;
				else
					visited[tmp] = 1;
			}
//			tmp = num + (str[num+1] - '0');
			tmp = num + 1;
			if(num<what && !visited[tmp])
			{
				q.push(tmp);
				if(tmp==what)
					break;
				else
					visited[tmp] = 1;
			}
		}
//		printqueue(q);
	}

	return level;
}		

int main()
{
	char str[100100];		//USE BFS
	scanf("%s", str);
	int pos[10][100000];
	int sizes[10] = {0};
	int num;
	for(int i=0; str[i]; i++)
	{
		num = str[i] - '0';
		pos[num][sizes[num]++] = i;
	}
	printf("%d\n", dfs(str, pos, sizes));
	return 0;
}
