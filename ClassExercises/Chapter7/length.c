#include <stdio.h>
int main(void) {
int i,k=0,a[10],b[10],c[25],j,n,m,d[25],f=0;
printf("\n how many elements in SET 1: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("\n please enter the elements no %d - ",i+1);
    scanf("%d",&a[i]);
}
printf("\n how many elements in set 2: ");
scanf("%d",&m);
for(i=0;i<m;i++)
{
    printf("\n please enter elements no %d - ",i+1);
    scanf("%d",&b[i]);
}
for(i=0;i<n;i++)
{
    c[k]=a[i];
    k++;
}
for(i=0;i<n;i++) {
    f=0;
    for(j=0;j<m;j++) {
        if(b[i]==c[j])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        c[k]=b[i];
        k++;
    }
}

printf("\n the union set is:{");
for(i=0;i<k;i++)
{
    printf("\t%d",c[i]);
}
printf("}\n");
for(j=0;j<n;j++)
{
    for(i=0;i<m;i++)
    {
        if(b[i]==a[j])
            break;
    }
    if(i!=m)
    {
        d[f]=b[i];
        f++;
    }
}
}
