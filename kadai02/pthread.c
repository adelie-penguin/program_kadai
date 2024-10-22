/* vim: set tabstop=4 : */
/****************************************************************************
 * pthread のおためしプログラム
 *----------------------------------------------------------------------
 *
 * コンパイルコマンド
 * $gcc -pthread pthread.c
 * 実行コマンド
 * $./a.out 
 *
 ****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define RANK_MAX	4	/* スレッド数 */

void* function(void*);

int main(int argc, char *argv[])
{
	int i;
	pthread_t rank[RANK_MAX];

	for(i = 0; i < RANK_MAX; i++)
	{
		pthread_create(&(rank[i]), NULL, function, (void*)0+i);
	}
	for(i = 0; i < RANK_MAX; i++)
	{
		pthread_join(rank[i], NULL);
	}	
	return(0);
}

void* function(void* argument)
{
	int rank = argument - (void*)0;
	fprintf(stdout, ">> thread:%d\n", rank);
}
