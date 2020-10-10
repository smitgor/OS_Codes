#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int memorySize[20],ans[20],processSize[20],memorySize_duplicate[20];
int n,m;
int internal_F=0,external_F=0;

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
    printf("\nInternal fragmentation : %d",internal_F);
    printf("\nInternal fragmentation : %d",external_F);
    printf("\n\n");
}

int maximumsize(int x)
{
    int max=0;
    for(int i=0;i<m;i++)
    {
        if(memorySize_duplicate[i]>x)
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
        if(memorySize_duplicate[i]>x)
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
    external_F=0;
    internal_F=0;
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
        external_F+=memorySize[i];
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
                    internal_F=memorySize_duplicate[j]-processSize[i];
                    memorySize_duplicate[j]=0;
                    external_F-=processSize[i];
                    break;
                }
            }
        }
        else
        {
            ans[i]=0;
            //external_F+=;
        }
    }
    printf("\nWorst Fit : \n");
    print();
}

void bestfit()
{
    external_F=0;
    internal_F=0;
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
        external_F+=memorySize[i];
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
                    internal_F=memorySize_duplicate[j]-processSize[i];
                    memorySize_duplicate[j]=0;
                    external_F-=processSize[i];
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
    external_F=0;
    internal_F=0;
    for(int i=0;i<m;i++)
    {
        memorySize_duplicate[i]=memorySize[i];
        external_F+=memorySize[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(processSize[i]<memorySize_duplicate[j])
            {
                
                ans[i]=j+1;
                internal_F=memorySize_duplicate[j]-processSize[i];
                memorySize_duplicate[j]=0;
                external_F-=processSize[i];
                break;
            }
        }
    }
    printf("\nFirst Fit : \n");
    print();
}

int main()
{
    srand(time(0)); 
    n = rand() % 8+1;
    for(int i=0;i<n;i++)
    {
        processSize[i] = rand() % 7+1;
    }

    m = rand() % 7+1;
    for(int i=0;i<m;i++)
    {
        memorySize[i] = rand() % 7+1;
    }

    firstfit();

    bestfit();

    worstfit();
    return 0;
}