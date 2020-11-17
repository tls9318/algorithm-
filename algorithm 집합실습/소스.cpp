/*int형 집합 intset(헤더)*/
#ifndef ___IntSet
#define ___InstSet

/*---int형 집합을 관리하는 구조체---*/
typedef struct {
	int max;
	int num;
	int* set;
} IntSet;

/*--- 집합 초기화---*/
int Initialize(IntSet* s ,int max);

/*--- 집합 s에 n이 들어있는지 확인---*/
int IsMember(const IntSet* s, int n);

/*--- 집합 s에 n을 추가---*/
void Add(intSet* s, int n);

/*---집합 s에서 n을 삭제---*/
void Remove(IntSet* s, int n);

/*--- 집합 s에 넣을수 있는 최대 원소 개수를 반환 ---*/
int Capacity(const IntSet* s);

/*--- 집합 s의 원소 개수---*/
int Size(const IntSet* s);

/*--- 집합 s2를 s1에 대입---*/
void Assign(IntSet* s1, const IntSet* s2);

/*--- 집합 s1과 s2가 같은지 확인---*/
int Equl(const IntSet* s1, const IntSet* s2);

/*---집합 s2와 s3의 합집합을 s1에 대입---*/
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3);

/*--- 집합 s2와 s3의 교집합을 s1에 대입---*/
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3);

/*--- 집합 s2에서 s3을 뺀 차집합을 s1에 대입 ---*/
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet * 3);

/*--- 집합 s의 모든 원소 출력 ---*/
void print(const IntSet* s);

/*---집합 s의 모든 원소를 출력(줄 바꿈문자 포함)---*/
void printLn(const IntSet* s);

/*---집합 종료---*/
void Terminate(IntSet* s);
#endif


/*--- 실습 7-2[A]---*/

/*--- int형 집합 intSet(소스)---*/
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- 집합 초기화 ---*/
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

/*--- 집합 s에 n이 들어 있는지 확인 ---*/
int IsMember(const IntSet* s, int n)
{
	int i;
	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;
	return -1;

}

/*--- 집합 s에 n을 추가---*/
void Add(IntSet* s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)
		s->set[s->num++] = n;
}

/* ---집합 s에서 n을삭제 ---*/
void Remove(IntSet* s, int n)
{
	int idx;
	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];
	}
}



/* --- 실습 7-2[B] ---*/

/*--- 집합 s에 넣을 수 있는 최대의 원소 개수를 반환 ---*/
int Capacity(const IntSet* s)
{
	return s->max;
}

/*--- 집합 s의 원소 개수를 반환---*/
int Size(const IntSet* s)
{
	return s->num;
}

/* --- 집합 s2를 s1에 대입---*/
void Assign(IntSet* s1, const IntSet* s2)
{
	int i;
	int n = (s1->max < s2->max) ? s1->max : s2->num;
	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

/* --- 집합 s1과 s2가 같은지 확인---*/
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

/* --- 집합 s와 s3의 합집합을 s1에 대입---*/
intSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i;
	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);
	return s1;
}