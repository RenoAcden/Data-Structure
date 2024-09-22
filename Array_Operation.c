#include<stdio.h>
int a[10], currentsize=0, size;
int main(){
    int choice;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&a[i]);
        currentsize++;
    }    
    printf("To perform Operations enter any 1 option\n"); 
    printf("1. To Insert\n"); 
    printf("2. To delete\n");
    printf("3. To search\n");
    printf("4. To display\n");  
    printf("5. To Sort\n");  
    
    
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insert(a);
            break;
        case 2:
            delete(a);
            break;  
        case 3:
            search(a);
            break; 
        case 4:
            display(a);
            break;
        case 5:
            sort(a);
            break;              
            }
        }
int isfull(){
    if(currentsize==size){
        return 1;
        }
    else{
        return 0;
        }   
    }           
int isempty(){
    if(currentsize==0){
        return 1;
        }
    else{
        return 0;
        }
    } 
int insert(int *a){
    int element,pos;
    if(isfull()==1){
        printf("Cannot Insert!");
        }
    else{  
        printf("Enter the element to insert:");
        scanf("%d",&element);
        printf("Enter the position to insert:");
        scanf("%d",&pos);
        for(int i=currentsize;i>pos-1;i--){
            a[i]=a[i-1];
        
        }
        a[pos-1]=element;
        currentsize++;
        for(int i=0;i<currentsize;i++){
            printf("%d\n",a[i]);
        }
    }   
} 
int delete(int *a){
    int pos;
    if(isempty()==1){
        printf("You can't delete:");
    }
    else{
    printf("Enter the position to delete:");
    scanf("%d",&pos);
    for(int i=pos-1;i<currentsize;i++){
        a[i]=a[i+1];
    }
    currentsize--;
    for(int i=0;i<currentsize;i++){
        printf("%d\n",a[i]);
        }
    }    
}
int search(int *a){
    if(isempty()==1){
        printf("The array in empty.You can't search:");
    }
    else{
        int search,found=0,i;
        printf("Enter the element to search:");
        scanf("%d",&search);
        for(i=0;i<currentsize;i++){
            if(a[i]==search){
                printf("The element is in %d(st/nd/rd/th) position.",i+1);
                found++;
                }
            }   
            if(found==0){
                printf("Not found!");
            }
          
        }
    }
int display(int *a){
    if(isempty()==1){
        printf("No Element,can't display");
        }
    else{
        printf("The elements are:");
        for(int i=0;i<currentsize;i++){
            printf("%d\t",a[i]);
            } 
        }   
    }
int sort(int *a){
    int i,j,temp;
    if(isempty()==1){
        printf("No Element, Can't sort");
        }
    else{
        for(i=0;i<currentsize;i++){
            for(j=i+1;j<currentsize;j++){
                if(a[i]>a[j]){
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }   
        }
    printf("Sorted Array:\n");
    for(i=0;i<currentsize;i++){
        printf("%d \t",a[i]);
        }
    }
}