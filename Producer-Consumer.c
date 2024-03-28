#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // for usleep function

#define BUFFER_SIZE 5

sem_t empty, full;
pthread_mutex_t mutex;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
int item = 1;
while (1) {
sem_wait(&empty); // Wait for an empty slot in the buffer
pthread_mutex_lock(&mutex);

// Produce item
buffer[in] = item;
printf("Produced: %d\n", item);
item++;
in = (in + 1) % BUFFER_SIZE;

pthread_mutex_unlock(&mutex);
sem_post(&full); // Increment the count of full slots

usleep(500000); // Sleep for 500 milliseconds
}
pthread_exit(NULL);
}

void *consumer(void *arg) {
while (1) {
sem_wait(&full); // Wait for a full slot in the buffer
pthread_mutex_lock(&mutex);

// Consume item
int item = buffer[out];
printf("Consumed: %d\n", item);
out = (out + 1) % BUFFER_SIZE;

pthread_mutex_unlock(&mutex);
sem_post(&empty); // Increment the count of empty slots

usleep(500000); // Sleep for 500 milliseconds
}
pthread_exit(NULL);
}

int main() {
pthread_t producer_thread, consumer_thread;
pthread_mutex_init(&mutex, NULL);
sem_init(&empty, 0, BUFFER_SIZE); // Initialize empty semaphore with buffer size
sem_init(&full, 0, 0); // Initialize full semaphore with 0

// Create producer and consumer threads
pthread_create(&producer_thread, NULL, producer, NULL);
pthread_create(&consumer_thread, NULL, consumer, NULL);

// Wait for threads to finish (which will never happen, but for demonstration purpose)
pthread_join(producer_thread, NULL);
pthread_join(consumer_thread, NULL);

// Destroy semaphores and mutex
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutex);

return 0;
}

