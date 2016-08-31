;2,2,1 列の表現

; (cons 1
;       (cons 2
;             (cons 3
;                   (cons 4 nil))))

; (list 1 2 3 4)

(define one-through-four (list 1 2 3 4))
(print one-through-four)
(print (car one-through-four))
(print (cdr one-through-four))
(print (cons 10  one-through-four))
(print (cons 5  one-through-four))

; cdr ダウン
(define (list-ref items n)
  (if (= n 0)
    (car items)
    (list-ref (cdr items) (- n 1))))
(define squares (list 1 4 9 16 25))
(print (list-ref squares 3))

(define (length items)
  (if (null? items)
    0
    (+ 1 (length (cdr items)))))
(define odds (list 1 3 5 7))
(print (length odds))

(define (append list1 list2)
  (if (null? list1)
    list2
    (cons (car list1) (append (cdr list1) list2))))

(print (append squares odds))

;map
(define (scale-list items factor)
  (if (null? items)
    ()
    (cons (* (car items) factor)
          (scale-list (cdr items)
                      factor))))
(print (scale-list (list 1 2 3 4 5) 10))

(define (map proc items)
  (if (null? items)
    ()
    (cons (proc (car items))
          (map proc (cdr items)))))

(print (map abs (list -10 2.5 -11.6 17)))

(define (scale-list items factor)
  (map (lambda (x) (* x factor)) items))

(print (scale-list (list 1 2 3 4 5) 10))

(define x (cons (list 1 2) (list 3 4)))
(print (length x))

(define (count-leaves x)
  (cond ((null? x) 0)
        ((not (pair? x)) 1)
        (else (+ (count-leaves (car x))
                 (count-leaves (cdr x))))))

(print (count-leaves x))

(define (scale-tree tree factor)
  (cond ((null? tree) ())
        ((not (pair? tree)) (* tree factor))
        (else (cons (scale-tree (car tree) factor)
                    (scale-tree (cdr tree) factor)))))
(print (scale-tree (list 1 (list 2 (list 3 4) 5) (list 6 7)) 10))

(define (scale-tree tree factor)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
           (scale-tree sub-tree factor)
           (* sub-tree factor)))
       tree))

(print (scale-tree (list 1 (list 2 (list 3 4) 5) (list 6 7)) 10))

(define (filter predicate sequence)
  (cond ((null? sequence) ())
        ((predicate (car sequence))
         (cons (car sequence)
               (filter predicate (cdr sequence))))
        (else (filter predicate (cdr sequence)))))

(print (filter odd? (list 1 2 3 4 5)))

(define (accumulate op initial sequence)
  (if (null? sequence)
    initial
    (op (car sequence) (accumulate op initial (cdr sequence)))))

(print (accumulate + 0 (list 1 2 3 4 5)))
(print (accumulate * 1 (list 1 2 3 4 5)))
(print (accumulate cons () (list 1 2 3 4 5)))

(define (enumerate-interval low high)
  (if (> low high)
    ()
    (cons low (enumerate-interval (+ low 1) high ))))

(print (enumerate-interval 2 7))

(define (enumerate-tree tree)
  (cond ((null? tree) ())
        ((not (pair? tree)) (list tree))
        (else (append (enumerate-tree (car tree))
                      (enumerate-tree (cdr tree))))))

(print (enumerate-tree (list 1 (list 2 (list 3 4)) 5)))

(define (sum-odd-squares tree)
  (accumulate + 0 (map square (filter odd? (enumerate-tree tree)))))

(define (even-fibs n)
  (accumulate cons () (filter even? (map fib (enumerate-interval 0 n)))))


