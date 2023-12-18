#include<stdio.h>
#include<stdlib.h>
//stracture to represet am object of a set in linked list reprsentation 
typedef struct
{
	int value;
	struct rep *repptr;//pointer to header node of the struct node *next
	struct node *next;
}node;

//structure to represent header node of linked representation of set 
typedef struct 
{
	node *head;
	node *tail;
}rep;
//structure to store key and object node pointer
typedef struct
{
	int key;
	node *obj_node_ptr;
	struct node_addr *next;
	}nodadder;
	nodadder *ndr=0;//list to store keys and objects node printer
	//function to create a set for an object 
void makeset(int a)
{
                                                   
nodadder *t=(nodadder *)malloc(sizeof(nodadder));//create a object node pointer
//create a new set
rep *newset=(rep *)malloc(sizeof(rep));//create a new set
node *n=(node *)malloc(sizeof(node));
//file values
n->value=a;
n->repptr=newset;
n->next=0;
//initialize head and tail
newset->head=newset->tail=n;
//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to returm pointer of the the representative(heder node) of the containing
rep *find(int x)
{
	nodadder *t=ndr;
	while(t->key!=x && t!=0)
		t=t->next;
	return t->obj_node_ptr->repptr;
}
//functon to find union of 2 sets corresponding ro object given
void unionset(int key1,int key2)
{
	rep *set1,*set2;
	node *t1;
	set1=find(key1);
	set2=find(key2);
	if(set1==set2)
	print("\n%d and %d to the same set .\n",key1,key2);
	else
	{
//changing the header pointer of object of set2 that of set
	t1=set2->head;
	while(t1!=0)
	{
		t1->repptr=set1;
		t1=t1->next;
	}
	set1->tail->next=set2->head;
	set2->tail=set2->tail;//set the tail of set to tail of set2

	free(set2);
	}
}
//function to diplaya set 
void display_set(int a)
{
	rep *r;
	node *t;
	r=find(a);
	t=r->head;
	print("set member contianing %d :",a);
	while(t!=0)
	{
		printf("%d",t->value);
		t=t->next;
	}
}
void main()
{
makeset(10);
makeset(20);
makeset(30);
makeset(40);
makeset(50);// it can member driven prblem
printf("find(10)=%x",find(10));
printf("find(20)=%x",find(20));
printf("find(30)=%x",find(30));
printf("find(40)=%x",find(40));
printf("find(50)=%x",find(50));
unionset(10,20);
display_set(10);
printf("\n after union of 10 and 20 find(20)=%x",find(20));
unionset(30,40);
display_set(30);
printf("\n afet union of 30 to 40 find(40)=%x",find(40));
unionset(20,40);
printf("\n after union of set containg 20 and set containg 40 find 40 find (40)=%x \n",find(40));
display_set(40);
}
