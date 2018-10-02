#include <stdio.h>

typedef struct studentResults {
	int ass1, ass2, exam;
	float total;
	char grade;
} StudentType;

void calculateGrade(StudentType *student){
	student->total = student->ass1 * 0.2
	                 + student->ass2 * 0.3
	                 + student->exam * 0.5;
	if (student->total < 50)
		student->grade = 'N';
	else if (student->total < 60)
		student->grade = 'P';
	else if (student->total < 70)
		student->grade = 'C';
	else if (student->total < 80)
		student->grade = 'D';
	else
		student->grade = 'H';
}

int main(void){

	StudentType s;

	s.ass1 = 20;
	s.ass2 = 60;
	s.exam = 65;
	calculateGrade(&s);
	printf("Total %.2f  Grade %c\n",s.total,s.grade);
	return 0;
}
