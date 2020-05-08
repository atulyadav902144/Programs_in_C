    #include<stdio.h>
    #include<stdlib.h>
    #define maxsize 5
    void insert();
    void delete();
    void display();
    int front = -1, rear = -1;
    int queue[maxsize];
    void main ()
    {
        int choice;
        while(choice != 4)
        {
            printf("------Menu-------");
            printf("\n1.Insert an Element\n2.Delete an Element\n3.Display the Queue\n4.Exit\n");
            printf("\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                insert();
                break;
                case 2:
                delete();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(0);
                break;
                default:
                printf("\nInvalid choice??\n");
            }
        }
    }
    void insert()
    {
        int item;
        printf("\nEnter the element\n");
        scanf("\n%d",&item);
        if(rear == maxsize-1)
        {
            printf("\nQueue Overflow\n\n");
            return;
        }
        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear+1;
        }
        queue[rear] = item;
        printf("\nElement inserted ");

    }
    void delete()
    {
        if (front == -1 || front > rear)
        {
            printf("\nQueue Underflow\n\n");
            return;

        }
        else
        {
            if(front == rear)
            {
                front = -1;
                rear = -1 ;
            }
            else
            {
                front = front + 1;
            }
            printf("\nElement Deleted ");
        }


    }

    void display()
    {
        int i;
        if(rear == -1)
        {
            printf("\n---Queue is Empty--- \n\n");
        }
        else
        {   printf("\n----Queue----\n");
            for(i=front;i<=rear;i++)
            {
                printf("\n%d\n",queue[i]);
            }
        }
    }
