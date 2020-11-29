## Bellman-Ford algorithm

- 重み付き有向グラフの最短経路長を求めるアルゴリズム
  - 辺の重みは整数
  - 辺の重みの総和が負である閉路を検出して報告する
  - 始点から各頂点への最短経路長を更新する (辺を緩める) ことを繰り返す
    - 頂点の数を|V|とする
    - 繰り返す回数は|V| - 1
    - すべての辺で辺を緩める
- 選択して緩める

## 参照URL

- [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
- [ベルマン–フォード法](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%9E%E3%83%B3%E2%80%93%E3%83%95%E3%82%A9%E3%83%BC%E3%83%89%E6%B3%95)
- [単一始点最短経路（負の重みをもつ辺を含む）](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B)
