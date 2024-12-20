# program_kadai/kadai01


## 課題内容

`calc.c`の25行目近辺にあるcalc_matrix関数を編集し、連立一次方程式 $Ax=b$を求解するプログラムを完成させましょう。

### 作業手順

1. プログラムファイルを保存する
1. ファイル編集前に下記を確認
   1. コンパイルでエラーが出ないことを確認する
   1. 実行コマンドを入力し、ファイル編集前の表示内容を確認する
1. 関数calc_matrix()内で配列bに解 $x$の値を格納するコードを記述する
1. 正しく動作しているかを確認する

### プログラムファイルのダウンロード

下記のgitコマンドを使うか、ブラウザ機能を利用してcalc.cを保存してください。
```
git clone --depth=1 -b kadai01 https://github.com/adelie-penguin/program_kadai
```

### コンパイルコマンド

コンパイルオプションは特に必要ありません。  
必要に応じて最適化オプション「-O3」を追加してください。
```
gcc calc.c
```

### 実行コマンド

コマンド引数で行列サイズを指定します。  
行列サイズ5で実行したいときは下記のように入力します。  
コマンド引数が省略された場合は、元数20でプログラムを実行します。  
```
./a.out 5
```

### 作成する関数calc_matrix()の注意点

- 関数calc_matrix()が呼ばれた時点で、引き数A, b, sizeには問題データが設定済みです。
- 関数calc_matrix()内で配列bに解 $x$の値を格納するのが目標です。
- 引数のAの値はどのように書き換えても構いません。
- 必要に応じて関数内でメモリ確保しても問題ありません。

| | 仕様 |
|---|---|
| 戻り値      | なし|
| double **A | 係数行列 $A$ (2次元配列: $a_{0,1}$の値をa[0][1]に格納)　|
| double *b  | 定数ベクトル $b$ (ここに $x$の値を上書きする)　|
| int size   | 行列サイズ(元数) |

### calc_dbg.c

前進代入( $Ly=b$から $y$を求める計算)と後退代入( $Ux=y$から $x$を求める計算)の正確さを確認するためのデバッグ用ファイルです。  
`calc_dbg.c`は乱数を用いて上三角行列と下三角行列を生成します。
