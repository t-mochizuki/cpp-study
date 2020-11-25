## Disjoint set

- お互いに疎な集合を格納するデータ構造
- 次の操作を備えたデータ構造
  - Find: 所属する集合の代表を返す
  - Union: 2つの集合を1つに統合する
- 大きな集合に小さな集合を統合する
- 経路圧縮: Findを行ったときに、ついでに木の深さを低くする
  - Findを行ったときに辿ったノードの親ノードが代表になる

## 参照URL

- [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [素集合データ構造](https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0)
- [Union-Find 木](https://yutaka-watanobe.github.io/star-aida/books/pseudo_code/disjoint_set_simulation/code.html)
