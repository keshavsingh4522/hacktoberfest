package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(findNumbers([]int{12, 345, 2, 6, 7896}))
}

func findNumbers(nums []int) int {
	result := 0
	i := 0
	for i < len(nums) {
		if len(strconv.Itoa(nums[i]))%2 == 0 {
			result = result + 1
		}
		i = i + 1
	}
	return result
}
