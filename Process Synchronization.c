#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;

void *thread_function(void *thread_id) {
int tid = *((int*)thread_id);

// Lock the mutex before accessing shared resources
pthread_mutex_lock(&mutex);

// Critical section
printf("Thread %d is entering the critical section.\n", tid);
printf("Thread %d is in the critical section.\n", tid);
printf("Thread %d is leaving the critical section.\n", tid);

// Unlock the mutex after accessing shared resources
pthread_mutex_unlock(&mutex);

pthread_exit(NULL);
}

int main() {
pthread_t threads[NUM_THREADS];
int thread_ids[NUM_THREADS];

// Initialize the mutex
pthread_mutex_init(&mutex, NULL);

// Create threads
int i;
for (i = 0; i < NUM_THREADS; ++i) {
thread_ids[i] = i;
pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
}

// Join threads
for (i = 0; i < NUM_THREADS; ++i) {
pthread_join(threads[i], NULL);
}

// Destroy the mutex
pthread_mutex_destroy(&mutex);

return 0;
}

