#include<vector>
#include<iostream>
using namespace std;
struct mystruct
{
    int row;
    int col;
};
int main()
{

    vector< vector<struct mystruct> > A;
    for(int i=0;i<10;i++)
    {
        vector<struct mystruct> row;
        for(int j=0;j<10;j++)
        {
            struct mystruct x;
            x.row=i;
            x.col=j;
            row.push_back(x);
        }
        A.push_back(row);
    }
    for(int i=0;i<10;i++)
    {


        for(int j=0;j<10;j++)
        {

           cout<<A[i][j].row<<","<<A[i][j].col<<" ";
        }
         cout<<"\n";
    }
}
