#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define N_THREADS 3
#define MAX_VAL 100

int summation = 0;

sem_t lock;

void* protect_critical_region(void* n) {
    int i = 0, thread_num = (int)(long)n;
    bool finished = false;

    while (!finished) {
        sem_wait(&lock);
        for (int j = 0; j < thread_num; ++j) {
            printf("\t\t\t");
        }
        printf("CRITICAL(T%d)\n", thread_num);
        sem_post(&lock);

        sleep(2);

        sem_wait(&lock);

        for (int j = 0; j < thread_num; ++j) {
            printf("\t\t\t");
        }
        printf("out of CRITICAL(T%d)\n", thread_num);
        sem_post(&lock);

        finished = (i++ > N_THREADS);

        sem_wait(&lock);
        for (int j = 0; j < thread_num; ++j) {
            printf("\t\t\t");
        }
        printf("into non-critical(T%d)\n", thread_num);
        sem_post(&lock);
    }
    return NULL;
}

/*void* adder(void* step){*/
    /*int s = (int)(long)step;*/
    /*if(summation + s <= MAX_VAL ){*/
        /*summation+=s;*/
    /*}*/
/*}*/

int main(int argc, const char* argv[]) {
    pthread_t tid[N_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    sem_init(&lock, 0, 1);

    for (int i = 0; i < N_THREADS; ++i) {
        pthread_create(&tid[i], &attr, protect_critical_region, (void*)(long)i);
    }

    for (int i = 0; i < N_THREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
    printf("\nall %d threads joined", N_THREADS);
    printf("\n\nEnd of program\n");

    return 0;
}
