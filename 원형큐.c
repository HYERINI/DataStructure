//원형큐

#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;            //front : 첫번째 요소 하나 앞의 인덱스, rear : 마지막 요소의 인덱스
}QueueType;

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//원형큐 초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;     //선형큐와 달리 front와 rear를 0으로 초기화한다
}

//공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);  //front와 rear의 위치가 같음
}

//포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);     //큐의 마지막 인덱스 다음 인덱스가 0이 될 수 있게 함
}

//원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) =", q->front, q->rear);          //현재 front와 rear위치 출력
	if (!is_empty(q)) {
		int i = q->front;          //i는 front 위치
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);           //이렇게 해야 마지막 인덱스의 다음 인덱스 = 0    
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;               //i가 q->rear 이면 반복문 탈출
		} while (i != q->front);             //i가 front를 가리키지 않고 있을 때 반복
	}
	printf("\n");
}

//삽입함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");               //큐가 포화상태면 에러 메시지
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;          //rear하나 증가 시켜줌 (맨 끝 위치일 때에는 다음위치가 0이 됨)
	q->data[q->rear] = item;                           //증가시켜준 rear 위치에 item 넣어준다.
}

//삭제함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");              //큐가 공백상태면 에러 메시지
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;       //front하나 증가 시켜줌 (맨 끝 위치일 때에는 다음위치가 0이 됨)
	return q->data[q->front];                         //증가시켜준 front위치에 있는 item을 반환
}

int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);             //큐 초기화
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))       //포화상태 아닐 때
	{
		printf("정수를 입력하시오: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);    //입력받은 element 큐에 넣어주고
		queue_print(&queue);         //현재 큐 모습 출력
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))     //공백상태 아닐 때
	{
		element = dequeue(&queue);      //반환시켜준 q->data[q->front]값을 element에 넣어주고
		printf("꺼내진 정수: %d\n", element);   //element 출력
		queue_print(&queue);     //현재 큐 모습 
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
