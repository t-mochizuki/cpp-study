(defn solve [a b cnt]
  (if (>= a b)
    (inc cnt)
    (solve
      (if (= cnt 0) (dec a) a)
      (- b a)
      (inc cnt))))

(let [a (int (read))
      b (int (read))]
  (println (if (= b 1) 0 (solve a b 0))))
