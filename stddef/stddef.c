#include <stdio.h>
//#include <stddef.h>

#define offsetof(type, member)	        ((size_t)(((void *)&((type *)0)->member) - (void *)0))
#define container_of(ptr, type, member) ({ \
						const typeof(((type *)0)->member) *__mptr = (ptr);\
						(type *)((void *)(__mptr) - offsetof(type, member));})

struct student{
	int num;
	int name[20];
	float score;
};

int main()
{
	int i, j, k, l;
	void *p;
	struct student st1;

	p = &i;
	i = 10;
	j = 100;
	k = 1000;
	l = 10000;

	printf("j = %d\n", ((struct student *)&i)->name[0]);

//	printf("name offset os student is %d\n", (int)offsetof(struct student, name));
	printf("score offset of student is %d\n", (int)(((void *)&((struct student *)10)->score) - (void *)10));
	printf("score offset of student is %d\n", (int)offsetof(struct student, score));
	printf("st1 address is %p\n", &st1);
	printf("st1 address is %p\n", container_of(&st1.score, struct student, score));

}


