package main

import "fmt"

func main() {
	fmt.Println(xorOperation(10, 5))
}

func xorOperation(n int, start int) int {
	nums := []int{}
	num := 0
	for num < n {
		nums = append(nums, start+2*num)
		num = num + 1
	}

	i := 0
	result := 0
	for i < n {
		result = result ^ nums[i]
		i = i + 1
	}

	return result
}
