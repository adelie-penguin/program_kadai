# 並列処理のテストプログラム


コンパイル・実行コマンドは，各ファイルの先頭部分に記述されています．

| ファイル名 |  |
----|---- 
| cuda.cu | CUDAで並列処理(CPU-GPU間のデータ転送あり) |
| cuda2.cu | CUDAで並列処理(GPU側から表示) |
| pthread.c | pthreadで並列処理 |
| mpi.c | MPIで並列処理 |
| openmp.c |  |
| makefile | cuda2.cuのみをコンパイル可能 |
