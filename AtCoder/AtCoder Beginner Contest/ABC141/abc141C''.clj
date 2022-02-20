(defn readline [s]
  (map #(Long/parseLong %)
       (clojure.string/split s #"\s")))

(defn readlines []
  (map #(Long/parseLong %)
       (line-seq (clojure.java.io/reader *in*))))

(defn solve [as n i v acc]
  (if (empty? as)
    (if (= n i)
      (conj acc v)
      (recur as n (inc i) 0 (conj acc v)))
    (if (= (first as) i)
      (recur (next as) n i (inc v) acc)
      (recur as n (inc i) 0 (conj acc v)))))

(let [[n k q] (readline (read-line))
      as (sort (readlines))
      v (- k q)
      xs (map #(+ % v) (solve as n 1 0 []))
      fout (java.io.PrintWriter. (clojure.java.io/writer *out*))]
  (do
    (doseq [x xs] (.println fout (if (> x 0) "Yes" "No")))
    (.flush fout)))
