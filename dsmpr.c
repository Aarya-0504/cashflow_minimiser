#include<stdio.h>
#include<stdlib.h>

int graph[20][20],amount[20];
char name[20][20];
/*struct node{
    char data;
    
}*/

int minimumof2(int a,int b){
    if(a<=b)
        return a;
    else
        return b;
}

int minimumIndex(int n){
    int min_index=0;
    for(int i=0;i<n;i++){
        if(amount[i]<amount[min_index]){
            min_index=i;
        }
    }
    return min_index;
}

int maximumIndex(int n){
    int max_index=0;
    for(int i=0;i<n;i++){
        if(amount[i]>amount[max_index]){
            max_index=i;
        }
    }
    return max_index;
}

void cashflow(int n){
    int credit=maximumIndex(n);
    int debit=minimumIndex(n);
    //for(int i=0;i<n;i++)
   // printf("amount[%d]=%d ",i,amount[i]);
    
   // printf("credit=%d and debit=%d \n",credit,debit);
    if(amount[credit]==0 && amount[debit]==0){
        return;
    }
        
    int min_value=minimumof2(-amount[debit],amount[credit]);
    amount[debit]=amount[debit]+min_value;
    amount[credit]=amount[credit]-min_value;
    printf("%s should send %drs to %s\n",name[debit],min_value,name[credit]);
    cashflow(n);    
}

void amountstorearray(int n){
    
    
    
    for(int i=0;i<n;i++){
        amount[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            amount[i]=amount[i]+(graph[j][i]-graph[i][j]);
        }
    }
    cashflow(n);
   
    return;
}

int main(){
    int n,i=0;
    char s[20];
    printf("wel come we will help you for your transaction management(cashflow minimisation) \n");
    printf("\n");
    printf("Enter the number of people:");
    scanf("%d",&n);
    printf("\n");
   // for(int i=0;i<n;i++){
        
       for(i=0;i<n;i++){
           printf("enter name of persons  : ");
           scanf("%s",name[i]);
       }
       printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(name[i]!=name[j]){
                printf("enter the amount that %s is given to %s : ",name[i],name[j]);
                scanf("%d",&graph[i][j]);
                continue;
            }
            
        }
    }
    printf("\n");
    printf("given relation of transaction is ploted below : \n");
    printf("\n");
    for(i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    amountstorearray(n);
    printf("\n\n||Thank you||");
    return 0;
}