# 問題

以下のコマンドからサーバープログラムに接続し、FLAGを入手して下さい。

```nc 3.131.69.179 15991```

プログラム : [maze](./maze)

※ソースコードは配布なし

# 解説

ソースコード : [maze.c](./maze.c)

名前の入力にBOFがあり、mazeの中身を書き換える事で脱出する事ができます。

とは言っても、nameとmazeの間には 'A' 〜 'Z' の26通りのCanaryが挟まっているので、Brute Forceするか時間を合わせるかする必要があります。

FLAG : ```pakenCTF{6ru4e_40rce}```

writer : define