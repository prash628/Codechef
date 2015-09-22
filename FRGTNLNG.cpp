#include<iostream>
#include<string>
using namespace std;



int N,K,L;
 int res;

 string words[100];
 int there[100];

 string temp;

int main()
{

	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>K;
		for(int x=0;x<N;x++)
        {
            cin>>words[x];
            there[x]=0;
        }
        for(int x=0;x<K;x++)
        {
            cin>>L;
            for(int y=0;y<L;y++)
            {
                cin>>temp;
                for(int z=0;z<N;z++)
                {
                    if(temp==words[z])
                    {
                        there[z]=1;
                    }
                }
            }
        }
        for(int x=0;x<N;x++)
        {
            if(there[x]==1)
            {
                cout<<"YES";
            }
            else
            {
                cout<<"NO";
            }
            if(x==N-1)
            {

            }
            else
            {
                cout<<" ";
            }
        }
		cout<<"\n";

	}

	return(0);
}
