# 問題

（ファイルが与えられる）

# 解説

実行するとバイナリができます。

データの最初らへんは全部NULLですが、後半は若干情報があり、おそらく実行ファイルであることがわかります。

であるので、元のファイルをGhdraでデコンパイルしてみます、するとバイトデータが配列として記されているので

それを新たなプログラムで再度出力します。それをさらにデコンパイルし中の配列を直接出力すると

FLAG: ```pakenCTF{7h1s_9r08r4m_w1l1_63_d313t3d_s00n!}``` が得られます。

writer:kenkenken2004