func sum(numbers ...int) int {
    total := 0
    for _, num := range numbers {
        total += num
    }
    return total
}

// You can call the sum function with any number of integers: result := sum(1, 2, 3, 4, 5)
