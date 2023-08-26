#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(struct _counter));
    c->count = 0u;
    return c;
}

void counter_inc(counter c) {
    c->count += 1u;
}

bool counter_is_init(counter c) {
    return (c->count == 0u); 
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count --;    
}

counter counter_copy(counter c) {
    counter k = NULL;
    k = malloc(sizeof(counter));
    k->count = c->count;
    return k; 
}

void counter_destroy(counter c) {
    free(c);
}
