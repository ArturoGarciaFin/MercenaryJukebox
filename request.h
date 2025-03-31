#ifndef __REQUEST__
#define __REQUEST__

typedef struct request{
    char* song;
    float value;

    struct request *next;
    struct request *prev;
} request;

request* create_request(char* song, float value);
void destroy_request(request* element);

#endif