#include <stdio.h> // Standard In/Out contains printf()
#include <limits.h> // Contains INT_MAX and INT_MIN
#include <float.h> // Contains FLT_EPSILON, DBL_EPSILON and LDBL_EPSILON
#include <string.h> // Contains e.g. strcpy()
#include <stdlib.h> // Contains e.g. exit(), EXIT_FAILURE and EXIT_SUCCESS

/*
 * Prints a string of dashes. No new line at the end.
 */
void printDashes(void){
	printf("----------");
}

/*
 * Prints the exercise number surrounded by dashes.
 *
 * exercise: String containing the exercise name and number.
 */
void printExercise(char exercise[]){
	printDashes();
	printf(" %s ", exercise);
	printDashes();
	printf("\n");
}

/*
 * Printing the maximum or minimum integer found
 *
 * maxOrMin: String
 */
void printMaxMinInt(char maxOrMin[], char loop[], int integer){
	printf("My %s int for the %s is %i\n", maxOrMin, loop, integer);
}

/*
 * Function pointer to an integer operation.
 */
int (*intOperation)(int x, int y);

/*
 * Calculates if one integer is less than another.
 *
 * x: Integer value to compare with y.
 * y: Integer value which x is compared to.
 *
 * returns 1 if true and 0 if false
 */
int lessThan(int x, int y){
	return x < y;
}

/*
 * Calculates if one integer is larger than another.
 *
 * x: Integer value to compare with y.
 * y: Integer value which x is compared to.
 *
 * returns 1 if true and 0 if false.
 */
int greatherThan(int x, int y){
	return x > y;
}

/*
 * Calculates
 */
void calculateMaxMinInt(int posNeg){
	// Sets variables corresponding to max or min depending on the variable posNeg
	char maxMin[10];
	char intMaxMinName[10];
	int intMaxMin;
	if (posNeg == 1) {
		strcpy(maxMin, "max");
		strcpy(intMaxMinName, "INT_MAX");
		intMaxMin = INT_MAX;
		intOperation = greatherThan;
	} else if (posNeg == -1) {
		strcpy(maxMin, "min");
		strcpy(intMaxMinName, "INT_MIN");
		intMaxMin = INT_MIN;
		intOperation = lessThan;
	} else {
		printf("ERROR: posNeg shall be either +1 or -1 but were %i.\n", posNeg);
		exit(EXIT_FAILURE);
	}
	// Actual MAX_INT or MIN_INT
	printMaxMinInt(maxMin, intMaxMinName, intMaxMin);
	// Initialise integer variable
	int i;
	// for loop
	for (i = intMaxMin - 10; intOperation(i+(posNeg*1), i); i = i + posNeg) {}
	printMaxMinInt(maxMin, "for loop", i);
	// while loop
	i = posNeg;
	while (intOperation(i+(posNeg*1), i)) {
		i = i + posNeg;
	}
	printMaxMinInt(maxMin, "while loop", i);
	// do while loop
	i = posNeg;
	do {
		i = i + posNeg;
	} while (intOperation(i+(posNeg*1), i));
	printMaxMinInt(maxMin, "do while loop", i);
}

void solutionExercise1(void){
	printExercise("Exercise 1");
	// Part i
	printExercise("i");
	calculateMaxMinInt(1);
	// Part ii
	printExercise("ii");
	calculateMaxMinInt(-1);
	// Parti iii
	printExercise("iii");
}

int main(void){
	solutionExercise1();
	/*solutionExercise2();
	solutionExercise3();
	solutionExercise4();*/
}
