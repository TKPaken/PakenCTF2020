# 問題

以下のコマンドからサーバープログラムに接続して、FLAGを入手して下さい。

```nc 3.131.69.179 15692```

ソースコード : [password.c](./password.c)

プログラム : [password](./password)

# 解説

名前の出力にFormat String Bugがあります。バイナリを解析すると、パスワードがスタックで10,11番目に入っている事が分かるので、```%10$p,%11$p``` と入力すると16進数表記のパスワードが表示されます。なお、リトルエンディアンなので同じスタック内では逆になっている事に気をつけて下さい。

後はASCIIに直して入力するだけです。パスワードを書き換えるのもいいと思います。

FLAG : ```pakenCTF{F0rm6t_Str1ng_4ttack}```

writer : define