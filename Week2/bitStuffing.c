#include<stdio.h>
#include<string.h>

int main()
{
    char data[50],stuff[50];
    int i,j,cnt,len;
    printf("enter data : ");
    scanf("%s",data);

    len=strlen(data);
    cnt=0,j=0;
    for(i=0;i<len;i++)
    {

    if(data[i]=='1')
    {
    cnt++;
    }
    else
    {
        cnt=0;
    }
    stuff[j]=data[i];
    j++;
    if(cnt==5&&data[i+1]=='1')
    {
        stuff[j]='0';
        j++;
        cnt=0;
    }
    }
stuff[j]='\0';
printf("stuffed data at intermediate site is \n 01111110 %s 01111110 \n ",stuff);
return 0;
}
