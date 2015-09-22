#include<iostream>
#include<string>
using namespace std;



int N,K;
int A[1002];
int dp[1002][1026];



int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		for(int x=0;x<1002;x++)
		{
			for(int y=0;y<1026;y++)
			{
				dp[x][y]=0;
			}
		}
		cin>>N;
		cin>>K;
		for(int x=0;x<N;x++)
		{
			cin>>A[x];
		}

		dp[0][0]=1;
		dp[0][0^A[0]]=1;

		for(int x=1;x<N;x++)
		{
			for(int state=0;state<1024;state++)
			{
				if(dp[x-1][state]==1)
				{
					dp[x][state]=1;
					dp[x][state^A[x]]=1;
				}
			}
		}

		int maxVal=-1;
		int nthVal;
		for(int state=0;state<1024;state++)
			{
				if(dp[N-1][state]==1)
				{
					nthVal=state^K;
					if(nthVal>maxVal)
					{
						maxVal=nthVal;
					}
				}
			}

			cout<<maxVal<<"\n";




	}
	return(0);
}
