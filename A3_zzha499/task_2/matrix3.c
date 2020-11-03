/* do not add other includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime() {
	struct timeval t;
	double sec, msec;

	while (gettimeofday(&t, NULL) != 0);
	sec = t.tv_sec;
	msec = t.tv_usec;

	sec = sec + msec / 1000000.0;
	return sec;
}

int main(int argc, char* argv[])
{
	/* declare variables; examples, adjust for task */
	double t1, t2;
	unsigned int M = 3;
	unsigned int N = 1000;
	unsigned int cacheLine_size = 64;

	double** a;
	double** b;
	double** c;
	double SUM_of_AB;
	unsigned int occured;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int NEW_J;
	unsigned int NEW_K;


	/* allocate memory for arrays; examples, adjust for task */
	a = malloc(N * sizeof(double**));
	b = malloc(N * sizeof(double**));
	c = malloc(N * sizeof(double**));

	for (i = 0; i < N; i++) {
		a[i] = malloc(N * sizeof(double));
		b[i] = malloc(N * sizeof(double));
		c[i] = malloc(N * sizeof(double));
	}

	/* initialise arrray elements */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			a[i][j] = 1;
			b[i][j] = 1;
			c[i][j] = 0;
		}
	}

	t1 = getTime();

	/* code to be measured goes here */
	/***************************************/

	for (occured = 0; occured < M; occured++) {
		for (NEW_J = 0; NEW_J < N; NEW_J += cacheLine_size) {
			for (NEW_K = 0; NEW_K < N; NEW_K += cacheLine_size) {
				for (i = 0; i < N; i++) {
					for (j = NEW_J; j < (N < NEW_J + cacheLine_size ? N : NEW_J + cacheLine_size); j++) {
						SUM_of_AB = c[i][j];
						for (k = NEW_K; k < (N < NEW_K + cacheLine_size ? N : NEW_K + cacheLine_size); k++) {
							SUM_of_AB += a[i][k] * b[k][j];
						}
						c[i][j] = SUM_of_AB;
					}
				}
			}
		}
	}

	t2 = getTime();

	/* output; examples, adjust for task */
	printf("Total Time: %6.2f secs\n", (t2 - t1));
	/* IMPORTANT: also print the result of the code.
	 * otherwise compiler might optimise away the code */
	 /* free memory; examples, adjust for task */
	for (i = 0; i < N; i++) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);

	return 0;
}
