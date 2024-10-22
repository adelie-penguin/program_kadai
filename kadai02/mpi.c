/**********************************************************
 *
 * MPIの実験プログラム
 *
 *---------------------------------------------------------
 *
 * コンパイル
 * $mpicc -O3 -o mpi_test mpi.c
 *
 * ローカルで実行
 * $mpiexec -n 4 -H wsp18:4 mpi_test
 *
 ***********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"mpi.h"


int main(int argc, char *argv[])
{
	/* MPI専用 --------------------------------*/
	int pe;     /* PE数 */
	int r;     /* ランク番号 */
	char name[128]; /* host名 */

	MPI_Init(&argc, &argv);             /* MPI実行環境の初期化 */
	MPI_Comm_size(MPI_COMM_WORLD, &pe); /* プロセス数取得 */
	MPI_Comm_rank(MPI_COMM_WORLD, &r);  /* ランク番号取得 */

	gethostname(name, sizeof(name));
	fprintf(stdout, "host name:%s  rank:%d (in %dPE)\n", name, r, pe);

	//MPI_Barrier(MPI_COMM_WORLD); /* みんなで同期取りましょう！ */

	MPI_Finalize(); /* MPI終了 */
	return 0;
}
