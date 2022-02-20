(use '[clojure.string :only (split)])

(defn readline [s]
  (let [ss (split s #" ")]
    (map #(Long/parseLong %) ss)))

(defn readlines [n acc]
  (if (= n 0)
    acc
    (recur (dec n)
           (conj acc (dec (Long/parseLong (read-line)))))))

(defn solve [as xs]
  (if (empty? as)
    xs
    (recur (next as) (update-in xs [(first as)] inc))))

(let [[n k q] (readline (read-line))
      as (readlines q [])
      xs (vec (take n (repeat (- k q))))]
  (doseq [x (solve as xs)] (println (if (> x 0) "Yes" "No"))))
