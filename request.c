#include <stdlib.h>
#include <string.h>

#include "request.h"

request* create_request(char* song, float value){
    request *new_req;

    new_req = (request*) malloc (sizeof(request));
    new_req->song = strdup(song);
    new_req->value = value;
    new_req->next = NULL;
    new_req->prev = NULL;
    
    return new_req;
}

void destroy_request(request* element){
    free(element->song);
    free(element);
}