#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    
    unsigned int pivot = izq;    
    unsigned int i = izq + 1u;
    unsigned int j = der;

    while (i <= j){
        if (goes_before(a[i],a[pivot]))
        {
            i = i + 1u;
        } else if (goes_before(a[pivot],a[j])){
            j = j - 1u;
        } else{
            swap(a, i, j);
        }
    }

    swap(a,pivot,j);
    pivot = j;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    
   unsigned int ppiv;
   if (der > izq)
   {
       ppiv = partition( a, izq, der );
       quick_sort_rec(a, izq, ppiv );
       quick_sort_rec(a, ppiv + 1u, der);
   }
   
}


void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
