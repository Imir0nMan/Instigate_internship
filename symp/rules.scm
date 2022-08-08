;syntax-rules ()
(define-syntax քերականություն֊կանոն
 (syntax-rules ()
  ((_ b1 ...)
  (syntax-rules b1 ...)))
)


;define-syntax ()
(define-syntax սահմանել֊քերականություն
 (քերականություն֊կանոն ()
 ((_ անուն b1 ...)
 (define-syntax անուն b1 ...)))
)


;define ()
(սահմանել֊քերականություն սահմանել
    (քերականություն֊կանոն ()
      ((սահմանել անուն արգումենտներ)
       (define անուն արգումենտներ))))

;begin ()
(սահմանել֊քերականություն կատարել
	(քերականություն֊կանոն ()
	 ((կատարել գործողություն ...)
	  (begin գործողություն ...))))

;display ()
(սահմանել֊քերականություն տպել
 (քերականություն֊կանոն()
  ((տպել արտ)
  (կատարել (newline)
  (display արտ))))
)



;lambda ()
(սահմանել֊քերականություն լամբդա
    (քերականություն֊կանոն  ()
      ((_ () body)
       (lambda args
         (if (null? args)
             body
             apply body args)))
      ((_ (arg) body)
       (letrec
           ((partial-application
             (lambda args
               (if (null? args)
                   partial-application
                   (let ((arg (car args))
                         (rest (cdr args)))
                     (if (null? rest)
                         body
                         (apply body rest)))))))
         partial-application))
      ((_ (arg args ...) body)
       (letrec
           ((partial-application
             (lambda all-args
               (if (null? all-args)
                   partial-application
                   (let ((arg (car all-args))
                         (rest (cdr all-args)))
                     (let ((next (լամբդա (args ...) body)))
                       (if (null? rest)
                           next
                           (apply next rest))))))))
         partial-application))))

 
;(define-syntax քերականություն֊կանոն
;	(lambda (x)
;	  (syntax-case x ()
;	    [(_ (i ...) ((keyword . pattern) template) ...)
;	     #'(lambda (x)
;		(syntax-case x (i ...)
;	          [(_ . pattern) #'template] ...))])))
 
;for
(սահմանել կրկնել (lambda (start end func)
        (let loop ((index start))
        (if (> index end) #t
         (կատարել (func index) (loop (+ index 1))) ))))


 ;(կրկնել 1 10 (lambda (x) (display x) (newline)))


;while
(սահմանել֊քերականություն քանի
  (քերականություն֊կանոն (դեռ)
    ((_ դեռ condition . մարմին)
     (let loop ()
       (cond (condition
	      (կատարել . մարմին)
	      (loop)))))))
	  
(սահմանել counter 10)

;(քանի դեռ (> counter 0)
;   (display counter)
;   (newline)
;   (set! counter (- counter 1)))

;or ||
(սահմանել֊քերականություն կամ
   (lambda (x)
   (syntax-case x ()
   ((_) (syntax #f))
   ((_ e) (syntax e))
   ((_ e1 e2 e3 ...)
   (syntax (let ((t e1)) (if t t (կամ e2 e3 ...))))))))
          
;(display (կամ 214))

;and &&
(սահմանել֊քերականություն և
  (քերականություն֊կանոն ()
    ((_) #t)
    ((_ e) e)
    ((_ e1 e2 ...)
     (if e1
	 (և e2 ...)
	 #f))))

;(newline)
;(display (և 12 13))

;remainder %
(սահմանել֊քերականություն մնացորդ
	(քերականություն֊կանոն ()
	((մնացորդ թիվ1 թիվ2)
	 (remainder թիվ1 թիվ2))))
  

;expresion արտահայտություն  
(սահմանել֊քերականություն արտ
	(քերականություն֊կանոն ()
	 ((արտ թիվ1 գործողություն թիվ2)
	 (գործողություն թիվ1 թիվ2))))
	 
;(տպել (հաշվել 12 մնացորդ 45))
     
;(տպել (մնացորդ 13 7))
  
;when
(սահմանել֊քերականություն երբ
  (քերականություն֊կանոն ()
    ((_ պայման գործողություն1 գործողություն2)
     (if պայման գործողություն1 գործողություն2))))
 
;if else 
(սահմանել֊քերականություն եթե
  (քերականություն֊կանոն (ապա)
    ((_ պայման ապա գործ1 ...)
     (if պայման (կատարել գործ1 ...)))

	((_ պայման ապա գործ1 ... այլապես գործ)
	 (if պայման (կատարել գործ1 ...) գործ ))

	))
     
;(եթե (> 12 3) ապա (display "if block") այլապես (display "else block"))

    

;list
(սահմանել֊քերականություն ցուցակ
	(քերականություն֊կանոն ()
	((ցուցակ արժեք1 ...)
	(list արժեք1 ...))))
	
;not !
(սահմանել֊քերականություն ժխտում
	(քերականություն֊կանոն ()
	((ժխտում պայման)
	(not պայման))))
	
;sqrt
(սահմանել֊քերականություն արմատ
	(քերականություն֊կանոն ()
	((արմատ թիվ)
	 (sqrt թիվ))))
	 
;set!  =
(սահմանել֊քերականություն վերագրել
	(քերականություն֊կանոն ()
	((_ փոփոխական արժեք)
	(set! փոփոխական արժեք))))
	
	
;newline
(սահմանել֊քերականություն նորտող
	(քերականություն֊կանոն ()
	((_)
	(newline))))


;switch-case
(սահմանել֊քերականություն դիտարկել
 (քերականություն֊կանոն (դեպք անել)
  ((դիտարկել արտահայտություն (դեպք ա անել գործ1) (դեպք բ անել գործ2) ...)
  (begin (if (equal? ա արտահայտություն) գործ1)
  (if (equal? բ արտահայտություն) գործ2)
  ...)
  )
 )
)



