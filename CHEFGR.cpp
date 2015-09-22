#include<iostream>
#include<string>
using namespace std;



int N,M;
int A[102];


int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>N;
		cin>>M;
		int max;
		int fresh=0;
		for(int x=0;x<N;x++)
		{
			cin>>A[x];
			if(fresh==0){fresh=1;max=A[x];}
			else{if(A[x]>max){max=A[x];}}
		}

		int xtra=0;
		for(int x=0;x<N;x++)
		{
			xtra=xtra+(max-A[x]);

		}


		if(xtra==M||(M-xtra)%N==0){cout<<"Yes"<<"\n";	}
		else{cout<<"No"<<"\n";	}


	}
	return(0);
}


