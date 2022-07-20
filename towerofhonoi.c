#include<stdio.h>

void move(int n,char src,char dest,char temp)
{
  if(n==1)
  printf("Move from %c to %c\n",src,dest);

  else
  {
    move(n-1,src,temp,dest);
    move(1,src,dest,temp);
    move(n-1,temp,dest,src);
  }
}
int main()
{
  int n;
  printf("Enter number of rings\n");
  scanf("%d",&n);
  move(n,'A','C','B');
  return 0;
}
