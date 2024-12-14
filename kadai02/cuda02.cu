/* vim: set tabstop=4 foldmethod=marker : */
/************************************************
 *
 * CUDAおためしプログラム
 *   ・CPU-GPU間のデータ転送
 *   ・シェアードメモリの利用
 *
 *-----------------------------------------------
 *
 *  コンパイルコマンド
 *   $nvcc -o cuda02 cuda02.cu
 *
 *  実行コマンド
 *   $./cuda02
 *
 ************************************************/

#include<stdio.h>
#include<cuda_runtime.h>

#define ThreadMax (10)
#define MallSize  ((ThreadMax) * sizeof(int))

/*==============================================*/
/* GPUで実行する関数                            */
/*----------------------------------------------*/
/* ※シェアードメモリをわざと経由                */
/*==============================================*/
__global__ void test_asemble(int *g_data, int num)
{
	int idx = threadIdx.x;      /* レジスタ変数(スレッドIDの取得)           */
	__shared__ int  s_data;     /* シェアード変数                           */

	s_data      = g_data[idx];  /* グローバルメモリからシェアードにコピー   */
	s_data     += idx * num;
	g_data[idx] = s_data;       /* グローバルメモリへの書き戻し             */

	return;
}

/************************************************/
/* main関数(CPUで実行)                          */
/************************************************/
int main(int argc, char *argv[])
{
	int i;
	int *c_array   = NULL;  /* CPU側の配列 */
	int *g_array   = NULL;  /* GPU側の配列 */
	int thread_max = 10;
	int grid_max   = 1;


	/*--[スレッド数とブロック数を決める]-------*/

	dim3 grid(grid_max);            /* スレッドブロックの個数を指定         */
	dim3 block(thread_max);         /* スレブロのサイズ(スレッド数)を指定   */


	/*--[CPU側のメモリ確保]--------------------*/

	c_array = (int*)malloc(thread_max * sizeof(int));   /* CPU上にメモリ確保 */

	for(int i = 0; i < thread_max; i++)           
	{
		c_array[i] = 0;     /* 配列初期化 */
	}

	/*--[CUDA側のメモリ確保]-------------------*/

	/* GPU上にメモリ確保        */
	cudaMalloc((int**)&g_array, MallSize);

	/* CPUの配列をGPUにコピー   */
	cudaMemcpy(g_array, c_array, MallSize, cudaMemcpyHostToDevice);


	/*--[GPUのカーネル起動]--------------------*/

	test_asemble<<<grid, block>>>(g_array, 10);


	/*--[仕事結果の回収]-----------------------*/

	/* GPUの配列をCPUにコピー   */
	cudaMemcpy(c_array, g_array, MallSize, cudaMemcpyDeviceToHost);

	/* 表示 */
	for(i = 0; i < thread_max; i++)
	{
		fprintf(stdout, "c_array[%d]=%d\n", i, c_array[i]);
	}

	cudaFree(g_array);
	free(c_array);
	cudaDeviceReset(); /* デバイスリセット */
	return(0);
}
