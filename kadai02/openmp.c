/**********************************************************
 *
 * OpenMPの実験プログラム
 *
 *---------------------------------------------------------
 *
 * コンパイル
 * $gcc -fopenmp openmp.c 
 *
 * 実行コマンド
 * $./a.out
 *
 ***********************************************************/

#include<stdio.h>
#include<omp.h>

int main(void)
{
	int i;
	int sum = 0;
	double etime, stime;

	omp_set_num_threads(4);

	fprintf(stdout, ">> Thread_Max: %d\n", omp_get_max_threads());

	stime = omp_get_wtime();
	#pragma omp parallel for reduction(+:sum)
	for(i = 0; i < 10; i++)
	{
		fprintf(stdout, ">> thread%d: i=%d\n", omp_get_thread_num(), i);
		sum = i;
	}
	etime = omp_get_wtime();

	fprintf(stdout, ">> sum = %d\n", sum);
	fprintf(stdout, ">> time: %lf\n", etime - stime);
	return 0;
}
