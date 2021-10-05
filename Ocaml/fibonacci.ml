let rec fib n = match n with
    0 -> 1 |
    1 -> 1 |
    n -> (fib (n-1)) + (fib (n-2));;

print_int(fib 5);;
print_string("\n");;

let rec fib_tr n =
    let rec fib_tr_aux n (a, b) = match n with
        0 -> a |
        1 -> b |
        n -> fib_tr_aux (n-1) (b, a+b)
    in fib_tr_aux n (1, 1);;

print_int(fib_tr 5);;
print_string("\n");;