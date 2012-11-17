(benchmark fuzzsmt
:logic QF_AUFBV
:status sat
:extrafuns ((v0 BitVec[12]))
:extrafuns ((a1 Array[10:2]))
:formula
(let (?e2 bv62635[16])
(let (?e3 (bvand ?e2 ?e2))
(let (?e4 (bvnand v0 v0))
(let (?e5 (store a1 (extract[9:0] v0) (extract[5:4] ?e3)))
(let (?e6 (store ?e5 (extract[10:1] ?e4) (extract[10:9] ?e4)))
(let (?e7 (select ?e5 (extract[10:1] v0)))
(let (?e8 (select ?e6 (extract[14:5] ?e3)))
(let (?e9 (store ?e5 (extract[15:6] ?e3) (extract[11:10] ?e2)))
(let (?e10 (select ?e6 (sign_extend[8] ?e8)))
(let (?e11 (select ?e5 (extract[9:0] ?e4)))
(let (?e12 (bvnot v0))
(let (?e13 (zero_extend[10] ?e10))
(let (?e14 (bvsub ?e2 (sign_extend[14] ?e8)))
(let (?e15 (bvsmod (sign_extend[10] ?e8) ?e13))
(let (?e16 (bvurem ?e14 ?e14))
(let (?e17 (ite (= ?e15 ?e12) bv1[1] bv0[1]))
(let (?e18 (bvadd (sign_extend[14] ?e7) ?e3))
(let (?e19 (sign_extend[3] ?e13))
(let (?e20 (bvurem (zero_extend[11] ?e17) ?e12))
(let (?e21 (sign_extend[8] ?e11))
(let (?e22 (bvxnor (zero_extend[4] ?e4) ?e14))
(flet ($e23 (bvult ?e22 (sign_extend[4] v0)))
(flet ($e24 (bvsge ?e18 (sign_extend[4] ?e4)))
(flet ($e25 (bvsgt ?e2 (sign_extend[4] ?e15)))
(flet ($e26 (bvsge ?e22 (sign_extend[4] ?e15)))
(flet ($e27 (= ?e20 ?e12))
(flet ($e28 (distinct (sign_extend[10] ?e7) ?e12))
(flet ($e29 (distinct (zero_extend[13] ?e7) ?e19))
(flet ($e30 (bvsgt ?e2 (sign_extend[4] ?e4)))
(flet ($e31 (bvult ?e2 (zero_extend[4] v0)))
(flet ($e32 (bvslt (zero_extend[10] ?e8) ?e12))
(flet ($e33 (bvslt ?e4 ?e4))
(flet ($e34 (bvsle ?e15 ?e15))
(flet ($e35 (bvugt (zero_extend[14] ?e10) ?e2))
(flet ($e36 (bvult ?e8 ?e7))
(flet ($e37 (bvugt (sign_extend[14] ?e10) ?e16))
(flet ($e38 (bvult v0 ?e20))
(flet ($e39 (bvsgt ?e8 ?e10))
(flet ($e40 (bvsle (zero_extend[11] ?e17) v0))
(flet ($e41 (distinct (zero_extend[14] ?e17) ?e19))
(flet ($e42 (distinct (zero_extend[11] ?e17) ?e20))
(flet ($e43 (bvule (sign_extend[10] ?e7) ?e12))
(flet ($e44 (bvsle ?e18 (sign_extend[14] ?e10)))
(flet ($e45 (bvsgt ?e2 ?e14))
(flet ($e46 (bvult ?e13 v0))
(flet ($e47 (bvsge ?e20 (zero_extend[11] ?e17)))
(flet ($e48 (bvule (sign_extend[5] ?e21) ?e19))
(flet ($e49 (bvsgt ?e16 (sign_extend[6] ?e21)))
(flet ($e50 (bvult (sign_extend[14] ?e11) ?e14))
(flet ($e51 (distinct ?e22 (zero_extend[4] ?e12)))
(flet ($e52 (bvuge (sign_extend[4] ?e12) ?e22))
(flet ($e53 (bvsgt (sign_extend[2] ?e21) ?e13))
(flet ($e54 (bvslt (sign_extend[14] ?e8) ?e2))
(flet ($e55 (bvule ?e13 (zero_extend[10] ?e11)))
(flet ($e56 (= ?e2 ?e14))
(flet ($e57 (distinct ?e22 ?e3))
(flet ($e58 (or $e52 $e23))
(flet ($e59 (implies $e48 $e41))
(flet ($e60 (if_then_else $e25 $e58 $e37))
(flet ($e61 (implies $e51 $e32))
(flet ($e62 (not $e40))
(flet ($e63 (not $e54))
(flet ($e64 (and $e34 $e31))
(flet ($e65 (and $e47 $e59))
(flet ($e66 (implies $e43 $e28))
(flet ($e67 (iff $e49 $e65))
(flet ($e68 (if_then_else $e56 $e53 $e60))
(flet ($e69 (implies $e57 $e30))
(flet ($e70 (if_then_else $e69 $e42 $e38))
(flet ($e71 (iff $e68 $e39))
(flet ($e72 (xor $e44 $e33))
(flet ($e73 (implies $e70 $e67))
(flet ($e74 (or $e45 $e24))
(flet ($e75 (and $e26 $e74))
(flet ($e76 (not $e36))
(flet ($e77 (and $e76 $e71))
(flet ($e78 (not $e50))
(flet ($e79 (implies $e46 $e61))
(flet ($e80 (iff $e66 $e72))
(flet ($e81 (or $e73 $e29))
(flet ($e82 (if_then_else $e27 $e77 $e79))
(flet ($e83 (implies $e35 $e81))
(flet ($e84 (xor $e62 $e55))
(flet ($e85 (not $e80))
(flet ($e86 (iff $e84 $e82))
(flet ($e87 (implies $e64 $e63))
(flet ($e88 (implies $e87 $e83))
(flet ($e89 (if_then_else $e75 $e85 $e88))
(flet ($e90 (xor $e86 $e78))
(flet ($e91 (implies $e89 $e90))
(flet ($e92 (and $e91 (not (= ?e13 bv0[12]))))
(flet ($e93 (and $e92 (not (= ?e13 (bvnot bv0[12])))))
(flet ($e94 (and $e93 (not (= ?e14 bv0[16]))))
(flet ($e95 (and $e94 (not (= ?e12 bv0[12]))))
$e95
)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

