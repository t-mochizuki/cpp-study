(defn solve [s b acc]
  (if (empty? s)
    acc
    (let [c (first s)]
      (if (= b c)
        (recur (next s) b acc)
        (recur (next s) c (inc acc))))))

(let [n (read-line)
      s (read-line)]
  (println (solve (next s) (first s) 1)))
