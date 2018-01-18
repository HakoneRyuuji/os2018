#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) { // do nothing -- no free buffer item 
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {// do nothing -- nothing to consume
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

int main(){
	item *x;
	printf("The first item is producing\n");
	x = malloc(sizeof(item));
	produce(x);
	printf("The first: %f\n", first);
	printf("The last: %f\n", last);
	printf("The next item is producing\n");
	x = malloc(sizeof(item));
	produce(x);
	printf("The first: %f\n", first);
	printf("The last: %f\n", last);
	consume();
	printf("First item: %f\n", first);
	printf("Last one: %f\n", last);
return 0;
}
