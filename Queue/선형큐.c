//선형큐

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;           
typedef struct {
	int front;  //큐의 헤드
	int rear;   //큐의 테일
	element data[MAX_QUEUE_SIZE];
}QueueType;

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐의 front와 rear을 -1로 초기화시켜준다.
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

//큐 출력해주는 함수
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

//큐의 포화상태(rear가 큐의 맨 끝을 가리키고 있을 때 1 반환)
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

//큐의 공백상태(front와 rear가 같은 곳을 가리키고 있을 때 1 반환)
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//큐에 원소를 추가해주는 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;       //큐가 포화상태가 아니면 rear를 1 증가시켜준 뒤, item을 해당 칸에 넣어준다
}

//큐에서 원소를 제거하여 반환하는 함수
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];      //큐가 공백상태가 아니면 front를 1 증가시켜준 뒤 해당 칸의 값을 item에 넣어주고
	return item;                           //item을 반환한다
}

int main(void)
{
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);        //front = -1, rear = 0
	enqueue(&q, 20); queue_print(&q);        //front = -1, rear = 1
	enqueue(&q, 30); queue_print(&q);        //front = -1, rear = 2


	item = dequeue(&q); queue_print(&q);     //front = 0, rear = 2
	item = dequeue(&q); queue_print(&q);     //front = 1, rear = 2
	item = dequeue(&q); queue_print(&q);     //front = 2, rear = 2

	
	return 0;
}


//[실행결과]

//10 |    |    |    |    |
//10 | 20 |    |    |    |
//10 | 20 | 30 |    |    |
//   | 20 | 30 |    |    |
//   |    | 30 |    |    |
//   |    |    |    |    |
