#include<stdio.h>
#include<malloc.h>
#include"libbinheap.h"

int main() {
    binheap_t *heap = binheap_new(1000);
    unsigned int n, i;
    pair_t v = {0, 0};

    scanf("%u", &n);
    for( i = 0; i < n; i++ ){
       scanf("%d", &v.key);
       v.value = i;
       binheap_add(heap, v);
    }

    while( binheap_extract_min(heap, &v) ) {
       printf("%d ", v.key);
    }
    printf("\n");
    binheap_delete( heap );
    return 0;
}
