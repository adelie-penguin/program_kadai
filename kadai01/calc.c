/* vim: set tabstop=4 : */
/****************************************************************************
 *
 * 連立一次方程式の求解
 *
 *---------------------------------------------------------------------------
 *
 * コンパイル $gcc calc.c
 * 実行       $./a.out  [arg1]
 *
 *---------------------------------------------------------------------------
 *  show_matrix()関数: 20元以下の行列を表示
 *
 ****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

/*==========================================================*/
/* この関数の中で方程式を求解する 							*/
/*==========================================================*/
void calc_matrix(double **A, double *b, int size)
{

}

/*==========================================================*/
/* 問題生成(密行列)											*/
/*==========================================================*/
void set_matrix(double **A, double *b, int size)
{
	int i, j;

	for(i = 0; i < size; i++)
	{
		b[i] = 0.0;
		for(j = 0; j < size; j++)
		{
			A[i][j] = (rand() % 21) - 10;
			b[i] += A[i][j] * j;		
		}
		A[i][i] += size * 10;
		b[i] += size * 10 * i;		
	}
}
/*==========================================================*/
/* 行列表示													*/
/*==========================================================*/
void show_matrix(double **A, double *b, int size)
{
	int i, j;

	if(size > 20)
	{
		fprintf(stderr, ">> (line%d) 行列サイズが大きいので表示省略 \n", __LINE__);
		return;
	}

	fprintf(stdout, "\n");
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size ; j++)
		{
			fprintf(stdout, "%4.0lf ", A[i][j]);
		}
		fprintf(stdout, "| %4.0lf\n", b[i]);
	}
	fprintf(stdout, "\n");
}

/*==========================================================*/
/* 時間測定用 												*/
/*==========================================================*/
#ifdef ___WIN
typedef time_t time_data;
#define TIME_SET_START()	stime = clock()
#define TIME_PRINT()	etime = clock();							\
								fprintf(stdout, ">> 実行時間 %f[ms]\n", 		\
								(float)(etime - stime) * 1000.0/ CLOCKS_PER_SEC)
#else
#include<sys/time.h>
typedef struct timeval time_data;
#define TIME_SET_START()	gettimeofday(&stime, NULL);
#define TIME_PRINT()	gettimeofday(&etime, NULL);					\
	fprintf(stdout, ">> 実行時間 %f[ms]\n", 		\
			(etime.tv_sec-stime.tv_sec) * 1000.0 + 	\
			(etime.tv_usec-stime.tv_usec) * 0.001)
#endif


/*==========================================================*/
/* メイン関数 												*/
/*==========================================================*/
int main(int argc, char *argv[])
{
	int i; 
	double **A;				/* 係数行列 */
	double *b;				/* 定数ベクトル */
	int size = 10;			/* 行列サイズ */

	time_data stime, etime;	/* 時間測定用の変数定義 */
	double err;				/* 計算誤差 */

	if(argc == 2)
	{
		size = atoi(argv[1]);
	}

	if(size <= 0)
	{
		fprintf(stderr, ">> (line%d) argument[1] is matrix size.\n", __LINE__);
		exit(1);
	}

	if((b = (double*)malloc(sizeof(double) * size)) == NULL)
	{
		fprintf(stderr, ">> line%d malloc error.\n", __LINE__);
		exit(1);
	}
	if((A = (double**)malloc(sizeof(double*) * size)) == NULL)
	{
		fprintf(stderr, ">> line%d malloc error.\n", __LINE__);
		exit(1);
	}
	if((A[0] = (double*)malloc(sizeof(double) * size * size)) == NULL)
	{
		fprintf(stderr, ">> line%d malloc error.\n", __LINE__);
		exit(1);
	}
	for(i = 1; i < size; i++)
	{
		A[i] = &(A[0][size * i]);
	}

	srand(time(NULL));
	set_matrix(A, b, size);
	show_matrix(A, b, size);
	TIME_SET_START();
	calc_matrix(A, b, size);
	TIME_PRINT(); 

	err = 0.0;
	for(i = 0; i < size; i++)
	{
		err = (fabs(b[i] - i) > err)? fabs(b[i] - i): err;
	}
	fprintf(stdout, ">> 問題サイズ %d\n"
			">> 計算結果の最大誤差 %lf\n", size, err);

	free(A[0]);
	free(A);
	return(0);
}
