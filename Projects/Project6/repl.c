#include<stdio.h>
void replace(int *a, int *b, int n);
void swap(int *p, int *q);
int main()
{
int n,i=0;
int a[100],b[100];
printf("Enter the number of digits of the number:");
scanf("%d",&n);
printf("Enter the number:");
for(i=0;i<n;i++)
scanf("%1d",&a[0]);
replace(a,b,n);

i=0;

for(i=0;i<n;i++)

  printf("%d",b[i]);

}
void replace(int* a,int* b,int n)
{
int i;
for(i=0;i<n;i++)
{
(*(b+i)) = (*(a+i)+6)%10;
}
swap(b,(b+(n-1)));
}
void swap(int *p, int* q)
{
int t;
t=*p;
*p=*q;
*q=t;
}


