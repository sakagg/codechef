#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n, w, tw, c, costs[2][100010];
	int size[2] = {0};
	int iters[2][2];		//[index%2][1/2]
	long long max[200020];
	int ind1, ind2;
	cin>>n;
	tw = 0;
	for(int i=0; i<n; i++)
	{
		scanf("%d%d", &w, &c);
		tw+=w;
		costs[w-1][size[w-1]++] = c;
	}
	sort(costs[0], costs[0]+size[0]);
	sort(costs[1], costs[1]+size[1]);
	max[0] = 0;
	iters[0][0] = size[0]-1;
	iters[0][1] = size[1]-1;
	iters[1][0] = size[0]-1;
	iters[1][1] = size[1]-1;
	if(size[0]>0)
	{
		max[1] = costs[0][size[0]-1];
		iters[1][0]--;
	}
	for(int i=2; i<=tw; i++)
	{
		ind1 = i%2;
		ind2 = !ind1;
		if(iters[ind2][0] > -1 && iters[ind1][1] > -1)
			if(max[i-1] + costs[0][iters[ind2][0]] > max[i-2] + costs[1][iters[ind1][1]])
			{
				max[i] = max[i-1] + costs[0][iters[ind2][0]];
				iters[ind1][0] = iters[ind2][0]-1;
			}
			else
			{
				max[i] = max[i-2] + costs[1][iters[ind1][1]];
				iters[ind1][1]--;
			}
		else if(iters[ind2][0] > -1)
		{
			max[i] = max[i-1] + costs[0][iters[ind2][0]];
			iters[ind1][0] = iters[ind2][0]-1;
		}
		else
		{
			max[i] = max[i-2] + costs[1][iters[ind1][1]];
			iters[ind1][1]--;
		}
//		printf("%lld %d %d\n", max[i], iters[ind1][0], iters[ind1][1]);
	}
	cout<<max[1];
	for(int i=2; i<=tw; i++)
		cout<<" "<<max[i];
	cout<<endl;
	return 0;
}
