#include<stdio.h>
#include<stdlib.h>

void red () 
{
  printf("\033[1;31m");
}
void rs()
{
  printf("\033[0m");
}

struct node
{
    int data;
    struct node *next;
}typedef node;

//Creating New Node
node* new_node()
{
    node *ptr=NULL;
    ptr = (node*)malloc(sizeof(node));
    ptr->data=0;
    ptr->next=NULL;
    return ptr;
}


//Eque Opretion
void enq(node *m_node, int val)
{
    node *ptr=NULL;
    ptr=new_node();
    ptr->data=val;
    ptr->next=m_node->next;
    m_node->next=ptr;
    printf("Enq value :%d\n ",ptr->data);
}


//Deque Opretion
int rm(node *m_node, node *node)
{
   if(node->next == NULL)
   {
       node->data = 0;
       m_node->next = NULL;
       free (node);
       return 0;
   }
   rm(node,node->next);
   return 0;
}

int dque(node *m_node)
{
    node *ptr=NULL;
    if(m_node->next == NULL)
    {
        red();
        printf("Queue is Empty Can't do Dequeue\n");rs();
        return 0;
    }
    rm(m_node,m_node->next);
    return 0;
}


//printing the que
int print(node *m_node)
{
    if(m_node != NULL)
    {
       printf("%d\t",m_node->data);
       print(m_node->next);
    }
    return 0;

}

//main Starts here
int main()
{
    node *main_node;
    main_node=new_node();
    int val,data,count=0;
    while(1){
    printf("\n1 Enque\n");
    printf("2 Deque\n");
    printf("3 print Que \n");
    printf("4 Exit\n");
    printf("Enter your Option : ");
    scanf("%d",&val);

    switch(val)
    {
      case 1: printf("Enter data:");
              scanf("%d",&data);
              enq(main_node,data);
              count=0;
              break;

      case 2:dque(main_node);
             count=0;
             break;

      case 3:if(main_node->next != NULL)
             { print(main_node->next);}
             else if(main_node->next == NULL)
             { red(); printf("Que is Empty\n");rs();}
             count=0;
             break;

      case 4:return 0;

      default:if(count<5)
               { red();
                red();
		printf("Enterd Option is Wrong\n\n");
		rs();
		count++;
               }
	      else
	      {
	       red();
               printf("Program Termineting\nbecouse multiple Wrong Entreis    \n");              
	       rs();
               return 0;
	      }
               break;
    }
  }

    return 0;
}
