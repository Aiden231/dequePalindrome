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

//���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init_queue(DequeType* qptr)
{
	qptr->front = 0;
	qptr->rear = 0;
}

// ���� �˻�
int is_empty(DequeType* qptr)
{
	return (qptr->front == qptr->rear);
}

// ��ȭ �˻�
int is_full(DequeType* qptr)
{
	return ((qptr->rear + 1) % MAX_QUEUE_SIZE == qptr->front);
}

// ���� �Լ�
void add_rear(DequeType* qptr, element item)
{
	if (is_full(qptr)) {
		printf("ť�� ��ȭ�����Դϴ�.\n");
		return;
	}

	qptr->rear = (qptr->rear + 1) % MAX_QUEUE_SIZE;
	qptr->data[qptr->rear] = item;
}

// ���� �Լ�
element delete_front(DequeType* qptr)
{
	if (is_empty(qptr)) {
		// printf("ť�� ��������Դϴ�.\n");
	}

	qptr->front = (qptr->front + 1) % MAX_QUEUE_SIZE;
	return qptr->data[qptr->front];
}

// �����Լ�
element get_front(DequeType* qptr)
{
	if (is_empty(qptr))
	{
		printf("ť�� ��������Դϴ�.\n");
		return;
	}

	return qptr->data[(qptr->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* qptr, element val)
{
	if (is_full) {
		printf("ť�� ��ȭ�����Դϴ�.\n");
		return;
	}
	
	qptr->data[qptr->front] = val;
	qptr->front = (qptr->front + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* qptr)
{
	int prev = qptr->rear;
	if (is_empty(qptr)) {
		// printf("ť�� ��������Դϴ�.\n");
		return;
	}

	qptr->rear = (qptr->rear + MAX_QUEUE_SIZE - 1) % MAX_QUEUE_SIZE;
	
	return qptr->data[prev];
}

element get_rear(DequeType* qptr)
{
	if (is_empty) {
		printf("ť�� ��������Դϴ�.\n");
		return;
	}

	return qptr->data[qptr->rear];
}

// ����ť ��� �Լ�
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
		char enter[MAX_QUEUE_SIZE]; // �Է� ���� ���� ����
		char word[MAX_QUEUE_SIZE]; // ��ȯ�� �ܾ� ����

		DequeType* q;
		init_queue(&q);

		printf("���ڿ��� �Է��ϼ���(�����ϰ� ������ exit �Է�) : ");
		scanf_s("%[^\n]s", enter, MAX_QUEUE_SIZE); // enter������ ������ ��� �� ����

				// exit �Է½� ����
		if (strcmp(enter, "exit") == 0) {
			printf("Program exit\n");
			break;
		}
		// word �迭 �ʱ�ȭ
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			word[i] = 0;
		}

		// �빮��->�ҹ���, Ư����ȣ ����
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

		// ȸ�� �Ǻ� �Լ�
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

		getchar(); // ���ۿ� ���� ���๮�� ó��
	} while (1);

	return 0;
}
