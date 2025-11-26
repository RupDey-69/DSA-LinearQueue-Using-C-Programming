// Linear Queue

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int front = -1;
int rear = -1;

int queue[SIZE];

// Enqueue Operation
int enqueue(int val)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Is Over Flow..\n");
        return -1;
    }

    if (front == -1) // first element insert
        front = 0;

    rear++; // rear must increase ALWAYS
    queue[rear] = val;

    printf("Inserted %d\n", val);
    return val;
}

// Dequeue Operation
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("The Queue Is Empty..\n");
        return -1;
    }

    int val = queue[front];
    front++;

    // queue becomes empty again
    if (front > rear)
    {
        front = rear = -1;
    }

    printf("Deleted %d\n", val);
    return val;
}

// Peek Operation
int peek()
{
    if (front == -1)
    {
        printf("The Queue Is Empty...\n");
        return -1;
    }

    printf("Front Element = %d\n", queue[front]);
    return queue[front];
}

// Display Operation
int display()
{
    if (front == -1)
    {
        printf("The Queue Is Empty....\n");
        return -1;
    }

    printf("Queue Elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n<----Queue Menu--->");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Peek");
        printf("\n 4.Display");
        printf("\n 5.Exit");

        printf("\nEnter the Choice:");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the Element in the Queue:");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice.....");
        }
    }

    return 0;
}
