/*int�� ���� intset(���)*/
#ifndef ___IntSet
#define ___InstSet

/*---int�� ������ �����ϴ� ����ü---*/
typedef struct {
	int max;
	int num;
	int* set;
} IntSet;

/*--- ���� �ʱ�ȭ---*/
int Initialize(IntSet* s ,int max);

/*--- ���� s�� n�� ����ִ��� Ȯ��---*/
int IsMember(const IntSet* s, int n);

/*--- ���� s�� n�� �߰�---*/
void Add(intSet* s, int n);

/*---���� s���� n�� ����---*/
void Remove(IntSet* s, int n);

/*--- ���� s�� ������ �ִ� �ִ� ���� ������ ��ȯ ---*/
int Capacity(const IntSet* s);

/*--- ���� s�� ���� ����---*/
int Size(const IntSet* s);

/*--- ���� s2�� s1�� ����---*/
void Assign(IntSet* s1, const IntSet* s2);

/*--- ���� s1�� s2�� ������ Ȯ��---*/
int Equl(const IntSet* s1, const IntSet* s2);

/*---���� s2�� s3�� �������� s1�� ����---*/
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3);

/*--- ���� s2�� s3�� �������� s1�� ����---*/
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3);

/*--- ���� s2���� s3�� �� �������� s1�� ���� ---*/
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet * 3);

/*--- ���� s�� ��� ���� ��� ---*/
void print(const IntSet* s);

/*---���� s�� ��� ���Ҹ� ���(�� �ٲ޹��� ����)---*/
void printLn(const IntSet* s);

/*---���� ����---*/
void Terminate(IntSet* s);
#endif


/*--- �ǽ� 7-2[A]---*/

/*--- int�� ���� intSet(�ҽ�)---*/
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntSet* s, int max)
{
	s->sum = 0;
	if ((s->set = (int*)calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- ���� s�� n�� ��� �ִ��� Ȯ�� ---*/
int IsMember(const IntSet* s, int n)
{
	int i;
	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;
	return -1;

}

/*--- ���� s�� n�� �߰�---*/
void Add(IntSet* s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)
		s->set[s->num++] = n;
}

/* ---���� s���� n������ ---*/
void Remove(IntSet* s, int n)
{
	int idx;
	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];
	}
}



/* --- �ǽ� 7-2[B] ---*/

/*--- ���� s�� ���� �� �ִ� �ִ��� ���� ������ ��ȯ ---*/
int Capacity(const IntSet* s)
{
	return s->max;
}

/*--- ���� s�� ���� ������ ��ȯ---*/
int Size(const IntSet* s)
{
	return s->num;
}

/* --- ���� s2�� s1�� ����---*/
void Assign(IntSet* s1, const IntSet* s2)
{
	int i;
	int n = (s1->max < s2->max) ? s1->max : s2->num;
	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

/* --- ���� s1�� s2�� ������ Ȯ��---*/
int Equal(const IntSet* s1, const IntSet* s2)
{
	int i, j;
	if (Size(s1) != Size(s2))
		return 0;
	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2 -> num; j++)
			if (s1 - > set[i] == s2->set[j])
				break;
		if (j == s2->num)
			return 0;
	}
	return 1;
}

/* --- ���� s�� s3�� �������� s1�� ����---*/
intSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i;
	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);
	return s1;
}