## Kruskal's algorithm

- 重み付き無向グラフの最小全域木を求めるアルゴリズム
- 辺を重みの昇順でソートして、軽いほうから木に移す
  - 辺の端点u, vが同じ木の頂点のときは、その辺を捨てる

## 補足

- 隣接行列の空間計算量
  - 頂点がn個のときはO(n^2)

- 隣接リストの空間計算量
  - 辺がm個で頂点がn個のときはO(m+n)

## 参照URL

- [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)
- [第9回目 --- グラフのデータ構造，最小木問題（その１）](http://www.dais.is.tohoku.ac.jp/~shioura/teaching/ad09/ad09-09.pdf)
