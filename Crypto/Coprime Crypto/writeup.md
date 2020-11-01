# 問題

---Decrypt this cryptograph---

"c1ys{4_C0_ky_}_hhaFrnn75ar5!y7p3T8aep1p"


---Examples of plain texts and codes' pair---

"Tsukukoma-Paken"

"ea-mkksnkPaouuT"


"kenkenken2004"

"4002nekneknek"


"We_love_CTF"
"oCevT_eFl_W"

"Prime_Number_Is_Still_Veiled"

"lerlri__mVIees_i_NlSuetmdibP"


"Are_You_Enjoying_This_CTF?"

"?FTC_sihT_gniyojnE_uoY_erA"


"abcdefghijk"

"eibfjcgkdha"


# 解説

平文と暗号文の組み合わせが複数与えられ、それらから復号する問題です。

平文と暗号文は同じ種類・数の文字から成り立っており、 **転置式暗号** であることが推測できます。

また、問題名から **「互いに素な数」** の性質を利用しているであろうことがわかります。

まず、古典転置式暗号では基本的に文字の位置によって暗号化され、文字がなんであるかは暗号化に関係しません。

つまり、文字数さえ同じであれば普通は同じ転置がなされます。

これは、転置後の位置は転置前の位置の全単射の写像ということです。

そのような写像で、「互いに素」と深く関係するものの一つには、「余り」があります。

「自然数A,Bが互いに素ならばAB以下のAの正の倍数kAのBで割った余りは全て異なる」というものです。

これは背理法で証明されます。

また、kは1以上B以下で、Bで割った余りは0以上B未満です。

つまり、k+1とmodBは全単射の写像であるということです。

だから、n文字のi文字目を自然数pでi\*p%n文字目に転置することで復号できます。

自然数pを総当たりで探すとp=103であることがわかります。

よって、FLAG: ```pakenCTF{7h15_15_an_3asy_cryp708r4phy!}``` を得ることができました。

writer:kenkenken2004
