(define (linear a b)
  (if (and (= a 0)(= b 0))
			"infinity"
		   (if (= a 0)
			   "none"
			    (- (/ b a)))))

(display (linear 4 0))

