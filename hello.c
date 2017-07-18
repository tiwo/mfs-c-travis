#include <stdlib.h>
#include <stdio.h>	// printf

void die(){}

struct letter;
typedef struct letter {
	struct letter *next;
	struct letter *prev;
	char c;
} letter;
// typedef struct letter letter;

letter *letterlist_append(letter *list, char c) {
	letter *new = malloc(sizeof(letter));
	new->c = c;
	new->prev = list->prev;
	new->next = list;
	new->prev->next = list->prev = new;
	list->prev = new;
}

int letterlist_length(const letter *list) {
	const letter *l = list->next;
	int result = 0;
	while (l != list) {
			result++;
			l = l->next;
	}
	return result;
}

void require(int truth) {	if (!truth) exit(1); }

int main(int argc, char **argv) {
	letter *list = letterlist_append(NULL, 'H');
	require((int)list);
	for (const char *w = "ello World!"; *w; ++w)
		require((int)letterlist_append(list, *w));

	printf("List length: %d\n", letterlist_length(list));
	return 0;
}
