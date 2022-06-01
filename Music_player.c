#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"

typedef struct playlist
{
    char song[20];
    struct playlist *next;
    struct playlist *prev;

}*node;

typedef struct mobile
{
    long long int phone;
    struct node1 *next1;
} * node1;


node create_node()
{
    node temp;int n;
    temp=(node)malloc(sizeof(struct playlist));
    printf("enter the number:");
    scanf("%s",&temp->song);
    temp->next=NULL;
    temp->prev=NULL;
}


node1 create_node1(long long int phone)
{
    node1 temp1;
    temp1 = (node1)malloc(sizeof(struct mobile));
    temp1->phone = phone;
    temp1->next1 = NULL;
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

/*void display(node head)
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
}*/

/*node delete_ele(node head)
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

}*/

node1 insert_beg(node1 temp1, node1 head1)
{
    if (head1 == NULL)
    {
        return temp1;
    }
    temp1->next1 = head1;

    head1 = temp1;
    return head1;
}

void find_phone(long long int phone, node1 head1)
{

    node1 cur = head1, temp1;

    while (cur != NULL)
    {
        if (cur->phone == phone)
        {
            login(phone);
            break;
        }
        cur = cur->next1;
    }
    if (cur == NULL)
    {
        printf("Please sign up\n");
        temp1 = create_node1(phone);
        head1 = insert_beg(temp1, head1);
        signup(phone);
    }
}
void user(node1 head1)
{
    long long int phone;
    int opt;
    node1 temp1;
    printf("1.Sign up\n2.Login");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        printf("Phone number ");
        scanf("%lld", &phone);
        temp1 = create_node1(phone);
        head1 = insert_beg(temp1, head1);
        signup(phone);
        break;
    case 2:
        printf("Phone number ");
        scanf("%lld", &phone);
        find_phone(phone, head1);
        break;
    }
}


node create_playlist()
{
    node temp;int n;
    temp=(node)malloc(sizeof(struct playlist));
    printf("Playlist name: ");
    scanf("%s",&temp->song);
    temp->next=NULL;
    temp->prev=NULL;
}

void count_nodes(node head)          //Total Songs
{
    int i=0;
    node cur = head->next;
    while (cur->next!=NULL)
    {
        cur=cur->next;
        i++;
    }
    printf("Total songs-->%d",i);
}

void search1(node head)              //Searching a song
{
    char song[100];
    node cur = head->next;
    printf("\n\a\a\a\aEnter song To be Searched- ");
    scanf("%s",&song);
    int flag=0;

    while(cur!=NULL)
    {
        if(strcmp(cur->song,song)==0)
        {
            printf("\n\a\a\a\a#Song Found\n");
            flag++;
            break;
        }
        else
        {
            cur=cur->next;
        }
    }
    if(flag==0)
    {
        printf("\n\a\a\a\a#Song Not found");
    }
}

void play(node head)                //Play a song
{
    char song[100];
    node cur = head->next;
    printlist(head);
    printf("\n\a\a\a\aChoose song you wish to play- ");
    scanf("%s",song);
    int flag=0;

    while(cur!=NULL)
    {
        if(strcmp(cur->song,song)==0)
        {
            printf("\n\a\a\a\a=>Now Playing......%s",song);
            flag++;
            push(song);
            break;
        }
        else
        {
            cur=cur->next;
        }
    }
    if(flag==0)
    {
        printf("\n\a\a\a\a#Song Not found");
    }
}

void printlist(node head)                        //Print all the songs in a playlist
{
    node cur = head->next;
    printf("\nPlaylist Name- %s",head->song);
    while(cur->next!=NULL)
    {
        printf("%s",cur->song);
        cur=cur->next;
    }
    printf("%s",cur->song);
}

void main()
{
    // node temp,head=NULL;int ch;int n,x;char name[20];
    node1 head1 = NULL;
    init();      // initializing chain to NULL
    user(head1); // Signup or login

    node temp,head=NULL;int ch;int n,x;
    node headm[10];
    printf("Enter the name of your playlist: ");
    temp = create_playlist();
    headm[0] = insert_end(temp,head);

    while(1)
    {
        printf("\n1.Add New Song\n 2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n6.Play Song\n7.Recently Played List\n8.Last Played\n9.Sorted playlist\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Which linked list?:\n") ;
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