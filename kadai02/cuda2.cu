/* vim: set tabstop=4 : */
/****************************************************************************
 * cuda のおためしプログラム
 *----------------------------------------------------------------------
 *
 * コンパイルコマンド
 * $make
 * 実行コマンド
 * $./cuda2 
 *
 ****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* CUDAが無効な状態でも実行したい場合はこのifdefに代替コードを記述 */
#ifdef __CUDACC__
#include<cuda_runtime.h>
#define penguin_print()	fprintf(stdout, ">> with cuda\n")
#else
#define penguin_print()	fprintf(stdout, ">> without cuda\n")
#endif
/*------------*/

#define BLOCK_MAX   2	/* スレッドブロック数 */
#define BLOCK_SIZE  4	/* スレッド数 */

__global__ void function(void);

int main(int argc, char *argv[])
{
	penguin_print();
	function<<<BLOCK_MAX, BLOCK_SIZE>>>();
	cudaDeviceReset();
	return(0);
}

__global__ void function(void)
{
	printf(">> block%d thread%d \n", blockIdx.x, threadIdx.x);
}
