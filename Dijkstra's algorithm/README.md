## Dijkstra's algorithm

- 重み付き有向グラフの最短経路長を求めるアルゴリズム
  - 辺の重みは非負の整数
  - 始点から各頂点への最短経路長を更新する (辺を緩める) ことを繰り返す
    - 最小の重さの辺で、その辺の端点が未訪問の頂点である辺を選択して辺を緩める
- すべての辺の重みが同じときは幅優先探索での時間計算量はO(|E|)
  - 辺の数を|E|とする

## 参照URL

- [第11回目 --- 最短路問題](http://www.dais.is.tohoku.ac.jp/~shioura/teaching/ad09/ad09-11.pdf)
- [ダイクストラ法](https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95)
- [最短経路問題](https://ja.wikipedia.org/wiki/%E6%9C%80%E7%9F%AD%E7%B5%8C%E8%B7%AF%E5%95%8F%E9%A1%8C)
- [Shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree)
- [単一始点最短経路](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_B)
- [単一始点最短経路 II](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C)
