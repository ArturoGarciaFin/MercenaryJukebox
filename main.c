#include <stdlib.h>
#include <stdio.h>
#include "jukebox_queue.h"

void place_jukebox_request(jukebox_queue* queue){
    char song[51];
    float value = 0;

    printf("Enter the song name: ");
    fgetc(stdin);
    scanf("%50[^\n]", song);
    do{
        printf("Enter the song bid (min. $1): $");
        scanf("%f", &value);
    } while(value < 1);

    enqueue_jukebox(create_request(song, value), queue);
}


void play_jukebox(jukebox_queue *queue){

    request* next = dequeue_jukebox(queue);
    if (next != NULL){
        printf("Playing song %s with bid %.2f (%u requests remaining in queue)\n", next->song, next->value, count_jukebox_queue(queue));
        destroy_request(next);
    } else {
        printf("No song requests to be processed\n");
    }
}

int main(void){
    int option;
    jukebox_queue *queue;

    queue = create_jukebox_queue();
    printf("================ MERCENARY JUKEBOX ================\n");
    while(1){
        printf("1 - Place a request\n");
        printf("2 - Process a request\n");
        printf("3 - Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        if (option == 1)
            place_jukebox_request(queue);
        else if (option == 2)
            play_jukebox(queue);
        else if (option == 3)
            break;
        else
            continue;
    }

    destroy_jukebox_queue(queue);
    return 0;
}