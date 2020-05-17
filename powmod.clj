(defn powmod
  "Returns the value of a ^ e mod m."
  ([a e m] (powmod a e m 1))
  ([a e m s]
   (if (= e 0)
     s
     (let [s' (if (odd? e) (mod (* a s) m) s)
           a' (mod (* a a) m)
           e' (mod (quot e 2) m)]
       (recur a' e' m s')))))

;; (powmod 3 1 521)
;; (powmod 3 2 521)
;; (powmod 3 4 521)
;; (powmod 3 8 521) ;; => 309 mod 521
;; (powmod 3 16 521) ;; => 138 mod 521
;; (powmod 3 32 521) ;; => 288 mod 521
;; (powmod 3 64 521) ;; => 105 mod 521
;; (powmod 3 128 521) ;; => 84 mod 521
;; (powmod 3 256 521) ;; => 283 mod 521
;; (powmod 3 512 521) ;; => 376 mod 521
;; (powmod 3 520 521) ;; => 1 mod 521
