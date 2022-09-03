#include <iostream>
#include "QueueClass.cpp"
// Testing Radix Sort

int get_max(int arr[], int size)
{
  int i, max = arr[0];
  for (i = 1; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int num_of_digit(int num)
{
  int digit = 0;
  while (num != 0)
  {
    digit++;
    num = num / 10;
  }
  return digit;
}

int radix_sort(int arr[], int size)
{
  int num, i, radix = 10;
  num = num_of_digit(get_max(arr, size)); // number of passess

  // array of 10 queues
  Queue *pendingNums;
  pendingNums = (Queue *)malloc(10 * sizeof(Queue));
  // pendingNums = new Queue[10];
  if (pendingNums == NULL)
    return (0);

  int div = 1;
  for (i = 0; i < num; i++)
  {
    int el, j, k, index;
    for (j = 0; j < size; j++)
    {
      el = arr[j];
      el = el / div;
      index = el % radix;
      pendingNums[index].enqueue(arr[j]);
    }

    for (j = 0, k = 0; j < 10; j++)
    {
      while (!pendingNums[j].isEmpty())
      {
        el = pendingNums[j].dequeue();
        arr[k] = el;
        k++;
      }
    }

    div *= 10;
  }

  free(pendingNums);
  return (1);
}

void display(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int status;
  int arr[8] = {82, 901, 100, 12, 150, 77, 55, 23};
  status = radix_sort(arr, 8);
  if (status == 1)
  {
    printf("Sorted Successfully!\n");
  }
  else
    printf("Sorting has failed!\n");

  display(arr, 8);
}
