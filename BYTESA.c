#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;  //No of test cases
char x[10000000];
int len;
int retval;
int func();
void func2();
int main()
{
  int val;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%s",x);
    len=strlen(x);
    val=func();
    if(val==-1)
    { 
      printf("NO\n");
    }
    else
    {
      printf("YES\n");  
      func2();
    }
  }
  return(0);
}
int func()
{
  int no;
  for(no=len-1;no>=0;no--)
  {
    if(x[no]=='1'||x[no]=='6'||x[no]=='8'||x[no]=='9'||x[no]=='0')
    {
    }
    else
    {
      return(-1);
    }
   }
   return(0); 
}
void func2()
{
  int no;
  for(no=len-1;no>=0;no--)
  {
    if(x[no]=='1'||x[no]=='8'||x[no]=='0')
    {
      printf("%c",x[no]);
    }
    if(x[no]=='6')
    {printf("9");}
    if(x[no]=='9'){printf("6");}  
  }
  printf("\n");
} 