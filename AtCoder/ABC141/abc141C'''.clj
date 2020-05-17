(defn readline [s]
  (map #(Long/parseLong %)
       (clojure.string/split s #"\s")))

(defn readlines []
  (map #(Long/parseLong %)
       (line-seq (clojure.java.io/reader *in*))))

(def ^java.io.PrintWriter fout
  (java.io.PrintWriter. (clojure.java.io/writer *out*)))

(defn p [^java.lang.Long x]
  (.println fout (if (> x 0) "Yes" "No")))

(defn solve [as n k i v]
  (if (empty? as)
    (if (= n i)
      (p (+ k v))
      (do
        (p (+ k v))
        (recur as n k (inc i) 0)))
    (if (= (first as) i)
      (recur (next as) n k i (inc v))
      (do
        (p (+ k v))
        (recur as n k (inc i) 0)))))

(let [[n k q] (readline (read-line))
      as (sort (readlines))
      k' (- k q)]
  (solve as n k' 1 0))

(.flush fout)
