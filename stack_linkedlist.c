#include<stdio.h>
#include<stdlib.h>

void red () {
  printf("\033[1;31m");
}
void rs(){
printf("\033[0m");
}

struct node 
{
    int data;
    struct node *next;
}typedef node;

node* new_node()
{
    node *ptr=NULL;
    ptr = (node*)malloc(sizeof(node));
    ptr->data=0;
    ptr->next=NULL;
    return ptr;
}

void push(node *m_node, int val)
{
    node *ptr=NULL;
    ptr=new_node();
    ptr->data=val;
    ptr->next=m_node->next;
    m_node->next=ptr;
    printf("push value :%d\n ",ptr->data);
}
int pop(node *m_node)
{
    node *ptr=NULL, *f=NULL;
    if(m_node->next == NULL)
    {
	red();
	printf("Stack is Empty Can't do POP\n");rs();
	return 0;
    }
    f=m_node->next;
    ptr=f->next;
    free(f);
    m_node->next=ptr;
    return 0;
}
void print(node *m_node)
{
    if(m_node != NULL)
    { 
       printf("%d\n",m_node->data);
       print(m_node->next);
    }

}
int main()
{
    node *main_node;
    main_node=new_node();
    int val,data,count=0;
    while(1){
    printf("\n1 Push\n");
    printf("2 Pop\n");
    printf("3 print Stack \n");
    printf("4 Exit\n");
    printf("Enter your Option : ");
    scanf("%d",&val);

    switch(val)
    {
      case 1: printf("Enter data:"); 
	      scanf("%d",&data);
	      push(main_node,data);
	      count=0;
	      break;

      case 2:pop(main_node);
	     count=0;
	     break;

      case 3:if(main_node->next != NULL)
	     { print(main_node->next);}
	     else if(main_node->next == NULL)
	     { red(); printf("Stack is Empty\n");rs();}
	     count=0;
	     break;

      case 4:return 0;

      default:if(count>3)
	       { red();
	     printf("Program Termineting\nbecouse multiple Wrong Entreis\n");
	        rs();
		return 0;
	       }
	       red();
	       printf("Enterd Option is Wrong\n\n");
	       rs();
	       count++;
	       break;
    }
  }

    return 0;
}
