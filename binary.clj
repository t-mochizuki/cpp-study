(defn binary [n acc]
  (if (= n 0)
    acc
    (let [m (- n (* 2 (quot n 2)))]
      (binary (quot n 2) (conj acc m)))))
