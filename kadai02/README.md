# 並列処理のテストプログラム

コンパイル・実行コマンドは，各ファイルの先頭部分に記述されています．

| ファイル名 | 機能 |
----|---- 
| cuda01.cu | CUDAで並列処理(makefileでコンパイル可能) |
| cuda02.cu | CUDAで並列処理(CPU-GPU間のデータ転送あり) |
| mpi.c | MPIで並列処理 |
| openmp.c | OpenMPで並列処理 |
| pthread.c | pthreadで並列処理 |
| python01.y | pythonプログラム(Poolでプロセスを生成) |
| makefile | 配布段階ではcuda01.cuのみをコンパイル可能 |


## プログラムファイルのダウンロード

下記のgitコマンドかブラウザ機能を利用してファイルを保存してください．  
```
git clone --depth=1 -b kadai02 https://github.com/adelie-penguin/program_kadai
```

## 利用上の注意

- makefileは研究室のwss11～wss15環境以外だと正しく動作しませんので注意してください．
- mpi.c の実行コマンドは実行環境に合わせてコマンド引数を編集してください．
- 配布プログラムは実行結果が一意に定まりません．何度か実行して確認しておきましょう．
- 再配布は構いませんが，実行結果には責任を持ちませんのであしからず．

## makefileの補足説明

配布したmakefileには，研究室環境でcuda01.cuをコンパイルするために下記のコマンドが記載されています．
```
$(SRC) : $(SRC).cu
	nvcc -o $@ $< $(CFLAG) $(GFLAG) 
```
`$@`や`$<`はmakefile特有の構文です．上の行にある`:`前後の内容で置き換えられます．  
配布したmakefileは10行目で`SRC = cuda01`と定義します．
このため，wss15でmakeすると下記のコマンドが実行されます．
```
  nvcc -o cuda01 cuda01.cu -lm -O3 -arch=sm_70 --ptxas-options=-v
```

ファイル内の分岐処理で，コンパイル時にロングインしているコンピュータで利用可能なGPUのバージョンを`GFLAG`に設定します．  
分岐処理でwss13が特別扱いなのは，Jetsonでも同じmakefileを使い回すことを想定したためです．

配布したmakefileをcuda01.cu以外のソースコードでも利用したい場合は，
実行コマンドや10行目の`SRC = cuda01`などを編集してください．

## おすすめ(?)な学習資料

アルファベット順で記述した関係でCUDAの項目が先頭になっています．
CUDAはpthreadを拡張したような文法なので，CUDAを勉強する前にpthreadの基礎知識を習得しておくことをおすすめします．

| 並列化ライブラリ | 学習資料 |
----|---- 
|CUDA|<ul><li>**はじめてのCUDAプログラミング** ([出版社：工学社](https://www.kohgakusha.co.jp/books/detail/978-4-7775-1477-9))</li><ul><li>研究室のラックにある書籍</li><li>とりあえず動かしてみたい…という段階におすすめ</li><li>2009年出版なので情報は古い</li></ul><li>**CUDA C プロフェッショナル プログラミング** ([出版社：?インプレス](https://book.impress.co.jp/books/1115101001))</li><ul><li>研究室のラックにある書籍(通称：白本)</li><li>2015年の出版であるものの，ほどんどの技術はまだまだ現役である</li><li>まったく知識のない段階では読むのに苦労するが，チューニング段階では重宝する</li></ul></ul> |
|MPI|<ul><li>**MPI: メッセージ通信インターフェース標準 (日本語訳ドラフト)** ([PDF](https://www.mpi-forum.org/docs/translations-japanese/mpi-report-j.pdf))</li><ul><li>印刷してファイリングしたものが研究室にあるはず．</li><li>とても古い資料だが，公式発表なので信頼性が高い．</li></ul><li>**MPIによる並列プログラミングの基礎** ([PDF](https://aero.me.tut.ac.jp/Lectures/CFD/chapter02.pdf))</li><ul><li>同志社大学の渡邉先生の講義資料</li><li>PDFの10ページ目(原稿上の表記では42ページ)までは環境構築なので読み飛ばしてよい．</li></ul></ul> |
|OpenACC|<ul><li>**並列プログラミング入門**  (出版社：東京大学出版会)</li><ul><li>研究室のラックにある書籍(キャラメルゴーストハウス)</li><li>書籍前半はOpenMP, 中盤はOpenACC，後半はMPI/OpenMPと内容が豪華</li></ul></ul> |
|OpenMP|<ul><li>**C/C++プログラマーのためのOpenMP 並列プログラミング　\[第2版\]** ([出版社：カットシステム](https://www.cutt.co.jp/book/978-4-87783-199-8.html))</li><ul><li>研究室の書庫とラックにある書籍</li></ul><ul>|
|pthread|<ul><li>**Linuxとpthreadsによる マルチスレッドプログラミング入門** ([出版社：秀和システム](https://www.shuwasystem.co.jp/book/9784798053721.html))</li><ul><li>研究室の書庫にある書籍</li><li>1-3にある表がとっても便利</li></ul></ul>|
    
