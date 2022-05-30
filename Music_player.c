#include<stdio.h>
#include<stdlib.h>

typedef struct num
{
    int data;
    struct num *next;
    struct num *prev;

}*node;
node create_node()
{
    node temp;int n;
    temp=(node)malloc(sizeof(struct num));
    printf("enter the number:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

}

node insert_end(node temp,node head)
{
    node cur=head;
    if(head==NULL)
    {
        head=temp;
    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return head;
}
void display(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("No list to display\n");
    }
    printf("The list are:\n");
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}
node insert_pos(node temp,node head)
{
    int pos,i=1;node cur=head,pre=head;
    printf("enter the position:");
    scanf("%d",&pos);
    while(i<pos)
    {
        cur=cur->next;
        i++;
    }
    pre=cur->prev;
    pre->next=temp;
    temp->next=cur;
    return head;
}

node delete_ele(node head)
{
    int n,flag=0;node pre,cur=head;;
    if(head==NULL)
        printf("cannot delete...list is empty\n");
    else
    {
        printf("enter the num");
        scanf("%d",&n);
        if(head->next==NULL)
        {
            if(cur->data==n)
            {
                flag=1;
                head=NULL;
                free(head);
                return head;
            }
        }
        else
        {
            while(cur->next!=NULL)
            {
                if(cur->data==n)
                {
                    flag=1;
                    pre=cur->prev;
                    pre->next=cur->next;
                    cur->next->prev=pre;
                    free(cur);
                    return head;
                }
                cur=cur->next;
            }
            if(cur->next==NULL)
            {
                if(cur->data==n)
                {
                    flag=1;
                    pre=cur->prev;
                    pre->next=NULL;
                    free(cur);
                    return head;
                }

            }
        }
        return head;
    }
    if(flag==0)
        printf("Invalid no\n");

}


void user(){
    int opt;
    printf("1.SignUp    2.Login");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1: signup();
        break;
    case 2: if(login()==False){
        
    }
        break;
    default:
        break;
    }
}


void main()
{
    node temp,head=NULL;int ch;int n,x;char name[20];
    printf("Enter the name of the playlist:\n");
    scanf("%s",&name);
    node headm[n];
    node head=NULL;
    temp=create_node();
    headm[0]=insert_end(temp,head);
    
    while(1)
    {
        printf(" 1.Add a new song\n 2.delete song\n 3.display the entire playlist\n 4.Total songs\n 5.search song\n 6.recently played track\n 7.sorted playlist\n 8.create a new playlist");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  printf("Which linked list?:\n") ;
                    scanf("%d",&x);
                    temp=create_node();
                    headm[x]=insert_end(temp,headm[x]);
                      break;
            case 2: printf("Which linked list?:\n") ;
                    scanf("%d",&x);
                    temp=create_node();
                    headm[x]=insert_end(temp,headm[x]);
                      break;
            case 3: printf("Which linked list?:\n") ;
                    scanf("%d",&x);
                    temp=create_node();
                    headm[x]=insert_pos(temp,headm[x]);
                    break;
            case 4: printf("Which linked list to delete?:\n") ;
                    scanf("%d",&x);
                    headm[x]=delete_beg(headm[x]);
                    break;
            case 5: printf("Which linked list to delete?:\n") ;
                    scanf("%d",&x);
                    headm[x]=delete_end(headm[x]);
                    break;
            case 6: printf("Which linked list to delete?:\n") ;
                    scanf("%d",&x);
                    headm[x]=delete_ele(headm[x]);
                    break;
            case 7: printf("which linked list to display?\n");
                    scanf("%d",&x);
                    display(headm[x]);
                    break;
            default: exit(0);

        }
    }

}
