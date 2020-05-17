(defn solve [s b]
  (if (empty? s)
    "Yes"
    (let [c (first s)]
      (if (= b c)
        "No"
        (recur (next s) (if (= b \L) \R \L))))))

(println (solve (read-line) \L))
