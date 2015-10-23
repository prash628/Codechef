 #include<iostream>
#include<string>
using namespace std;



int N;
long long X[1001];
 int maxWins;

int main()
{

	int T;
	cin>>T;

	//T=1;


	for(int i=0;i<T;i++)
	{
	    cin>>N;
	    maxWins=0;
        string temp1,temp2;
        cin>>temp1;
        cin>>temp2;

        for(int j=0;j<N;j++)
        {
            int charx=temp1[j]-'A';
            int chary=temp2[j]-'A';
            if(charx==chary)
            {
                maxWins+=1;
            }
        }

        for(int j=0;j<=N;j++)
        {
            long long temp;
            cin>>temp;
            X[j]=temp;
        }


     if(maxWins==N)
     {
         cout<<X[N]<<"\n";
     }
     else
     {
        long long maxi=-1;
        for(int j=0;j<N;j++)
        {
            if(j>maxWins)
            {
                break;
            }
                long long temp=X[j];
                if(temp>maxi)
                {
                    maxi=temp;
                }
        }
        cout<<maxi<<"\n";
     }

	}
	return(0);
}
