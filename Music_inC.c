#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 11

struct node
{
    char data[20];
    struct node *next;
};

typedef struct mobile
{
    long long int phone;
    struct node *next1;
}*node1;

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void signup()
{
    //create a newnode with value
    long long int phone;
    struct node *newNode = malloc(sizeof(struct node));
    printf("Phone number ");
    scanf("%lld",&phone);
    printf("Password: ");
    scanf("%s",newNode->data);
    newNode->next = NULL;

    //calculate hash key
    int key = phone % size;

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
    printf("Sign up complete!");
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


void hash(long long int phone, char pass[20]){
    int key;
    key = phone % size;
    struct node *cur =  chain[key]; 
    while(cur!=NULL){
        if(strcmp(cur->data,pass)==0){
            printf("Logged in\n");
            break;
        }
        else{
            cur = cur->next;
        }
    }
}

void login(){
    
    long long int phone;
    char password[20];

    printf("Phone number ");
    scanf("%lld",&phone);
    printf("Password: ");
    scanf("%s",password);
    hash(phone,password);

}


node1 create_node()
{
    node1 temp;
    int n;
    temp=(node1)malloc(sizeof(struct mobile));
    printf("Phone number:");
    scanf("%lld",&temp->phone);
    temp->next1=NULL;
}


void append(){
    create_node();    
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

    login();
    return 0;
}

// int main(){
//     long long int phone;
//     char password[20];
//     int key;

//     // printf("Phone number ");
//     // scanf("%lld",&phone);
//     // printf("Password: ");
//     // scanf("%s",password);

    
//     // printf("%lld\n%s",phone,password);
//     // while(1){
//     //     scanf("%lld",&phone);
//     //     key = phone % 11;
//     //     printf("%d",key);
//     // }
//     // init();
    
//     // return 0;
// }