#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct stu
{
	int m;
	int p;
	double rat;
};

bool cmp(stu a, stu b)
{
	return a.rat > b.rat;
}

int main()
{
	int n, t, m, p;
	cin>>n>>t;
	stu all[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &m, &p);
		all[i].m = m;
		all[i].p = p;
		all[i].rat = ((double)(m))/p;
	}
	sort(all, all+sizeof(stu)*n, &cmp);
}
