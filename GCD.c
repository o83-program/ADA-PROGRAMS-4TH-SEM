#include<stdio.h>
int GCD(int x, int y)
{
if(x%y==0)
 return y;
else
 return (GCD(y, x%y));
}

int main()
{
int num1, num2, result;
printf("\n Enter the two numbers: ");
scanf("%d %d", &num1, &num2);
result = GCD(num1, num2);
printf("GCD of %d and %d = %d", num1, num2, result);
return 0;
}
