#include<iostream>
#include<string>
#include<queue>
#include <malloc.h>
#include<set>
#include<algorithm>
using namespace std;


int N;
 int res;int temp;

multiset<int> mymultiset;
int main()
{
std::ios::sync_with_stdio(false);

	int T;
	cin>>T;
	//T=1;

	for(int i=0;i<T;i++)
	{
	    mymultiset.clear();
		cin>>N;


		for(int x=0;x<N;x++)
        {
            cin>>temp;
            if(mymultiset.empty()==false)
            {
                //Elements are in there-now u have to find the upper bound-i.e. elements>=that num
                multiset<int>::iterator it;
                it=mymultiset.upper_bound(temp);
                if(it==mymultiset.end())
                {
                    mymultiset.insert(temp);
                }
                else
                {
                    mymultiset.erase(it);
                    mymultiset.insert(temp);
                }
            }
            else
            {
                mymultiset.insert(temp);
            }
        }
        int counter=0;

        for(multiset<int>::iterator it=mymultiset.begin();it!=mymultiset.end();it++)
        {
            counter++;
        }
        cout<<counter;
        for(multiset<int>::iterator it=mymultiset.begin();it!=mymultiset.end();it++)
        {
            cout<<" "<<*it;
        }

		cout<<"\n";

	}
	return(0);
}
