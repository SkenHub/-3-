# -3-
今後上げていきますので指摘お願いします。

12/1クラスOMR_OR更新 構造体の宣言をヘッダーファイル側で宣言し，クラス内で使えるようにしようとしたところ，エラーが発生．
誤文は，
invalid use of member 'O3::Data' in static member function

12/2クラスOMR_OR更新，ついでに実験で使っていたmain文も追加
昨日の結論としてクラス内での割り込み関数は無理があると，なので割り込み関数で実行する文だけメンバ関数にし，mainで割り込みを作りその中にメンバ関数を展開することで，通そうとした．
あとsken_system.initとか，while()とかは削除．mainでやってるでな．
今回の問題，先に記述したことはプログラムにし終え，実験してみたところ，エンコーダーの値が読み取れなかった，ただのエンコーダーを読むプログラムでは読めたため，ハードの問題はなさそう．

12/3　川﨑：12/2へのリマインド
エンコーダー値が読めない理由は、interrupt_prot関数の引数を通常変数にしているため. これではData_prot[]の値は変化しない（引数は関数内のローカル変数でアドレスが異なる）.

解決策

* 関数の戻り値を設定する. 欲しい数値が複数あるのでstruct作ってやるのをお勧め 
* 引数をポインタ変数にしてアドレスを渡すようにする
* てか、ここで値取り出せるようにする必要なくね？（デバック用にするなら別関数でもいいと思う）

今回の問題，先に記述したことはプログラムにし終わり，実験してみたところ，バイナリーの値が反応できなかった，ただのクリックーを読むプログラムでは読めなかったため，ハードの問題はなさそう．
12/5クラスOMR_OR,main更新 
前回の修正,引数に変数を入れ，そこに値を入れて返すつもりだったけど，返してなかった．　提案された解決法　ポインタ　リターン文
今回はポインタを使った．仮引数にポインタ変数の構造体を宣言し，そこにmainの構造体のアドレスを入れる．それだけ
備忘　&演算子　これがついた変数のアドレスを出してくれる　変数型* 名前　ポインタ変数の宣言,*の前後は関係なし. *変数名　ポインタ変数を通常変数として扱う．付かなければポインタ変数．
読めた．
