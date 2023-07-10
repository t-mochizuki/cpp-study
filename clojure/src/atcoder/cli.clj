(ns atcoder.cli
  (:require [atcoder.core :as core]
            [clojure.string :refer [join]]
            [clojure.tools.cli :refer [parse-opts]])
  (:gen-class))

(defn exit
  [status msg]
  (println msg)
  (System/exit status))

(def cli-options
  [["-h" "--help"]])

(defn -main
  [& args]
  (let [{:keys [options arguments errors summary]} (parse-opts args cli-options)]
    (cond
      (:help options) (exit 0 summary)
      errors (exit 1 (join "\n" errors))
      (empty? arguments) (core/main)
      :else (core/main (clojure.java.io/reader (first arguments))))))
