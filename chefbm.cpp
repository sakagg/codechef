#include <iostream>
#include<cstdio>
#include <vector>
#include <cstring>

using namespace std;

void print_array(int arr[], int size)
{
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
	cout<<endl;
}

int main()
{
	int n, m, p, size, tmp, ind;
	int arr[100010]={0};
	cin>>n>>m>>p;
	vector<int> a[n];
	int i, j;
	while(p--)
	{
		scanf("%d%d", &i, &j);
		a[i-1].push_back(j-1);
	}
	for(i=0; i<n; i++)
	{
		tmp = 0;
		memset(arr, 0, 100010*4);
		size = a[i].size();
		for(j=0; j<size; j++)
			arr[a[i][j]]++;
		tmp = arr[m-1] - arr[0] + m-1;
		for(j=0; j<size; j++)
		{
			ind = a[i][j];
			if((ind>0 && arr[ind-1] - arr[ind] > 1) || (ind<m-1 && arr[ind] - arr[ind+1] > 1))
			{
				tmp = -1;
				break;
			}
		}
//		print_array(arr, m+2);
//		for(j=0; j<size; j++)
//			arr[a[i][j]] = 0;
		cout<<tmp<<endl;
	}
	return 0;
}
