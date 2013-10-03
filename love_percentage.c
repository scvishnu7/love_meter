#include<stdio.h>
#include<string.h>
void main(){
char female[15];
char male[15];
int loveper,lov,len1,len2;

printf("enter male's name ");
scanf("%s", male);
printf("enter female's name ");
scanf("%s", female);

len1=strlen(male);
len2=strlen(female);
lov=len1*len2;

if(lov>100)
{
loveper=100-lov;
printf("the love percentage is %d", loveper);
}

if(lov<50)
{
loveper=lov+50;
printf("the love percentage is %d", loveper);
}

else
{
printf("the love percentage is %d", lov);
}
}
