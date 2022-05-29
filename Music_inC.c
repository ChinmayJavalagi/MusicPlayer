#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 11




// void hash(char phone, char pass[20]){
    
// }











struct node
{
    char data[20];
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(long long int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    
    scanf("%s",newNode->data);
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%s -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


void login(){
    
}


int main()
{
    //init array of list to NULL
    init();

    insert(8431309851);
    insert(8431309551);
    insert(9247124723);
    insert(7812612912);
    insert(9123408211);
    insert(9246128412);
    insert(7123192391);
    insert(6127349134);
    insert(9821236593);
    insert(9127312312);

    print();

    return 0;
}
