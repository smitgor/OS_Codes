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

void sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                queue[i]=queue[i]+queue[j];
                queue[j]=queue[i]-queue[j];
                queue[i]=queue[i]-queue[j];
            }
        }
    }
}

void C_SCAN()
{
    sort();

    int j,idx;
    ans[0]=head_pointer;
    //move towards max values
    for(int i=0;i<n;i++)
    {
        if(queue[i]>head_pointer)
        {
            j=i;
            idx=i;
            break;
        }
    }
    int i=1;
    while(j<n)
    {
        ans[i]=queue[j];
        total_Seek_time+=abs(ans[i]-ans[i-1]);
        i++;
        j++;
    }
    ans[i]=range;
    total_Seek_time+=abs(ans[i]-ans[i-1]);
    i++;    
    ans[i]=0;
    total_Seek_time+=abs(ans[i]-ans[i-1]);
    i++;
    
    j=0;
    while(j!=idx)
    {
        ans[i]=queue[j];
        total_Seek_time+=abs(ans[i]-ans[i-1]);
        i++;
        j++;
    }

}

void print()
{
    printf("\n%d",ans[0]);
    for(int i=1;i<=n+2;i++)
    {
        printf(" --> %d",ans[i]);
    }
    
    printf("\nTotal numbers of movements : %d",n+2);
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
    C_SCAN();
    print();
}