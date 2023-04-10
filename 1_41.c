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

void display(int *a, int size){
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

void insert(int item,int k,int *a){
	a=realloc(a,sizeof(int)*(size+1));
	size++;
	for(int i=size-1;i>=k;i--){
		a[i]=a[i-1];
	 }
	a[k]=item;
}

void delete(int k,int*a){
	if(k<0 || k>=size){
		printf("\ninvalid position");
		return;
	}
	else{
		for(int i=k;i<size-1;i++){
			a[i]=a[i+1];
		}
	}
	size--;
}

void merge(int *a,int *b){
	int size2;
	int *res=NULL;
	printf("\nenter the size of  2nd array: ");
	scanf("%d",&size2);
	b=(int*)malloc(size2*sizeof(int));
	printf("\nenter the elements:");
	for(int i=0;i<size2;i++){
		scanf("%d",&b[i]);
	}
	int i=0,j=0,k=0;
	res=(int*)malloc((size+size2)*sizeof(int));
	while(i<size && j<size2){
		if(a[i]<b[j]){
			res[k]=a[i];
			i++; k++;
		}
		else{
			res[k]=b[j];
			j++; k++;
		}
	}
	while(i<size){
		res[k++]=a[i++];
	}
	while(j<size2){
		res[k++]=b[j++];
	}
	display(res,k);
}

/*void split(int **a, int *n1, int **a2, int *n2, int pos)
{
    *a2 = (int *) malloc((*n1 - pos)*sizeof(int));
    int i;
    for (i = pos; i < *n1; i++) {
        (*a2)[i-pos] = (*a)[i];
    }
    // Resize array 1
    *a = (int *) realloc(*a, pos * sizeof(int));
    *n2 = *n1 - pos;
    *n1 = pos;
}*/
void split(int *a, int size)
{
    int *s1,*s2,i,k;
    if(a==NULL){
    	return;
	}
	s1=(int*)malloc(sizeof(int)*(size/2));
	s2=(int*)malloc(sizeof(int)*(size/2));
	for(i=0;i<size/2;i++){
		s1[i]=a[i];
	}
	k=0;
	for(;i<size;i++){
		s2[k++]=a[i];
	}
	printf("\n1st half\n");
	display(s1,size/2);
	printf("\n2nd half\n");
	display(s2,k);
}

void index_of(int *a,int ele){
	int i,found=0;
	printf("Indices of %d:",ele);
	for(i=0;i<size;i++)
	{
		if(a[i]==ele)
		{
			printf("%d ",i);
			found=1;
		}
	}
	if(!found)
		printf("None");
	
	printf("\n");
}   	

int main(){
	int *a=NULL;
	int *b=NULL;
	int ch,l,item,pos;
	while(1){
		  printf("\n\nMENU.....");
		  printf("\nenter 1 for create \nenter 2 for display \nenter 3 for count\nenter 4 for reverse\nenter 5 for sort\nenter 6 for indexed element\nenter 7 to search\n");
		  printf("enter 8 to insert\nenter 9 to delete\nenter 10 to merge\nenter 11 to split\nenter 12 to find index of an element\nenter 0 to exit....\n\nenter choice:  ");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		    case 1: a=create(a);
			   break;
		    case 2: display(a,size);
			   break;
		    case 3: count();
			   break;
		    case 4: reverse(a);
			   break;
		    case 5: sort(a);
			   break;
		    case 6: printf("\nenter an index ");
			    scanf("%d",&l);
			    indexed_element(a,l);  // for finding element at a given index
			    break;
		    case 7: printf("\nenter the element to be search ");
			    scanf("%d",&l);
			    search(a,l);
			    break;
		    case 8: printf("\nenter the elemnet:");
			    scanf("%d",&item);
			    printf("\nenter the position:(0 indexing)  ");
			    scanf("%d",&pos);
			    insert(item,pos,a);
			    break;
			case 9:	printf("\nenter the position:(0 indexing)  ");
			    scanf("%d",&pos);
			    delete(pos,a);
				break;
			case 10: printf("create 2nd array :\n ");
				merge(a,b);
				break;
			case 11: split(a,size);
				break;
			case 12: printf("\nenter the element to be search ");      //for finding index of a given element
			    scanf("%d",&l);
			    index_of(a,l);
				break;			 
		    case 0: printf("\n..........exit.........."); exit(0);

		    default : printf("\nwrong choice. try again");
			     break;
		  }
		}
	return 0;
}
