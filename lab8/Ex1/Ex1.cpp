#include <iostream>

const int SIZE = 5;

struct Queue{
    int front;
    int rear;
    int Q[SIZE];

    Queue(){
        front = -1;
        rear = -1;
    }
};

void enqueue(Queue* q, int data){
    if(isFull(q)){
        std::cout << "Queue is full\n";
        return;
    }

    if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else{
        q->rear++;
    }

    q->Q[q->rear] = data;
    return;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        std::cout << "Queue is empty\n";
        return;
    }

    int value = q->Q[q->front];
    std::cout << "Dequeue: " << value << std::endl;
    q->Q[q->front] = 0;
    if(q->front = q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front++;
    }
    return value;
}

int front(Queue* q){
    return q->Q[q->front];
}

bool isEmpty(Queue* q){
    return (q->front == -1 || q->front > q->rear);
}

bool isFull(Queue* q){
    return (q->rear == SIZE - 1);
}

void displayQueue(Queue* q){
    if(isEmpty(q)){
        std::cout << "Queue is empty";
        return;
    }

    for(int i = 0; i < SIZE -1; i++){
        std::cout << q->Q[i] << " ";
    }
    std::cout << std::endl;
}

int getSize(Queue* q){
    if(isEmpty(q)) return 0;
    return (q->rear - q->front + 1);
}

int main(){
    Queue* q = new Queue();
    dequeue(q);
    enqueue(q, 5);
    enqueue(q,2);
    dequeue(q);
    enqueue(q,3);
    displayQueue(q);
    getSize(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    return 0;
}