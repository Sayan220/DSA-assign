#include<stdio.h>
#include<stdlib.h>
int size;
int* create(int *a){
	int i;
	printf("\nenter the size of array: ");
	scanf("%d",&size);
	a=(int*)malloc(size*sizeof(int));
	printf("\nenter the elements:");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	return a;
}

void display(int *a){
	int i;
	printf("\nthe array :  [ ");
	for(i=0;i<size;i++)
		printf("%d  ",a[i]);
        printf("]\n");
} 

void count(){
	if(size==0){
		printf("\nempty array");
		return;
	}
	printf("\ntotal number of elements :%d",size);
}

void reverse(int *a)
{
    int start,r,temp;
    start=0;  r=size-1;
    while(start<r)
    {
        temp=a[start];
        a[start]=a[r];
        a[r]=temp;
        start+=1;
        r-=1;
    }
}

void sort(int *a){
	int temp;
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			   }
		}
	}
}

void indexed_element(int * a,int l){
	if(l>=size)
	{
	   printf("\nindex not present");
	   return;
        }
	printf("\n the element at index %d is: %d",l,a[l]);
} 

void search(int *a,int ele){
	int flag=0,pos;
	for(int i=0;i<size;i++){
		if(a[i]==ele)
		{
		  flag=1;
		  pos=i;
		  break;
		}
	}
	if(flag==1)
	     printf("\nelement %d is found at index %d",ele,pos);
	else
	     printf("\nelement not found");
}   	

void insert(int m,int k,int *a){
	int i;
	a=realloc(a,sizeof(int)*(size+1));
	size++;
	for(i=size-1;i>=k;i--){
		a[i]=a[i-1];
	 }
	a[k]=m;
	display(a);
}

void merge(int **arr1, int **arr2)
{
    // Allocate memory for new array
    int *new_arr = (int *) malloc((size + size) * sizeof(int));
    // Copy elements from array 1
    int i;
    for (i = 0; i < size; i++) {
        new_arr[i] = (*arr1)[i];
    }
    // Copy elements from array 2
    for (i = 0; i < size; i++) {
        new_arr[size+i] = (*arr2)[i];
    }
	//printf("after for loop");
    // Update array and size
    //free(*arr1);
    *arr1 = new_arr;
    *n1 += *n2;
}

int main(){
	int *a=NULL;
	int *b=NULL
	int ch,l,m,k;
	while(1){
		  printf("\n\nMENU.....");
		  printf("\nenter 1 for create \nenter 2 for display \nenter 3 for count\nenter 4 for reverse\nenter 5 for sort\nenter 6 for indexed element\nenter 7 to search\nenter 8 to insert\nenter 10 to exit....\n\nenter choice:  ");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		    case 1: a=create(a);
			   break;
		    case 2: display(a);
			   break;
		    case 3: count();
			   break;
		    case 4: reverse(a);
			   break;
		    case 5: sort(a);
			   break;
		    case 6: printf("\nenter an index ");
			    scanf("%d",&l);
			    indexed_element(a,l);
			    break;
		    case 7: printf("\nenter the element to be search ");
			    scanf("%d",&l);
			    search(a,l);
			    break;
		    case 8: printf("\nenter the elemnet:");
			    scanf("%d",&m);
			    printf("\nenter the position:");
			    scanf("%d",&k);
			    insert(m,k,a);
			    break;
			case 9: printf("create 2nd array : ");
				b=create(b);
				//printf("break");
				merge(&a,&b);
				break;	
		    case 10: printf("\n..........exit.........."); exit(0);

		    default : printf("\nwrong choice. try again");
			     break;
		  }
		}
	return 0;
}

	
