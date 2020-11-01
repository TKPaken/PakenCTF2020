# 問題

Code:"uMg_nx4=vAMbv>p’.\_gktgFZ>gg>’\[\_>D’>Lg_v>_jW)F]"

same key　(hint 33)

almost full prime range

# 解説

Composite Expo 、すなわち累乗を用いた複合的な暗号です。

複合的とはここでは換字式暗号と転置式暗号を合わせたという意味です。

換字と転置の両方で累乗が用いられています。

CoprimeやCrandなどと同じ要領でやります。

換字では33を基数、char-38を指数、余りを89とした累乗を求めます。

-38しているのは、累乗で被りが出ないようにするためです。（たぶん）

転置では33を基数、位置―1を指数、余りを文字列の長さとした累乗へと移します。

これの逆を行えばいいわけです。

なお、換字では全探索をします。

よって、FLAG: ```pakenCTF{H4u3_y0v_ever_h34rd_P13rr3_63_F3rm47}``` を得られました。

writer:kenkenken2004

