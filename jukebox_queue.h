#ifndef __JUKEBOX_QUEUE__
#define __JUKEBOX_QUEUE__

#include "request.h"

typedef struct jukebox_queue{
    request *head;
    request *tail;
} jukebox_queue;

jukebox_queue* create_jukebox_queue();
void enqueue_jukebox(request* element, jukebox_queue* queue);
request* dequeue_jukebox(jukebox_queue* queue);
unsigned int count_jukebox_queue(jukebox_queue* queue);
void destroy_jukebox_queue(jukebox_queue *queue);

#endif