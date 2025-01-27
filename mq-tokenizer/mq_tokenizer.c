
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>

#define MAX_TOKEN_SIZE 20
#define QUEUE_NAME "/token_queue"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE MAX_TOKEN_SIZE
#define MSG_BUFFER_SIZE (MAX_MSG_SIZE + 10)

typedef struct {
    char input_stream[1024];
} InputData;

void *tokenize(void *arg) {
    InputData *data = (InputData *)arg;
    char *token = strtok(data->input_stream, "#");
    mqd_t mq = mq_open(QUEUE_NAME, O_WRONLY);

    if (mq == (mqd_t)-1) {
        perror("mq_open");
        pthread_exit(NULL);
    }

    while (token != NULL) {
        if (strlen(token) > MAX_TOKEN_SIZE) {
            char truncated[MAX_TOKEN_SIZE + 1];
            strncpy(truncated, token, MAX_TOKEN_SIZE);
            truncated[MAX_TOKEN_SIZE] = '\0';
            mq_send(mq, truncated, strlen(truncated) + 1, 0);
        } else {
            mq_send(mq, token, strlen(token) + 1, 0);
        }
        token = strtok(NULL, "#");
    }

    mq_close(mq);
    pthread_exit(NULL);
}

void *print_tokens(void *arg) {
    mqd_t mq = mq_open(QUEUE_NAME, O_RDONLY);
    char buffer[MSG_BUFFER_SIZE];

    if (mq == (mqd_t)-1) {
        perror("mq_open");
        pthread_exit(NULL);
    }

    while (1) {
        ssize_t bytes_read = mq_receive(mq, buffer, MSG_BUFFER_SIZE, NULL);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Token: %s\n", buffer);
        }
    }

    mq_close(mq);
    pthread_exit(NULL);
}

int main() {
    pthread_t tokenizer_thread, printer_thread;
    InputData data;

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    mq_unlink(QUEUE_NAME);
    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, QUEUE_PERMISSIONS, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }
    mq_close(mq);

    printf("Enter input stream: ");
    fgets(data.input_stream, sizeof(data.input_stream), stdin);
    data.input_stream[strcspn(data.input_stream, "\n")] = 0;

    pthread_create(&tokenizer_thread, NULL, tokenize, &data);
    pthread_create(&printer_thread, NULL, print_tokens, NULL);

    pthread_join(tokenizer_thread, NULL);
    pthread_cancel(printer_thread);

    mq_unlink(QUEUE_NAME);
    return 0;
}
