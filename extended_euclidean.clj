(defn extended-euclidean
  "Returns x and y; the greatest common denominator of A and B are x * A + y * B."
  ([a b] (extended-euclidean a b 1 0 0 1))
  ([a b x y u v]
   (if (= b 0)
     [x y]
     (let [q (quot a b)
           r (mod a b)
           u' (- x (* q u))
           v' (- y (* q v))]
       (extended-euclidean b r u v u' v')))))

;; (extended-euclidean 240 66) ;; => [-3 11]
;; (+ (* 240 -3) (* 66 11)) ;; => 6
;; (extended-euclidean 520 221) ;; => [3 -7]
;; (+ (* 520 3) (* 221 -7)) ;; => 13

(defn inverse
  "Returns the inverse of a value A in modulo N."
  [a n]
  (let [[x y] (extended-euclidean a n)
        gcd (+ (* a x) (* n y))]
    (if (= gcd 1)
      (mod x n))))

;; (inverse 5 7) ;; => 3
;; (inverse 3 3016) ;; => 2011

(defn chinese-remainder-theorem
  "Returns x and m; x = a_i mod m_i, m = m_1 * m_2 * ... * m_k (i = 1,2,...,k)."
  [a as m ms]
  (if (empty? as)
    [a m]
    (let [a' (+ a (* m
                     (inverse m (first ms))
                     (- (first as) a)))
          m' (* m (first ms))]
      (chinese-remainder-theorem (mod (if (> a' 0) a' (+ a' m')) m')
                                 (next as)
                                 m'
                                 (next ms)))))

;; (chinese-remainder-theorem 0 [1 2 3] 1 [2 3 5]) ;; => [23 30]
;; (chinese-remainder-theorem 0 [3 5] 1 [7 11]) ;; => [38 77]
