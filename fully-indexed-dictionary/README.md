## 簡潔データ構造

- 索引を利用して高速な操作を実現するデータ構造

## 完備辞書

- ビット列B[0, n)に対する簡潔データ構造 (Fully indexable dictionary)
- B[i]がとりうる値は0か1
- 次の操作を備えたデータ構造
  - access(B, i): B[i]を返す
  - rank0(B, i): B[0, i)中の0の数を返す
  - rank1(B, i): B[0, i)中の1の数を返す
  - select0(B, i): B[0, i)中のi+1番目に出現した0の位置を返す
  - select1(B, i): B[0, i)中のi+1番目に出現した1の位置を返す
  - rank0(B, i) + rank1(B, i) = iが成り立つ
  - select1(B, i) = pならばrank1(B, p)=i, rank1(B, p+1) = i+1が成り立つ

## 参照図書

- [高速文字列解析の世界](https://sites.google.com/site/daisukeokanohara/iwanami_string_world)

## 参照URL

- [単進符号](https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%AB%E3%83%95%E3%82%A1%E7%AC%A6%E5%8F%B7)
