/* vim: set tabstop=4 : */
/****************************************************************************
 * cuda のおためしプログラム
 *----------------------------------------------------------------------
 *
 * コンパイルコマンド
 * $make
 * 実行コマンド
 * $./cuda01 
 *
 ****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_MAX   2	/* スレッドブロック数 */
#define BLOCK_SIZE  4	/* スレッド数 */

__global__ void function(void);

int main(int argc, char *argv[])
{
	function<<<BLOCK_MAX, BLOCK_SIZE>>>();
	cudaDeviceReset();
	return(0);
}

__global__ void function(void)
{
	printf(">> block%d thread%d \n", blockIdx.x, threadIdx.x);
}
