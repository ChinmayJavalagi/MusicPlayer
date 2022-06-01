#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp.h"

typedef struct playlist
{
    char song[20];
    struct playlist *next;
    struct playlist *prev;

} * node;

typedef struct mobile
{
    long long int phone;
    struct node1 *next1;
} * node1;
node create_node()
{
    node temp;
    int n;
    temp = (node)malloc(sizeof(struct playlist));
    printf("enter the number:");
    scanf("%d", &temp->song);
    temp->next = NULL;
    temp->prev = NULL;
}
node playlist()                       // playlists
{
    node temp;
    int n;
    temp = (node)malloc(sizeof(struct playlist));
    printf("enter the playlist name:");
    scanf("%s", temp->song);
    temp->next = NULL;
    temp->prev = NULL;
}

node1 create_node1(long long int phone)
{
    node1 temp1;
    temp1 = (node1)malloc(sizeof(struct mobile));
    temp1->phone = phone;
    temp1->next1 = NULL;
    return temp1;
}

/*node insert_end(node temp,node head)              //add a song at the end
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
}*/
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
    char n[20],flag=0;node pre,cur=head->next;
    if(head==NULL)
        printf("No playlist found\n");
    else
    {
        printf("enter the song to be deleted");
        scanf("%s",n);
        if(cur->next==NULL)
        {
            if(strcmp(cur->song,n)==0)
            {
                flag=1;
                cur=NULL;
                free(cur);
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
node insert_end(node head)           //to add songs
{
    char a[100];
    node cur;
    if (head->next == NULL)
        cur = head;
    else
        cur = head->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = (node)malloc(sizeof(struct playlist));
    cur->prev = cur;
    cur = cur->next;
    printf("\n\a\a\a\aEnter Song name-  ");
    scanf("%s", cur->song);
    cur->next = NULL;
    return head;
}
node1 del_search(node head) // delete a song
{
    char song[100];
    node cur;
    if (head->next == NULL)
    {
        printf("\nNo songs in the playlist");
        return;
    }
    else{
        cur = head->next;
    }
    printlist(head);
    printf("\n\a\a\a\aChoose song you wish to delete- ");
    scanf("%s", song);
    int flag = 0;
    while (cur != NULL)
    {
        if (strcmp(cur->song, song) == 0)
        {
            printf("\n\a\a\a\a#Song Found");
            // node temp;
            // temp = (node)malloc(sizeof(struct playlist));
            // cur = cur;
            if (cur->next == NULL)
            {
                cur->prev->next = NULL;
                free(cur);
                flag++;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                free(cur);
                flag++;
            }
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        printf("\n\a\a\a\a#Song Not found\n");
    }
    return head;
}
void count_nodes(node head) // Total songs
{
    int i = 1;
    node cur;
    if (head->next == NULL)
    {
        printf("\nTotal songs-  %d", 0);
        return;
    }

    else
        cur = head->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
        i++;
    }

    printf("\nTotal songs-  %d", i);
}
void search1(node head) // searching a song
{
    char song[100];
    node cur = head->next;
    printf("\n\a\a\a\aEnter song To be Searched- ");
    scanf("%s", &song);
    int flag = 0;

    while (cur != NULL)
    {
        if (strcmp(cur->song, song) == 0)
        {
            printf("\n\a\a\a\a#Song Found");
            flag++;
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        printf("\n\a\a\a\a#Song Not found");
    }
}
void printlist(node head) // print all songs in a playlist
{
    if (head->next == NULL)
    {
        printf("No songs found\n");
        return;
    }
    else
    {
        node cur = head->next;
        printf("\nPlaylist Name- %s", head->song);
        while (cur->next != NULL)
        {
            printf("\n%s", cur->song);
            cur = cur->next;
        }
        printf("\n%s", cur->song);
    }
}
void play(node head) // play a song
{
    char song[100];
    node cur = head->next;
    printlist(head);
    printf("\n\a\a\a\aChoose song you wish to play- ");
    scanf("%s", song);
    int flag = 0;

    while (cur != NULL)
    {
        if (strcmp(cur->song, song) == 0)
        {
            printf("\n\a\a\a\a=>Now Playing......%s", song);
            flag++;
            // push (song);                                         //recently  played track
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        printf("\n\a\a\a\a#Song Not found");
    }
}

node1 insert_beg(node1 temp1, node1 head1) // List of phone numbers
{
    if (head1 == NULL)
    {
        return temp1;
    }
    temp1->next1 = head1;
    return temp1;
}

node insert_b(node1 temp1, node1 head1) // List of phone numbers
{
    if (head1 == NULL)
    {
        return temp1;
    }
    temp1->next1 = head1;

    head1 = temp1;
    return head1;
}

node1 find_phone(long long int phone, node1 head1)
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
    return head1;
}
node1 user(node1 head1)
{
    long long int phone;
    int opt;
    node1 temp1;
    printf("1.Sign up\n2.Login\n");
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
        head1 = find_phone(phone, head1);
        break;
    }
    return head1;
}
void main()
{
    init(); // initializing chain to NULL
    node1 head1 = NULL;
    while (1)
    {
        node temp;
        int ch, cp = 1, k,l,flag = 0,pflag = 0;
        char n[20], x[20];
        char name[20];
        node headm[10];
        printf("What's up! Listen to your favourite tracks on PMAC Music\n");
        head1 = user(head1); // Signup or login
        node head = NULL;
        temp = playlist();
        headm[1] = insert_b(temp,head);
        node cur;
        while (1)
        {
            printf("\n1.Add  New Song\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n6.Play Song\n7.Create a new playlist\n8.Log out\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("\nTo which playlist do you want to add?(playlist name)\n");
                scanf("%s", x);
                cur = headm[1];
                for (int i = 1; i <= cp; i++)
                {
                    if (strcmp(headm[i]->song, x) == 0)
                    {

                        headm[i] = insert_end(headm[i]);
                        pflag=1;
                        break;
                    }
                    cur = cur->next;
                }
                if (pflag == 0)
                {
                    printf("Playlist not found!!....\n");
                }
                break;
            case 2: printf("\nwhich playlist (playlist no)\n");
                    scanf("%d",&k);
                    headm[k] = del_search(headm[k]);
                    break;
            case 3: printf("\nwhich playlist (playlist no)\n");
                    scanf("%d",&k);
                    printlist(headm[k]);
                    break;
            case 4: printf("\nwhich playlist (playlist no)");
                    scanf("%d",&k);
                    count_nodes(headm[k]);
                    break;
            case 5: printf("\nwhich playlist (playlist no)\n");
                    scanf("%d",&k);
                    search1(headm[k]);
                    break;
            case 6: printf("\nwhich playlist (playlist no)\n");
                    scanf("%d",&k);
                    play(headm[cp]);
                    break;
            case 7: cp++;
                    temp=playlist();
                    headm[cp]=insert_b(temp,head);
                    break;
            case 8: flag=1;
                    break;
            default: exit(0);
            }
            if (flag == 1)
                break;
        }
        printf("Press 1 to close the application\n");
        scanf("%d",&l);
        if (l==1)
        {
            exit(0);
        }
    }
}