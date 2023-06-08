#include<stdio.h>
#include<string.h>

int max(int a, int b){
    return (a>b)?a:b;
}
int Lcs_length(char* str1, char* str2, int m, int n){
    int Lcs[m+1][n+1];
    int i,j;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0)
                Lcs[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                Lcs[i][j]=Lcs[i-1][j-1]+1;
            else
                Lcs[i][j]=max(Lcs[i-1][j],Lcs[i][j-1]);
        }
    }
    return Lcs[m][n];
}
int main(){
     printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int m= strlen(str1);
    int n= strlen(str2);
    int Lcs_leng= Lcs_length(str1,str2,m,n);

    printf("Longest Common Subsequence = %d",Lcs_leng);
    return 0;
}
