#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define SHM_SIZE 1024

int main() {
int shmid;
key_t key;
char *shm_ptr;
char buffer[SHM_SIZE];

// Generate a unique key
key = ftok(".", 'a');
if (key == -1) {
perror("ftok");
exit(EXIT_FAILURE);
}

// Create a shared memory segment
shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
if (shmid == -1) {
perror("shmget");
exit(EXIT_FAILURE);
}

// Attach the shared memory segment
shm_ptr = shmat(shmid, NULL, 0);
if (shm_ptr == (char *)-1) {
perror("shmat");
exit(EXIT_FAILURE);
}

// Writing data to the shared memory
printf("Enter data to write to shared memory: ");
if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
perror("fgets");
exit(EXIT_FAILURE);
}
strncpy(shm_ptr, buffer, SHM_SIZE - 1); // Ensure null-terminated string
shm_ptr[SHM_SIZE - 1] = '\0'; // Null terminate explicitly

// Notify the reader that data is ready
printf("Data has been written to shared memory. Notifying the reader.\n");
*shm_ptr = '%'; // Notify by writing to shared memory
shm_ptr = NULL; // Reset shm_ptr

// Wait for the reader to finish reading
while (1) {
shm_ptr = shmat(shmid, NULL, 0); // Reattach the shared memory segment
if (shm_ptr == (char *)-1) {
perror("shmat");
exit(EXIT_FAILURE);
}
if (*shm_ptr == '%') {
break;
}
sleep(1);
}

// Detach the shared memory segment
if (shmdt(shm_ptr) == -1) {
perror("shmdt");
exit(EXIT_FAILURE);
}

// Delete the shared memory segment
if (shmctl(shmid, IPC_RMID, NULL) == -1) {
perror("shmctl");
exit(EXIT_FAILURE);
}

return 0;
}
