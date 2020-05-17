(defn solve [s t]
  (if (nil? s)
    0
    (+ (solve (next s) (next t))
       (if (= (first s) (first t)) 1 0))))

(println (solve (str (read)) (str (read))))
