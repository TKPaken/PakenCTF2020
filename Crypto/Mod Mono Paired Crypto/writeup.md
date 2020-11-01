# 問題

Code : "@o&U2%h/XR-a0+(0C'590590-055BB5(0r5QQ5*LlCP"

almost full prime range

# 解説

「Mod Mono Paired Crypto」の名前から推測するに、「１と余りが関連する写像」であることがわかります。

これはつまり、モジュラの逆元です。

また、Crandから類推するに、「almost full prime range」は94に近くて素数である数を意味しています。

法は94より小さい必要があるので、これに適しているのは89です。

暗号化の際には各charの89を法とした逆元+33を出力しているので

復号の際にはその逆、すなわち33を引き89を法とした逆元を求めればいいです。

よって、FLAG: ```pakenCTF{m4y_b3_7h1s_1s_4_11tt13_d1ff1cvl7}``` が得られました。

writer:kenkenken2004
