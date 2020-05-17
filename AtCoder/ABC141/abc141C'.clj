(defn readline [s]
  (let [ss (clojure.string/split s #" ")]
    (map #(Long/parseLong %) ss)))

(defn readlines [n acc]
  (if (= n 0)
    acc
    (recur (dec n)
           (conj acc (Long/parseLong (read-line))))))

(defn aggregate
  ([as n] (aggregate as n 1 0 []))
  ([as n i v acc]
   (if (empty? as)
     (if (= n i)
       (conj acc v)
       (recur as n (inc i) 0 (conj acc v)))
     (if (= (first as) i)
       (recur (next as) n i (inc v) acc)
       (recur as n (inc i) 0 (conj acc v))))))

(let [[n k q] (readline (read-line))
      as (sort (readlines q []))
      v (- k q)
      xs (map #(+ % v) (aggregate as n))]
  (doseq [x xs] (println (if (> x 0) "Yes" "No"))))
