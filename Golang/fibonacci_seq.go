package main

import "fmt"

func fibonacci() func() int {
	n := 0
	a := 0
	b := 1
	c := a + b
	return func() int {
		var ret int
		switch {
		case n == 0:
			n++
			ret = 0
		case n == 1:
			n++
			ret = 1
		default:
			ret = c
			a = b
			b = c
			c = a + b
		}
		return ret
	}
}

func main() {
	//printing the first 20 elements of Fibonacci sequence
	fibo := fibonacci()
	for i := 0; i < 20; i++ {
		fmt.Println(fibo())
	}
}