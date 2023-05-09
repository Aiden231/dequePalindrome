#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 20

typedef char element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}DequeType;

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init_queue(DequeType* qptr)
{
	qptr->front = 0;
	qptr->rear = 0;
}

// 공백 검사
int is_empty(DequeType* qptr)
{
	return (qptr->front == qptr->rear);
}

// 포화 검사
int is_full(DequeType* qptr)
{
	return ((qptr->rear + 1) % MAX_QUEUE_SIZE == qptr->front);
}

// 삽입 함수
void add_rear(DequeType* qptr, element item)
{
	if (is_full(qptr)) {
		printf("큐가 포화상태입니다.\n");
		return;
	}

	qptr->rear = (qptr->rear + 1) % MAX_QUEUE_SIZE;
	qptr->data[qptr->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* qptr)
{
	if (is_empty(qptr)) {
		// printf("큐가 공백상태입니다.\n");
	}

	qptr->front = (qptr->front + 1) % MAX_QUEUE_SIZE;
	return qptr->data[qptr->front];
}

// 삭제함수
element get_front(DequeType* qptr)
{
	if (is_empty(qptr))
	{
		printf("큐가 공백상태입니다.\n");
		return;
	}

	return qptr->data[(qptr->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* qptr, element val)
{
	if (is_full) {
		printf("큐가 포화상태입니다.\n");
		return;
	}
	
	qptr->data[qptr->front] = val;
	qptr->front = (qptr->front + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* qptr)
{
	int prev = qptr->rear;
	if (is_empty(qptr)) {
		// printf("큐가 공백상태입니다.\n");
		return;
	}

	qptr->rear = (qptr->rear + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
	
	return qptr->data[prev];
}

element get_rear(DequeType* qptr)
{
	if (is_empty) {
		printf("큐가 공백상태입니다.\n");
		return;
	}

	return qptr->data[qptr->rear];
}

// 원형큐 출력 함수
void deque_print(DequeType* qptr)
{
	printf("DEQUE(front=%d rear=%d) = ", qptr->front, qptr->rear);
	if (!is_empty(&qptr)) {
		int i = qptr->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%c |", qptr->data[i]);
			if (i == qptr->rear) break;
		} while (i != qptr->front);
	}
	printf("\n");
}


int main()
{
	do {
		char enter[MAX_QUEUE_SIZE]; // 입력 받은 문자 저장
		char word[MAX_QUEUE_SIZE]; // 변환된 단어 저장

		DequeType* q;
		init_queue(&q);

		printf("문자열을 입력하세요(종료하고 싶으면 exit 입력) : ");
		scanf_s("%[^\n]s", enter, MAX_QUEUE_SIZE); // enter나오기 전까지 모든 값 저장

				// exit 입력시 종료
		if (strcmp(enter, "exit") == 0) {
			printf("Program exit\n");
			break;
		}
		// word 배열 초기화
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			word[i] = 0;
		}

		// 대문자->소문자, 특수기호 제거
		int len = strlen(enter);

		for (int i = 0; i < len; i++)
		{
			if ('a' <= enter[i] && enter[i] <= 'z') {
				add_rear(&q, enter[i]);
			}
			else if ('A' <= enter[i] && enter[i] <= 'Z') {
				add_rear(&q, enter[i] - ('A' - 'a'));
			}
		}

		int num = 0;

		// 회문 판별 함수
		while (!is_empty(&q))
		{
			char check1 = delete_front(&q);
			char check2 = delete_rear(&q);

			if (check1 != check2)
			{
				num++;
			}

			if (is_empty(&q)) num--;
		}

		if (num == 0) {
			printf("%s is a palindrome\n", enter);
		}
		else {
			printf("%s is not a palindrome\n", enter);
		}
		printf("\n");

		getchar(); // 버퍼에 남은 개행문자 처리
	} while (1);

	return 0;
}
