; 1.3.1 引数としての手続

(define (cube x) (* x x x))

(define (sum-integers a b)
  (if (> a b)
    0
    (+ a (sum-integers ( +a 1) b))))

(define (sum-cubes a b)
  (if (> a b)
    0
    (+ (cube a)
       (sum-cubes (+ a 1) b))))

(define (sum term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))))

(define (inc n) (+ n 1))
(define (sum-cubes a b)
  (sum cube a inc b))

(print (sum-cubes 1 10))

(define (identity x) x)
(define (sum-integers a b)
  (sum identity a inc b))

(print (sum-integers 1 10))

(define (pi-sum a b)
  (define (pi-term x )
    (/ 1.0 (* x (+ x 2))))
  (define (pi-next x)
    (+ x 4))
  (sum pi-term a pi-next b))

(print (* 8 (pi-sum 1 1000)))

; 1.3.2 lambda

(define (pi-sum a b)
  (sum (lambda (x) (/ 1.0 (* x (+ x 2))))
       a
       (lambda (x) (+ x 4))
       b))

(print (* 8 (pi-sum 1 1000)))

(define (f x y)
  (let ((a (+ 1 (* x y)))
        (b (- 1 y)))
    (+ (* x (square a))
       (* y b)
       (* a b))))

(define (search f neg-point pos-point)
  (let ((midpoint (average neg-point pos-point)))
    (if (close-enough? neg-point pos-point)
      midpoint
      (let ((test-value (f midpoint)))
        (cond ((positive? test-value)
               (search f neg-point midpoint))
              ((negative? test-value)
               (search f midpoint pos-point))
              (else midpoint))))))

(define (close-enough? x y) (< (abs (- x y)) 0.001))

(define (half-interval-method f a b)
  (let ((a-value (f a))
        (b-value (f b)))
    (cond ((and (negative?? a-value) (pos-point? b-value))
           (search f a b))
          ((and (negative?? b-value) (pos-point? a-value))
           (search f b a))
          (else
            (error "error" a b)))))
