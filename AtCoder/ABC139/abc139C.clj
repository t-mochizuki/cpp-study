(use '[clojure.string :only (split)])

(defn readline [s]
  (let [ss (split s #" ")]
    (map #(Long/parseLong %) ss)))

(defn solve [h hs acc ans]
  (if (empty? hs)
    ans
    (let [h' (first hs)
          hs' (rest hs)
          acc' (inc acc)]
      (if (>= h h')
        (recur h' hs' acc' (if (> acc' ans) acc' ans))
        (recur h' hs' 0 ans)))))

;; (solve 10 [4 8 7 3] 0 0)
;; (solve 4 [4 5 6 6 5 5] 0 0)
;; (solve 1 [2 3 4] 0 0)
;; (solve 4 [5 4 6 6 5 5] 0 0)

(let [n (Integer/parseInt (read-line))
      hs (readline (read-line))]
  (println (solve (first hs) (rest hs) 0 0)))
