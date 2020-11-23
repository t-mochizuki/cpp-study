## 簡潔データ構造

- 索引を利用して高速な操作を実現するデータ構造

## 完備辞書

- ビット列B[0, n)に対する簡潔データ構造 (Fully indexable dictionary)
- B[i]がとりうる値は0か1
- 次の操作を備えたデータ構造
  - access(B, i): B[i]を返す
  - rank0(B, i): B[0, i)中の0の数を返す
  - rank1(B, i): B[0, i)中の1の数を返す
  - select0(B, i): ビット列の先頭からi+1番目に出現した0の位置を返す
  - select1(B, i): ビット列の先頭からi+1番目に出現した1の位置を返す
  - それぞれの操作の時間計算量はO(1)
- rank0(B, i) + rank1(B, i) = iが成り立つ
- select1(B, i) = pならばrank1(B, p)=i, rank1(B, p+1) = i+1が成り立つ
- 累積和で実装すると空間計算量が多くなる
- 次の3つの補助データで実装する
  - 大ブロック: 幅は(log n)^2。大ブロックごとに、ビット列の先頭からのrank1を格納する
  - 小ブロック: 幅は(log n) / 2。小ブロックごとに、関連する大ブロックの先頭からのrank1を格納する
  - ビットパターン: (log n) / 2ビットで表すことができる整数を2進数で表したときの1の数を格納する
- 大ブロックの数はn / (log n)^2
- 大ブロックはビット列の先頭からのrank1を格納するので、大ブロックに必要なビットはlog nビット
- 小ブロックの数はn / ((log n) / 2)
- 小ブロックは関連する大ブロックの先頭からのrank1を格納するので、小ブロックに必要なビットはlog ((log n)^2)ビット
  - log ((log n)^2) = 2 * log (log n)

## 参照図書

- [高速文字列解析の世界](https://sites.google.com/site/daisukeokanohara/iwanami_string_world)

## 参照URL

- [単進符号](https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%AB%E3%83%95%E3%82%A1%E7%AC%A6%E5%8F%B7)
- [簡潔辞書](https://ja.wikipedia.org/wiki/%E7%B0%A1%E6%BD%94%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0#%E7%B0%A1%E6%BD%94%E8%BE%9E%E6%9B%B8)
- [完備辞書（簡潔ビットベクトル）の解説 - アスペ日記](https://takeda25.hatenablog.jp/entry/20140201/1391250137)
