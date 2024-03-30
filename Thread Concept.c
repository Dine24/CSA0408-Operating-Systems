#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *thread_function(void *arg) {
int thread_id = *((int *)arg);
printf("Thread %d is running\n", thread_id);
sleep(2);
printf("Thread %d is exiting\n", thread_id);
pthread_exit(NULL);
}
int main() {
pthread_t thread1, thread2;
int id1=1,id2=2;
if (pthread_create(&thread1, NULL, thread_function, &id1) != 0) {
perror("Error creating thread 1");
exit(EXIT_FAILURE);
}
if (pthread_create(&thread2, NULL, thread_function, &id2) != 0) {
perror("Error creating thread 2");
exit(EXIT_FAILURE);
}
if (pthread_join(thread1, NULL) != 0) {
perror("Error joining thread 1");
exit(EXIT_FAILURE);
}
if (pthread_join(thread2, NULL) != 0) {
perror("Error joining thread 2");
exit(EXIT_FAILURE);
}
printf("Main thread exiting\n");
if (pthread_equal(thread1, thread2)) {
printf("Threads are equal\n");
} else {
printf("Threads are not equal\n");
}

return 0;
}

