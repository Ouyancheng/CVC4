(set-logic ALL)
(set-info :status sat)
(declare-fun t () (Tuple String String String String))
(declare-fun u () (Tuple String String))
(declare-fun v () Tuple)
(declare-fun x () String)
(assert (= t (mkTuple "a" "b" "c" "d")))
(assert (= x ((_ tupSel 0) t)))
(assert (= u ((_ tuple_project 2 3) t)))
(assert (= v (tuple_project t)))
(check-sat)