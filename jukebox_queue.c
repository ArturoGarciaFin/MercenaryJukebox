#include <stdio.h>
#include <stdlib.h>
#include "jukebox_queue.h"

jukebox_queue *create_jukebox_queue()
{
    jukebox_queue *queue = (jukebox_queue*)malloc(sizeof(jukebox_queue));
    if (!queue)
        return NULL;

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void enqueue_jukebox(request *element, jukebox_queue *queue)
{
    if (!queue || !element)
        return;

    if (!queue->head)
    {
        queue->head = element;
        queue->tail = element;
        return;
    }

    if (element->value >= queue->head->value)
    {
        element->next = queue->head;
        queue->head->prev = element;
        queue->head = element;
        return;
    }

    if (element->value < queue->tail->value)
    {
        queue->tail->next = element;
        element->prev = queue->tail;
        queue->tail = element;
        return;
    }

    request *aux = queue->head;
    while (aux != NULL && aux->value > element->value)
        aux = aux->next;

    element->next = aux;
    element->prev = aux->prev;

    if (aux->prev != NULL)
        aux->prev->next = element;

    if (aux != NULL)
        aux->prev = element;
}

request *dequeue_jukebox(jukebox_queue *queue)
{
    if (!queue || !queue->head)
        return NULL;

    request *r = queue->head;
    if (r->next)
        r->next->prev = NULL;
    else
        queue->tail = NULL;
    queue->head = r->next;

    return r;
}

unsigned int count_jukebox_queue(jukebox_queue *queue)
{
    request *aux = queue->head;
    unsigned int n = 0;

    while (aux != NULL)
    {
        aux = aux->next;
        n++;
    }

    return n;
}

void destroy_jukebox_queue(jukebox_queue *queue)
{
    request *aux;

    while ((aux = dequeue_jukebox(queue)))
        destroy_request(aux);
    free(queue);
}
