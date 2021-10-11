package main

func Fibonacci(n int) uint64 {
	if n == 0 {
		return 0
	}
	var fn, f1, f2 uint64
	fn, f1, f2 = 1, 1, 1
	for i := 2; i < n; i++ {
		fn = f1 + f2
		f2, f1 = f1, fn
	}
	return fn
}
