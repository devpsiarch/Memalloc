#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#define HEAP_CAP        640000  //max size in bytes of the heap
#define CHUNK_LIST_CAP  1024    // how many chunks are allowed in the Chunks list 

 
#define UNIMPLIMENETED \
    do {\
        fprintf(stderr,"%s:%d: TODO: %s is not yet implimented\n",__FILE__,__LINE__,__func__);\
        abort();\
    } while (false);


size_t used_heap = 0;
size_t HEAP[HEAP_CAP] = {0};

typedef struct {
    size_t size;
    void *start;
}Chunk;

typedef struct {
    size_t count;
    Chunk chunks[CHUNK_LIST_CAP];
}Chunk_list;


Chunk_list allocated_chunks = {0};
Chunk_list freed_chunks = {0};

void heap_dump(Chunk_list *list){
    for (size_t i = 0 ;i < list->count;i++) {
        printf("chunk(%zu): %p | size: %zu\n",i,list->chunks[i].start,list->chunks[i].size);
    }
}
int Chunk_find(const Chunk_list *list,void *ptr){
    UNIMPLIMENETED;
}
int Chunk_remove(Chunk_list *list,size_t index){
    UNIMPLIMENETED;
}
int Chunk_insert(Chunk_list *list,void *ptr,size_t size){
    assert(list->count < CHUNK_LIST_CAP);
    list->chunks[list->count].start = ptr;
    list->chunks[list->count].size = size;
    for (size_t i = list->count;i > 0 && list->chunks[i].start < list->chunks[i-1].start;i--) {
        const Chunk temp = list->chunks[i];
        list->chunks[i] = list->chunks[i-1];
        list->chunks[i-1] = temp;
    }
    list->count++;   
}

void *heap_alloc(size_t size){
	if(size > 0){
        assert(used_heap + size <= HEAP_CAP);
        void *ptr = HEAP + used_heap;
        used_heap += size;
        Chunk_insert(&allocated_chunks,ptr,size);
        return ptr;
    }
    else{
        return NULL;
    }
}



void heap_free(void *ptr){
	(void)ptr;
    UNIMPLIMENETED;
}

void heap_collect(){
    UNIMPLIMENETED;
}

int main(void){
	char *test = heap_alloc(26);
	for(int i = 0 ; i < 26;i++){
		test[i] = i + 'A';
        heap_alloc(sizeof(int)*i);
	}
    
	printf("%s\n",test);
    heap_dump(&allocated_chunks);
	return 0;
}
