#include<climits>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int dist[100100];

struct edge
{
	int end;
	int wt;
};

struct minDist
{
	bool operator()(const edge &a, const edge &b)
	{
		return a.wt>b.wt;
	}
};

int main()
{
// Uncomment to use TestCases
/*	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, m, start, end, ind;
	edge e, tmp;
	vector<int> front[100100];
	vector<int> back[100100];
	int locked[100100] = {0};
	memset(dist, 127, 100100*sizeof(int));
	scanf("%d%d", &n, &m);
	while(m--)
	{
		scanf("%d%d", &start, &end);
		start--;
		end--;
		front[start].push_back(end);
		back[end].push_back(start);
	}
/*	for(int i=0; i<n; i++)
	{
		for(int j=0; j<front[i].size(); j++)
			cout<<front[i][j]+1<<" ";
		for(int j=0; j<back[i].size(); j++)
			cout<<" "<<back[i][j]+1;
		cout<<endl;
	}
*/	n--;		//Dont Forget
	dist[0] = 0;
	e.end = 0;
	e.wt = 0;
	priority_queue<edge, vector<edge>, minDist> q;		//MinHeap
	q.push(e);
	locked[0] = 0;
	while(!locked[n] && q.size())
	{
		start = q.top().end;
//		cout<<start+1<<" "<<dist[start]<<endl;
		q.pop();
		if(locked[start])
			continue;
		locked[start] = 1;
		for(int i=front[start].size()-1; i>-1; i--)
		{
			ind = front[start][i];
			if(dist[ind] > dist[start])
			{
				dist[ind] = dist[start];
				tmp.end = ind;
				tmp.wt = dist[ind];
//				cout<<"Pushing: "<<ind<<endl;
				q.push(tmp);
			}
		}
		for(int i=back[start].size()-1; i>-1; i--)
		{
			ind = back[start][i];
			if(dist[ind] > (dist[start]+1))
			{
				dist[ind] = dist[start]+1;
				tmp.end = ind;
				tmp.wt = dist[ind];
//				cout<<"Pushing: "<<ind<<endl;
				q.push(tmp);
			}
		}
	}
	if(locked[n])
		printf("%d\n", dist[n]);
	else
		printf("-1\n");
	return 0;
}

