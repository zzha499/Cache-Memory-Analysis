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

/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main(int argc, char* argv[])
{
	/* variables for task 1 */
	double t1, t2;
	unsigned int MList[10] = { 1000, 1000, 500, 500, 200, 200, 100, 100, 100,100 };
	unsigned int NList[10] = { 1024, 4096, 16384, 65536, 262144, 1048576, 2097152, 4194304, 16777216, 33554432 };
	unsigned int M;
	unsigned int N;
	unsigned int i, j, k;

	/* declare variables; examples, adjust for task */
	int *a, *b;
	//double  a[100];
	long rand_Num;
	unsigned int result;

	for (k = 0; k < 10; k++)
	{
		M = MList[k];
		N = NList[k];

		/* parameter parsing task 1 */
		for (i = 1; i < (unsigned)argc; i++) {
			if (strcmp(argv[i], "--repetitions") == 0) {
				i++;
				if (i < argc)
					sscanf(argv[i], "%u", &M);
				else
					usage();
			}
			else if (strcmp(argv[i], "--array_size") == 0) {
				i++;
				if (i < argc)
					sscanf(argv[i], "%u", &N);
				else
					usage();
			}
			else usage();
		}


		/* allocate memory for arrays; examples, adjust for task */
		a = malloc(N * sizeof(int));
		b = malloc(N * sizeof(int));

		/* initialise arrray elements */
		for (i = 0; i < N; i++)
		{
			a[i] = i;
		}
		for (i = 0; i < N; i++)
		{
			b[i] = i;
		}

		result = 0;

		t1 = getTime();

		/* code to be measured goes here */
		/***************************************/
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				result += a[b[j]];
			}
		}
		/***************************************/
		t2 = getTime();

		for (i = 0; i < N; i++)
		{
			// Generate a random index number that does not exceed N

			rand_Num = (rand()) % N;
			int rand_Num2 = (rand()) % N;

			// Swapping
			int temp = b[rand_Num];
			b[rand_Num] = b[rand_Num2];
			b[rand_Num2] = temp;
		}

		t1 = getTime();

		/* code to be measured goes here */
		/***************************************/
		for (i = 0; i < M; i++)
		{
			result = 0;
			for (j = 0; j < N; j++)
			{
				result += a[b[j]];
			}
		}
		/***************************************/
		printf("%u", result);
		t2 = getTime();

		printf("\nCase 2:\n");
		printf("Time per iteration: %6.10f ns\n", (t2 - t1) / N / M * 1000000000);
		printf("\n===========================================================\n");

		/* output; examples, adjust for task */
		//printf("time: %6.2f secs\n", (t2 - t1));

		/* IMPORTANT: also print the result of the code, e.g. the sum,
		 * otherwise compiler might optimise away the code */

		 /* free memory; examples, adjust for task */
		free(a);
		free(b);
	}
	return 0;
}
