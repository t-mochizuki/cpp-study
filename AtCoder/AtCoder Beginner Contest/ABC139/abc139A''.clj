(defn solve [s t acc]
  (if (nil? s)
    acc
    (recur (next s)
           (next t)
           (if (= (first s) (first t))
             (inc acc)
             acc))))

(println (solve (read-line) (read-line) 0))
