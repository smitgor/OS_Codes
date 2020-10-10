#include<stdio.h>
#include<math.h>
int n,range,head_pointer,total_Seek_time=0;
int queue[20],ans[20],temp[20];

int nextRequest(int x)
{
    int idx=0;
    int min=range+1;
    for(int i=0;i<n;i++)
    {
        if(temp[i]!=-1 && min>(abs(x-queue[i])))
        {
            idx=i;
            min=abs(x-queue[i]);
        }
    }
    temp[idx]=-1;
    return queue[idx];
}

void SSTF()
{
    int j;
    for(int i=0;i<n;i++)
    {
        temp[i]=queue[i];
    }
    ans[0]=head_pointer;
    for(int i=0;i<n;i++)
    {
        j=nextRequest(ans[i]);
        ans[i+1]=j;        
        total_Seek_time+=abs(ans[i]-ans[i+1]);
    }
}

void print()
{
    printf("\n%d",ans[0]);
    for(int i=1;i<=n;i++)
    {
        printf(" --> %d",ans[i]);
    }
    printf("\nTotal numbers of movements : %d",n);
    printf("\nTotal seek time : %d",total_Seek_time);
}

int main()
{
    printf("Enter the Range : ");
    scanf("%d",&range);
    printf("Enter total nummber of requests : ");
    scanf("%d",&n);
    printf("Enter request in queue\n");
    for(int i=0;i<n;i++)
    {     
        scanf("%d",&queue[i]);
    }
    printf("Enter the head pointer : ");
    scanf("%d",&head_pointer);
    SSTF();
    print();
}