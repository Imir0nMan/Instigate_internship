(define (D a b c )
	(- (* b b) (* 4 a c ))
)


(define (linear a b)
	(if (and (= a 0)(= b 0))
		"infinity"
		(if (= a 0)
	  		"none"
	  		(- (/ b a))))
)


(define (quadratic a b c)
	(define d (D a b c))
	(define v1 (- b))
	(if (< d 0)
		"There is no solution"
		(if (>= d 0)
	  		(if (not (= a 0))
				(list (/  (- v1 (sqrt d)) (* 2 a))  (/ (+ v1 (sqrt d)) (* 2 a)) )
				(linear b c)
			)))
)


(display (quadratic 0 4 0))
