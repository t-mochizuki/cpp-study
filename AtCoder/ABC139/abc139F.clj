;; I read the submission #7244437.

(use '[clojure.string :only (split)])

(defn readlines [n acc]
  (if (= n 0)
    acc
    (recur (dec n)
           (conj acc (read-line)))))

(defn readline [s]
  (let [ss (split s #" ")]
    (let [[x y] (map #(Long/parseLong %) ss)]
      {:x x :y y})))

(defn distance2 [x y]
  (+ (Math/pow x 2) (Math/pow y 2)))

(defn distance2-v [v]
  (distance2 (:x v) (:y v)))

(defn dot [v1 v2]
  (+ (* (:x v1) (:x v2))
     (* (:y v1) (:y v2))))

(defn cross [v1 v2]
  (- (* (:x v1) (:y v2))
     (* (:x v2) (:y v1))))

(defn sum-v [v1 v2]
  {:x (+ (:x v1) (:x v2))
   :y (+ (:y v1) (:y v2))})

(defn classify [v1 vs acc]
  (if (empty? vs)
    acc
    (recur v1
           (next vs)
           (let [v2 (first vs)
                 d (dot v1 v2)
                 c (cross v1 v2)]
             (cond
               (> d 0) (update acc :positive-dot #(sum-v v2 %))
               (< d 0) (update acc :negative-dot #(sum-v v2 %))
               (> c 0) (update acc :positive-cross #(sum-v v2 %))
               :else (update acc :negative-cross #(sum-v v2 %)))))))

(defn variety [c]
  (let [v (:positive-dot c)
        n1 (:positive-cross c)
        n2 (:negative-cross c)]
    (apply
      max
      (map distance2-v [v
                        (sum-v v n1)
                        (sum-v v n2)
                        (sum-v (sum-v v n1) n2)]))))

(defn rotate90 [v]
  {:x (- (:y v))
   :y (:x v)})

(def zero-c
  {:positive-dot {:x 0 :y 0}
   :negative-dot {:x 0 :y 0}
   :positive-cross {:x 0 :y 0}
   :negative-cross {:x 0 :y 0}})

(defn solve []
  (let [n (Integer/parseInt (read-line))
        ls (readlines n [])
        vs (map readline ls)
        vs' (flatten (map #(take 4 (iterate rotate90 %)) vs))]
    (println
      (Math/sqrt
        (apply
          max
          (map (fn [v1]
                 (let [c (classify v1 vs zero-c)]
                   (variety c)))
               vs'))))))

(solve)
