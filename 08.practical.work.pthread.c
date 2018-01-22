#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct
{
  char type;			// 0=fried chicken, 1=French fries
  int amount;			// pieces or weight
  char unit;			// 0=piece, 1=gram
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void
produce (item * i)
{
  while ((first + 1) % BUFFER_SIZE == last)
    {				// do nothing -- no free buffer item 
    }
  memcpy (&buffer[first], i, sizeof (item));
  first = (first + 1) % BUFFER_SIZE;
  item *x;
  printf ("The first item is producing\n");
  x = malloc (sizeof (item));
  printf ("The first: %f\n", first);
  printf ("The last: %f\n", last);
  printf ("The next item is producing\n");
  x = malloc (sizeof (item));
}

item *
consume ()
{
  item *i = malloc (sizeof (item));
  while (first == last)
    {				// do nothing -- nothing to consume
    }
  memcpy (i, &buffer[last], sizeof (item));
  last = (last + 1) % BUFFER_SIZE;
  printf ("The first: %f\n", first);
  printf ("The last: %f\n", last);
  printf ("First item: %f\n", first);
  printf ("Last one: %f\n", last);
  return 0;
}

void
producerThread (void *param)
{
  int count = 0;
  item *i;
  while (count < 3)
    {
      i = malloc (sizeof (item));
      produce (i);
      count = count + 1;
    }
}

void
consumerThread (void *param)
{
  int count = 0;
  while (count < 2)
    {
      consume ();
      count = count + 1;
    }
}

int
main ()
{
  pthread_t tid;
  pthread_create (&tid, NULL, producerThread, NULL);
  pthread_join (tid, NULL);
  pthread_t tid1;
  pthread_create (&tid1, NULL, consumerThread, NULL);
  pthread_join (tid1, NULL);
}

