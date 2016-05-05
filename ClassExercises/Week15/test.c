#include <stdio.h>
struct node {
    int num;
    struct node *next;
}*prev = NULL;

struct node *last_to_first(struct node *list) {
    struct node *cur;
    for (cur = list; cur->next != NULL; prev = cur, cur = cur->next);
    
    if (prev == NULL) {
        return list;
    } else {
        prev->next = NULL;
        cur->next = list;
	return cur;
    }
}

int main() {
    struct node *p = NULL;
    p->num = 1;
    p->next->num = 8;
    p->next->next->num = 9;
	
	return 0;
}
