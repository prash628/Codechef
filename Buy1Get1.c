#include <stdio.h>
#include <string.h>
char ip[200];
int len;
int chk[200];
void clearchk();
void func();
int findres();
int result;
int main()  //BruteForce
{
  int n;
  scanf("%d",&n);
  while(n)
  {
    
    clearchk();
    scanf("%s",ip);
    len=strlen(ip);
    func();
    n--;
    result=findres();
    printf("%d\n",result);
  }
  return 0;
}
void func()
{
  int i,j;
  char checkchar;
  for(i=0;i<len;i++)
  {
    checkchar=ip[i];
    if(chk[i]==0)
    { 
      chk[i]=1;
      for(j=i+1;j<len;j++)
      {
          if(checkchar==ip[j])
          {
            chk[i]=chk[i]+1;
            chk[j]=201;
          }
      }
    }
   }
}
int findres()
{
  int count=0;
  int i,x;
  for(i=0;i<len;i++)
  {
    if(chk[i]!=201)
    {
      if(chk[i]==1)
      {
        count++;
      }
      else
      {
        x=chk[i]/2;
        count=count+x;
        if(chk[i]%2==1)
        {
          count++;
        }
      }
    }
  }
  return(count);
}
void clearchk()
{
  int i;
  for(i=0;i<200;i++)
  {
    chk[i]=0;
  }
}
 
