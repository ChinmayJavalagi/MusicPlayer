#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 11
struct node
{
    char data[20];

    struct node *next;
};

struct node *chain[size];
void init()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

void signup(long long int phone)
{

    // create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    printf("Password:");
    scanf("%s", newNode->data);
    newNode->next = NULL;

    // calculate hash key
    int key = phone % size;

    // check if chain[key] is empty
    if (chain[key] == NULL)
        chain[key] = newNode;
    // collision
    else
    {
        // add the node at the end of chain[key].
        struct node *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    printf("Sign up completed\n\n");
}
void hash(long long int phone, char password[20])
{
    int key,flag = 0;
    key = phone % size;
    struct node *cur = chain[key];
    while (cur != NULL)
    {
        if (strcmp(cur->data, password) == 0)
        {
            printf("logged In\n");
            flag =1;
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    if(flag==0){
        printf("wrong Pasword\n");
        login(phone);
    }
}
void login(long long int phone)
{

    char password[20];
    printf("Password: ");
    scanf("%s", password);
    hash(phone, password);
}
void print()
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%s -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}