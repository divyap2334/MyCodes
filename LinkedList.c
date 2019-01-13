#include <stdio.h>
#include <malloc.h>
#define ISEMPTY printf("\nEMPTY LIST:");
struct node
{
    int value;
    struct node *next;
};
struct node* create_node(int);
void insert_node_first();
void insert_node_last();
void insert_node_pos();
void delete_pos();
void search();
void update_val();
void display();
typedef struct node snode;
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;
 int main()
 {
    int ch;
    char ans = 'Y';

    while (ans == 'Y'||ans == 'y')
    {
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at position");
        printf("\n4.Delete Node from any Position");
        printf("\n5.Update Node Value");
        printf("\n6.Search Element in the linked list");
        printf("\n7.Display List from Beginning to end");
        printf("\n8.Exit\n");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t$$$Inserting node at first$$$\t\t\n");
            insert_node_first();
            break;
        case 2:
            printf("\n\t\t$$$Inserting node at last$$$\t\t\n");
            insert_node_last();
            break;
        case 3:
            printf("\n\t\t$$$Inserting node at position$$$\t\t\n");
            insert_node_pos();
            break;

        case 4:
            printf("\n\t\t$$$Deleting Node from any Position$$$\t\t\n");
            delete_pos();
            break;
        case 5:
            printf("\n\t\t$$$Updating Node Value$$$\t\t\n");
            update_val();
            break;
        case 6:
            printf("\n\t\t$$$Searching Element in the List$$$\t\t\n");
            search();
            break;
        case 7:
            printf("\n\t\t$$$Displaying List From Beginning to End$$$\t\t\n");
            display();
            break;

        case 8:
            printf("\n...Exiting...\n");
            return 0;
            break;
        default:
            printf("\n...Invalid Choice...\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N)");
        scanf(" %c", &ans);
    }
    return 0;
 }
snode *create_node(int val)
{
    snode *newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

void insert_node_first()
{
    int val;
    printf("\nEnter the value for the node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && first == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
}
void insert_node_last()
{
    int val;
    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
}
void insert_node_pos()
{
    int pos, val, cnt = 0, i;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
     printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr = first;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = first;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
    }
    else
    {
        printf("Position is out of range");
    }
}
void delete_pos()
{
    int pos, cnt = 0, i;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}
void update_val()
{
    int oldval, newval, flag = 0;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list to update\n");
    }
    else
    {
        printf("\nEnter the value to be updated:");
        scanf("%d", &oldval);
        printf("\nEnter the newvalue:");
        scanf("%d", &newval);
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            if (ptr->value == oldval)
            {
                ptr->value = newval;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nUpdated Successfully");
        }
        else
        {
            printf("\nValue not found in List");
        }
    }
}
void search()
{
    int flag = 0, key, pos = 0;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search");
        scanf("%d", &key);
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}
void display()
{
    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}
