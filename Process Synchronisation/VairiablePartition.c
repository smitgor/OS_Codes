#include<stdio.h>

int memorySize[20],ans[20],processSize[20],memorySize_duplicate[20];
int n,m;

void print()
{ 
    printf("\nProcess No.\tProcess Size\tBlock No.");
    for(int i=0;i<n;i++)
    {
        if(ans[i]!=0)
        {
            printf("\n%d\t\t%d\t\t%d",i+1,processSize[i],ans[i]);
        }
        else
        {
            printf("\n%d\t\t%d\t\tNot Allocated",i+1,processSize[i],ans[i]);
        }
    }
    printf("\n\n");
}

int maximumsize(int x)
{
    int max=0;
    for(int i=0;i<m;i++)
    {
        if(memorySize_duplicate[i]>=x)
        {
            if(memorySize_duplicate[i]>max)
            {
                max=memorySize_duplicate[i];
            }
        }
    }
    return max;
}

int minimumsize(int x)
{

    int min=99999;
    for(int i=0;i<m;i++)
    {
        if(memorySize_duplicate[i]>=x)
        {
            if(memorySize_duplicate[i]<min)
            {
                min=memorySize_duplicate[i];
            }
        }
    }
    if(min==99999)
    {
        return 0;
    }
    else
    {
        return min;
    }
    
}

void worstfit()
{
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
    }    
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    int x;
    for(int i=0;i<n;i++)
    {
        x = maximumsize(processSize[i]);
        if(x!=0)
        {
            for(int j=0;j<m;j++)
            {
                if(x==memorySize_duplicate[j])
                {
                    ans[i]=j+1;
                    memorySize_duplicate[j]-=processSize[i];
                    break;
                }
            }
        }
        else
        {
            ans[i]=0;
        }
    }
    printf("\nWorst Fit : \n");
    print();
}

void bestfit()
{
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
    }
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    int x;
    for(int i=0;i<n;i++)
    {
        x = minimumsize(processSize[i]);
        if(x!=0)
        {
            for(int j=0;j<m;j++)
            {
                if(x==memorySize_duplicate[j])
                {
                    ans[i]=j+1;
                    memorySize_duplicate[j]-=processSize[i];
                    break;
                }
            }
        }
        else
        {
            ans[i]=0;
        }
    }
    printf("\nBest Fit : \n");
    print();
}

void firstfit()
{
    int memorySize_duplicate[20];
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
    }
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<m;j++)
        {
            if(processSize[i]<=memorySize_duplicate[j])
            {
                
                ans[i]=j+1;
                memorySize_duplicate[j]-=processSize[i];
                break;
            }
        }
    }
    printf("\nFirst Fit : \n");
    print();
}

int main()
{

    printf("Enter the total number of processes : ");
    scanf("%d",&n);
    printf("Enter the process size : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processSize[i]);
    }

    printf("Enter the total number memory part : ");
    scanf("%d",&m);
    printf("Enter the memory size : ");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&memorySize[i]);
    }

    firstfit();

    bestfit();

    worstfit();
    return 0;
}