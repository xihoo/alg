#include<stdio.h>
#include<string.h>

char a[500],b[500];
char num[501][501]; 
char flag[501][501];
void LCS(); 
void getLCS();
void LCS()
{
    int i,j;
    for(i=1;i<=strlen(a);i++)
    {
        for(j=1;j<=strlen(b);j++)
        {
            if(a[i-1]==b[j-1]) 
            {
                num[i][j]=num[i-1][j-1]+1;
                flag[i][j]=1; 
            }
            else if(num[i][j-1]>num[i-1][j])
            {
                num[i][j]=num[i][j-1];
                flag[i][j]=2;  
            }
            else
            {
                num[i][j]=num[i-1][j];
                flag[i][j]=3; 
            }
        }
    }
}
void getLCS()
{

    char res[500];
    int i=strlen(a);
    int j=strlen(b);
    int k=0;
    while(i>0 && j>0)
    {
        if(flag[i][j]==1) 
        {
            res[k]=a[i-1];
            k++;
            i--;
            j--;
        }
        else if(flag[i][j]==2) 
            j--;
        else if(flag[i][j]==3) 
            i--;
    }

    for(i=k-1;i>=0;i--)
        printf("%c",res[i]);
    printf("\n");
}
int main()
{
    int i;
    strcpy(a,"huyonhgong");
    strcpy(b,"huymfjhinyy");
    memset(num,0,sizeof(num));
    memset(flag,0,sizeof(flag));
    LCS();
    printf("%d\n",num[strlen(a)][strlen(b)]);
    getLCS();
    return 0;
}
