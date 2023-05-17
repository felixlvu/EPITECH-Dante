/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante
*/

#include "mys.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

kueue* create_queue(void)
{
    kueue* queue = (kueue*) malloc(sizeof(kueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(kueue* queue, position data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

position dequeue(kueue* queue)
{
    if (queue->front == NULL) {
        position pos = {-1, -1};
        return pos;
    }

    Node* node = queue->front;
    position data = node->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(node);
    return data;
}

int is_queue_empty(kueue* queue)
{
    return queue->front == NULL;
}
