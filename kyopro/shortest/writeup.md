# 問題

N頂点M辺の全ての重みが1の無向グラフがあります。

define君は頂点0からの全頂点への最短経路を求めるプログラムを書きましたが、どうやらバグっているようです。

撃墜テストケースを作成して下さい。

フォーマット
```
N M
A_1 B_1
...
A_M B_M
```
ただし、N, M共に5以下である必要があります。

入力例
```
3 2
0 1
1 2
```

撃墜テストケースを```nc 3.131.69.179 18293```でサーバープログラムに接続、提出するとFLAGを得られます。

プログラム : [WA.cpp](./WA.cpp)

# 解説

本来Queueを使う所Stackにしてしまっているのが問題で、これだとDFSのようになってしまいます。

例えば、

```
5 5
0 1
1 2
2 3
3 4
4 0
```

を与えると本来は```0 1 2 2 1``` の所```0 1 3 2 1``` となります。

よって、撃墜できました！

FLAG : ```pakenCTF{d0_u_l1ke_c0de40rces}```

writer : autumn_eel , 解説 : define