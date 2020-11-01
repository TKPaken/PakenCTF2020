# 問題

以下のコマンドからサーバープログラムに接続して、FLAGを入手して下さい。

```nc 3.131.69.179 19283```

ソースコード : [libc.c](./libc.c)

プログラム : [libc](./libc)

共有ライブラリ : [libc.so.6](./libc.so.6)

# 解説

うっかり（？）printfのアドレスを吐いてくれているので、libc.so.6内のアドレスを引けばlibc_baseを特定する事が出来ます。

あとは、それを利用して ```system("/bin/sh")``` を実行させるだけです。

[Solve Code](./solve.py)

writer : define