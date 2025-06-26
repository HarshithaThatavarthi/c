#include<stdio.h>
int main()
{
    int arr[5],second_largest,j;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=0;
    for(int i=0;i<5;i++)
    {
        if(arr[i]>max){
            max=arr[i];
            j=i;
        }
    }
    for(int i=0;i<5;i++)
    {
      if(arr[i]>second_largest && i!=j) {
          second_largest=arr[i];
      } 
    }
    printf("%d",max);
    printf("%d",second_largest);
    return 0;
}
