/**
 * @file	calculator.c
 * @brief	Program to impliment a calculator using function pointers
 * @author	Jones <jonessos.ben@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "err.h"

/** Get a user input of specified type to variable 'x' */
#define getInput(type, x)		{			\
	if (!fscanf(stdin, type, &x))				\
		do_error_int(BAD_RETURN, __FILE__, __LINE__);	\
}
/** Print the result of the function, which was called based on user's choice */
#define do_op(x)			{			\
	fprintf(stdout, "\nresult: %f\n", 			\
			ops.x(numbers[0], numbers[1])); break;	\
}

/**
 * @brief	Pointers to functions doing the mathematical operation
 */
typedef struct {
	float (*add)(float, float);		/**< Pointer to 'add' function */
	float (*multiply)(float, float);	/**< Pointer to 'multiply' function */
	float (*subtract)(float, float);	/**< Pointer to 'subtract' function */
	float (*divide)(float, float);		/**< Pointer to 'divide' function */
} calculator;

static inline float ADD(float a, float b) { return a + b; }		/**< Returns the sum of two numbers */
static inline float MULTIPLY(float a, float b) { return a * b; }	/**< Returns the product of two numbers */
static inline float SUBTRACT(float a, float b) { return a - b; }	/**< Returns the difference of two numbers */
static inline float DIVIDE(float a, float b) { return a / b; }		/**< Returns the division of two numbers */

int main(void)
{
	int n = 2, ret = 0;
	char choice = '\0';
	float numbers[2] = {0, 0};
	calculator ops = {.add = ADD, .multiply = MULTIPLY, .subtract = SUBTRACT, .divide = DIVIDE};

	for (int i = 0; i < n; i++) {
		fprintf(stdout, "Input %d: ", i + 1); fflush(stdout);
		getInput("%f", numbers[i])
	}

	fprintf(stdout, "\n(a) add\n(b) multiply\n(c) subtract\n(d) divide\nWhich operation? "); fflush(stdout);
	do {
		getInput(" %c", choice);
		choice = tolower(choice);

		if (choice == 'a')
			do_op(add)
		else if (choice == 'b')
			do_op(multiply)
		else if (choice == 'c')
			do_op(subtract)
		else if (choice == 'd')
			do_op(divide)
		else
			fprintf(stderr, "\nInvalid choice\nWhich operation? ");
	} while (1);

exit:
	return ret;
}
