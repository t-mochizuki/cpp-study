(ns atcoder.core
  (:require [clojure.string :refer [split]]
            [clojure.edn :as edn]))

(defn- solve [r] nil)

(defn main
  ([]
   (solve (java.io.BufferedReader. *in*)))
  ([in-file]
   (with-open [r in-file]
     (let [n (edn/read-string (.readLine r))]
       (loop [i 0]
         (when (pos? (compare n i))
           (do
             (solve r)
             (recur (inc i)))))))))

;; (main)
