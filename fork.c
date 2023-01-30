#include <stdio.h>
#include <stdlib.h>     //header file for exit
#include <unistd.h>     //header file for fork system call
#include <sys/types.h> 
int main(){
    int n, temp;
    printf("enter no of elements :");
    scanf("%d",&n);
    int a[n];
    printf("enter element into array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    pid_t pid;
    pid=fork();
    if(pid>0){
        printf("parent process unsorted array:");
        for(int i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
    }
    
    else if(pid<0){
        printf("error");
    }
    else if(pid==0){
        printf("\n child process");
        printf("\n array after sorted");
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
        
    }
}