#include<iostream>
using namespace std;
 
 
int N,M,K;
int main()
{
	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>N;
	    cin>>M;
		cin>>K;
		if((N==1 && M==1)||(N==2&&M==1)||(N==1&&M==2)){cout<<0<<"\n";}
		else if(N==1 || M==1){cout<<K<<"\n";}
		else
		{
			int res=K/2;
			int resinto2=res*2;
			if(resinto2==K){}
			else{res++;}
			cout<<res<<"\n";
		}
	}
	return(0);
}
 