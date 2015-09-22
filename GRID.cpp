#include<iostream>
using namespace std;

 int A[1001][1001];
int memo[1001];

int N;
int validpos;
char hash;
int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{

			for(int j=0;j<1001;j++)
			{
				memo[j]=1;
			}

		validpos=0;
		cin>>N;
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<N;k++)
			{
				cin>>hash;
				if(hash=='#')
				{
					A[j][k]=0;
				}
				else
				{
					A[j][k]=1;
				}

			}

		}

		int total=0;int cansee=1;
		for(int j=N-1;j>=0;j--)
		{   cansee=1;


			for(int i=N-1;i>=0;i--)
			{
					int ith=0;
					if(A[j][i]==1 && cansee==1){cansee=1;}
					else{cansee=0;}
				if(A[j][i]==0){memo[i]=0;}

				if(memo[i]==1 && cansee==1){ith=1;}

				total=total+ith;
			}
		}

		cout<<total<<"\n";
	}
	return(0);
}
