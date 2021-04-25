#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *link;
	struct Node *llink;
};
typedef Node node;
node *aryList(int *,int);
node printList(node *);
void freeList(node *);
node *searchNode(node *,int);
void *insertNode(node *,int,int);
void *deleteNode(node *,int);
int main(){
	int funct,i,num,arrNum,item,iNode,idata,ddata;
	int *ary;
	node *Rnode,*Snode;
	while(-99){
		printf("------------------------------\n");
		printf("Plz choose the function\n1.Add new Array.\n2.Insert Node.\n3.Delete Node.\n4.Search Node.\n5.Exit\n");
		printf("------------------------------\n");
		printf("=> ");
		scanf("%d",&funct);
		switch(funct){
			case 1:
				printf("Array Size : ");
				scanf("%d",&arrNum);
				ary=(int *)malloc(sizeof(int)*arrNum);
				printf("Input array data : ");
				for(i=0;i<arrNum;i++){
					scanf("%d",&(*(ary+i)));
				}
				Rnode=aryList(ary,arrNum);
				printList(Rnode);
				break;
			case 2:
				printf("Insert Node number & Node data : ");
				scanf("%d %d",&iNode,&idata);
				insertNode(Rnode,iNode,idata);
				printList(Rnode);
				break;
			case 3:
				printf("Delete Node data : ");
				scanf("%d",&ddata);
				deleteNode(Rnode,ddata);
				printList(Rnode);
				break;
			case 4:
				printf("Plz input find number:");
				scanf("%d",&item);
				Snode=searchNode(Rnode,item);
				printf("<%p> Node value =%d\n",Snode,Snode->data);
				break;
			case 5:
				free(ary);
				freeList(Rnode);
				return 0; 
		}
	}
	
}

node *aryList(int *ary,int num){
	node *first,*current,*pre;
	
	for(int i=0;i<num;i++){
		current=(node *)malloc(sizeof(node));
		current->data=ary[i];
		if(i==0){
			first=current;
		}	
		else{
			pre->link=current;
		}
		current->link=NULL;
		pre=current;
	}
	return first;
}

node printList(node *first){
	node *current=first;
	if(first==NULL){
		printf("List is Empty\n");
//		return 0;
	}
	else{
		while(current!=NULL){
			printf("<%p>Node value =%d, Link to <%p>\n",current,current->data,current->link);
			current=current->link;	
		}
		
	}
	
}

void freeList(node *first){
	node *current,*tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->link;
		free(tmp);
		
	}
}

node *searchNode(node *first,int item){
	node *current;
	current=first;
	while(current!=NULL){
		if(current->data == item){
			return current;
		}
		else{
			current=current->link;
		}
	}
	return NULL;
}

void *insertNode(node *first,int Insertnode,int Insertitem){
	node *newNode,*tmp,*current;
	current=first;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = Insertitem;
	tmp=searchNode(current,Insertnode);
//	printf("<%p> %d -> <%p>",tmp,tmp->data,tmp->link);
	
	while(current!=NULL){
		if(tmp==current & tmp==first ){
			newNode->link = first->link;
			first->link = newNode;
		}
		else if(tmp==current & current->link==NULL){
			current->link = newNode;
			newNode->link=NULL;
		}
		else if(tmp==current & current->link!=NULL){
			newNode->link = current->link;
			current->link =newNode; 
		}
		current=current->link;
	}

}
void *deleteNode(node *first,int item){
	node *tmp,*current;
	current=first;
	tmp =searchNode(first,item);
	while(current!=NULL){
		if(tmp==current & tmp==first){
			first->link = current->link;
		}
		else if(current->link == tmp & tmp->link!=NULL){
			current->link = tmp->link;
		}
		else if(current->link == tmp & tmp->link==NULL){
			current->link = NULL;
		}
		current= current->link;
	}
}


