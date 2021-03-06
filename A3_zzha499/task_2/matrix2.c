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
    /* variables for task 2 */
    double t1, t2;
    unsigned int i;
    unsigned int N = 1000;
    unsigned int M = 3;
    
    

    /* declare variables; examples, adjust for task */
    double** a;
    double** b;
    double** c;
    double** tempMTX;
    double SUM_of_AB;
    double swap;
    unsigned int j;
    unsigned int k;
    unsigned int occured;

    /* allocate memory for arrays; examples, adjust for task */
    a = malloc(N * sizeof(double**));
    b = malloc(N * sizeof(double**));
    c = malloc(N * sizeof(double**));
    tempMTX = malloc(N * sizeof(double**));

    for (i = 0; i < N; i++) {
        a[i] = malloc(N * sizeof(double));
        b[i] = malloc(N * sizeof(double));
        c[i] = malloc(N * sizeof(double));
        tempMTX[i] = malloc(N * sizeof(double));
    }

    /* initialise arrray elements */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
            tempMTX[i][j] = 1;
        }
    }

    t1 = getTime();

    /* code to be measured goes here */
    /***************************************/

    // Temporary 2D array updated
    for (occured = 0; occured < M; occured++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (i + j < N) {
                    tempMTX[j][i] = b[i][j];
                }
            }
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                SUM_of_AB = 0;
                for (k = 0; k < N; k++) {
                    SUM_of_AB += (a[i][k] * tempMTX[j][k]);
                }
                c[i][j] = SUM_of_AB;
            }
        }
    }
    /***************************************/
    t2 = getTime();

    /* output; examples, adjust for task */
    printf("Total Time: %6.2f secs\n", (t2 - t1));

    /* IMPORTANT: also print the result of the code, e.g. the SUM_of_AB,
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
    free(tempMTX);

    return 0;
}
