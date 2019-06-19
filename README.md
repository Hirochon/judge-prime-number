# judge-prime-number
エラトステネスの篩を用いた素数判定

エラトステネスの篩（ふるい）とは
  エラトステネスの篩は素数判定法の一種で，指定された整数以下の全ての素数(prime number)を発見するための単純なアルゴリズムである． 古代ギリシアの科学者，エラトステネス(Eratosthenes) が考案したとされるため，この名がある．そのアルゴリズムは以下の通りである．
    　
		 ➀2〜N までの素数候補表を昇順に用意する。（素数候補表：2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20）
		 ➁素数候補表の先頭にある数を素数リストに記入する。（素数表：2）
		 ➂新たに素数表に記入された素数のすべての倍数を素数候補表から削除する。（素数候補表：2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20）
		 ➃➁に戻る。

プログラムの説明！
  このプログラムは入力されたn番目の素数を表示する。(このプログラムでは1200万までの素数を判定可能)
  例えば「123」と打てば、「123番目の素数は677です」と返される。
  
プログラムの使い方！
  ➀Cファイルをダウンロードして、コンパイルのちに実行。
  ➁コマンドライン入力を実装しているので、『search_x.exe　探したい素数の番目を入力』と打てば実行できる。

工夫した点
  ・条件式に無駄がないかどうか、条件式それぞれの役割を確認した。（２以外の偶数を先に素数リストから省くことによって、for文で処理する回数
を減らした。）
  ・calloc(０を代入)とmallocのメモリ確保のそれぞれの特徴を用いて、for文の使用数を削減。
