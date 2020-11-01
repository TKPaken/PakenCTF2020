# 問題

1以上1000以下の10000個の数字が1列に並んでいます。

1番先頭の数字は1、1番最後(つまり、先頭から10000番目)の数字は1000で、隣り合う数字の差の絶対値は1以下です。

```? x``` を入力することで、先頭からx番目の数字を得ることができます。

この操作を高々10回行った後、500がある位置のうち1つを、その位置をxとして ```! x``` の形で入力し、出てきたフラグを答えてください。

ただし、この問題の設定で数字の列に500が含まれていることは証明可能です。

```nc 3.131.69.179 19292```

# 解説

二分探索をすると、14回程度で確実に正答する事ができます。しかし、何度もチャレンジする事ができるので10回にしました。

二分探索の過程で500に当たれば出力、のような事を何度も繰り返せばいずれ当たります。

pwntoolsなどで自動化すると楽でしょう。

FLAG : ```pakenCTF{pvvnt0o1s_1s_usefu1}```

writer : autumn_eel , 解説 : define