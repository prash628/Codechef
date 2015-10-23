 #include<iostream>
#include<string>
using namespace std;



int N;
 int res;

int A[100000];

int main()
{

	int T;
	cin>>T;
	long long sum;
	//T=1;
	long long x;

	for(int i=0;i<T;i++)
	{
	    sum=0;
	    int starter;
		cin>>N;
		for(int j=0;j<N;j++)
        {
            cin>>A[j];
        }

        starter=0;
        int j;
        for(j=1;j<N;j++)
        {
            if(A[j]<A[j-1])
            {
                x=j-starter;
                sum=sum+((x*(x+1))/2);
                starter=j;
            }
        }
        x=(long long)(j-starter);
        sum+=((x*(x+1))/2);
		cout<<sum<<"\n";
	}
	return(0);
}
