(defn euclidean [a b]
  "Returns the greatest common denominator of a and b."
  (if (= b 0)
    a
    (euclidean b (mod a b))))

;; (euclidean 520 221) ;; => 13
