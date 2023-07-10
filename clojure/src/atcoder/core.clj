(ns atcoder.core
  (:require [clojure.string :refer [join split]]
            [clojure.tools.cli :refer [parse-opts]]
            [clojure.edn :as edn])
  (:gen-class))

(defn exit
  [status msg]
  (println msg)
  (System/exit status))

(defn solve [r]
  (let [line (.readLine r)]
    (println line)))

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

(def cli-options
  [["-h" "--help"]])

(defn -main
  [& args]
  (let [{:keys [options arguments errors summary]} (parse-opts args cli-options)]
    (cond
      (:help options) (exit 0 summary)
      errors (exit 1 (join "\n" errors))
      (empty? arguments) (main)
      :else (main (clojure.java.io/reader (first arguments))))))
