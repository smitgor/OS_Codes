#include<stdio.h>

int n,frame,idx=0,j=0,hit=0,miss=0;
int referencePage[30],memory[10][30];
int result[30]; //1 for Hit and 2 for Miss

void printLine()
{
    printf("\n+");
    for(int i=0;i<n;i++)
    {
        printf("-------+");
    }
}

void print()
{
    printf("\n\n\nZERO(0) represents the empty spaces.");
    printLine();
    printf("\n| ");
    for(int i=0;i<n;i++)
    {
        printf("  %d   | ",referencePage[i]);
    }
    printLine();

    for(int i=0;i<frame;i++)
    {
        printf("\n| ");
        for(int j=0;j<n;j++)
        {
            printf("  %d   | ",memory[i][j]);
        }
    }
    printLine();
    printf("\n|");
    for(int i=0;i<n;i++)
    {
        if(result[i]==1)
        {
            printf("  Hit  +");
            hit++;
        }
        else
        {
            printf("  Miss +");
            miss++;
        }
    }
    printLine();
    printf("\n\nTotal numbers od HIT is : %d\n",hit);
    printf("\nTotal numbers od MISS is : %d\n\n",miss);
}

int available(int x,int idx1)
{
    for(int a=0;a<frame;a++)
    {
        if(x==memory[a][idx1-1])
        {
            return 1;
        }
    }
    return 0;
}

void fifo()
{
    for(int i=0;i<n;i++)
    {
        if(available(referencePage[i],i))
        {
            result[i]=1;
            for(int k=0;k<frame;k++)
            {
                memory[k][i]=memory[k][i-1];
            }
        }
        else
        {
            memory[j][i]=referencePage[i];
            for(int k=0;k<frame;k++)
            {
                if(k==j)
                {
                    memory[j][i]=referencePage[i];
                }
                else
                {
                    memory[k][i]=memory[k][i-1];                
                }
            }
            result[i]=2;
            j=(j+1)%frame;
        }
    }
}

int main()
{

    printf("Enter the total number of reference pages : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&referencePage[i]);
    }
    printf("\nEnter number of frames :");
    scanf("%d",&frame);
    for(int i=0;i<frame;i++)
    {
        for(int j=0;j<n;j++)
        {
            memory[i][j]=-1;
        }
    }
    fifo();
    print();
}
