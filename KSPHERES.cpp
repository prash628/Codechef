#include<iostream>
#include<string>
using namespace std;



int N,M,C;
 int res;

 struct mystructwhat
 {
     long long lower,higher;
 }Rads[1001];


long long combo[1001];

 int realN;

 long long dp[1001][1001];

int main()
{

	int T;
	//cin>>T;
	T=1;

	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>M;
		cin>>C;

		for(int j=0;j<1001;j++)
        {
            Rads[j].lower=0;
            Rads[j].higher=0;
        }


        for(int j=0;j<N;j++)
        {
            long long temp1;
            cin>>temp1;
            Rads[temp1].higher+=1;

        }


         for(int j=0;j<M;j++)
        {
            long long temp2;
            cin>>temp2;
            Rads[temp2].lower+=1;
        }

        realN=0;

        for(int j=0;j<1001;j++)
        {
            if(Rads[j].lower!=0 && Rads[j].higher!=0)
            {
                long long combi=(Rads[j].lower*Rads[j].higher)%1000000007;
                combo[realN]=combi;
                realN++;

            }
        }


        for(int j=0;j<realN;j++)
        {
            for(int k=0;k<=C;k++)
            {
                dp[j][k]=0;
            }
        }

        for(int j=0;j<realN;j++)
        {
                int k=0;
                long long temp1,temp2;
                temp1=0;temp2=0;
                temp1=(combo[j])%1000000007;
                if(j!=0)
                {
                    temp2=dp[j-1][k];
                }
                dp[j][k]=(temp1+temp2)%1000000007;
        }


        for(int j=1;j<realN;j++)
        {
            for(int k=1;k<=C;k++)
            {
                long long temp1,temp2;
                temp1=0;temp2=0;
                temp1=(combo[j]*dp[j-1][k-1])%1000000007;
                temp2=dp[j-1][k];
                dp[j][k]=(temp1+temp2)%1000000007;
            }
        }

        for(int k=1;k<=C;k++)
        {
            cout<<dp[realN-1][k]<<" ";
        }

        //cout<<dp[realN-1][1]<<"\n";
	}
	return(0);
}
