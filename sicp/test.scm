; (define (abs x)
;   (cond ((> x 0) x)
;         ((= x 0) 0)
;         ((< x 0)(- x))))
(define (abs x)
  (if (< x 0)
    (- x)
    x))


(print (abs 3))
(print (abs 0))
(print (abs -3))
