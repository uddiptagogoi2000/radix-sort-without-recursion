#include <iostream>
#define MY_TYPE int

struct queue_node
{
  int info;
  queue_node *next;
};

typedef struct queue_node node;

class Queue
{
  node *head;
  node *tail;
  int size;

public:
  Queue()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  int getSize()
  {
    return size;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  MY_TYPE front()
  {
    if (isEmpty())
      return 0;
    return head->info;
  }

  bool enqueue(MY_TYPE data)
  {
    node *temp = new node; // OR node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
      return false;
    temp->info = data;
    temp->next = NULL;

    if (head == NULL)
    {
      head = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
    size++;
    return true;
  }

  MY_TYPE dequeue()
  {
    if (isEmpty())
      return 0;

    MY_TYPE ans = head->info;

    node *temp = head;
    head = head->next;
    delete temp;
    size--;
    return ans;
  }

  void display()
  {
    node *temp = head;
    printf("Queue is:\n");
    while (temp != NULL)
    {
      printf("%d ", temp->info);
      temp = temp->next;
    }
    printf("\n");
  }

  ~Queue()
  {
    while (!isEmpty())
    {
      this->dequeue();
    }
  }
};
