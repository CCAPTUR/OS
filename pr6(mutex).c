#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for sleep()

pthread_mutex_t x, wsem; // x for reader count, wsem for mutual exclusion
int readcount = 0;

void initialize() {
    pthread_mutex_init(&x, NULL);
    pthread_mutex_init(&wsem, NULL);
}

void *reader(void *param) {
    int waittime = rand() % 5;
    printf("\nReader is trying to enter");

    pthread_mutex_lock(&x);
    readcount++;
    if (readcount == 1)
        pthread_mutex_lock(&wsem);
    printf("\n%d reader(s) inside", readcount);
    pthread_mutex_unlock(&x);

    sleep(waittime);

    pthread_mutex_lock(&x);
    readcount--;
    if (readcount == 0)
        pthread_mutex_unlock(&wsem);
    pthread_mutex_unlock(&x);

    printf("\nReader is leaving");
    return NULL;
}

void *writer(void *param) {
    int waittime = rand() % 3;
    printf("\nWriter is trying to enter");

    pthread_mutex_lock(&wsem);
    printf("\nWriter has entered");
    sleep(waittime);
    pthread_mutex_unlock(&wsem);

    printf("\nWriter is leaving");
    return NULL;
}

int main() {
    int n1, n2, i;

    printf("\nEnter the number of readers: ");
    scanf("%d", &n1);
    printf("\nEnter the number of writers: ");
    scanf("%d", &n2);

    initialize();

    pthread_t readers[n1], writers[n2];

    for (i = 0; i < n1; i++) {
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    for (i = 0; i < n2; i++) {
        pthread_create(&writers[i], NULL, writer, NULL);
    }

    for (i = 0; i < n1; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < n2; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy mutexes after use
    pthread_mutex_destroy(&x);
    pthread_mutex_destroy(&wsem);

    return 0;
}
