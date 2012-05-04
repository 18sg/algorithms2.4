#include <assert.h>
typedef struct queue_element queue_element;
struct queue_element
{
	queue_element* next;
	int idx;
};

typedef struct
{
	queue_element* head;
	queue_element* tail;
	queue_element* free_head;
}queue; 

void queue_init(queue* q);
void queue_push_back(queue* q, int idx);
int queue_has_elements(queue* q);
int queue_pop(queue* q);
void queue_destory(queue* q);
