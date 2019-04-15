package main

import "fmt"

func return_range(n int, c chan int) {
	for i := 0; i < n; i++ {
		c <- i
	}
	close(c)
}

func main() {
	size := 10
	sum := 0
	// Implement Me
	c := make(chan int, size)
	go return_range(size, c)
	for i := range c {
		sum += i * i + 1
	}
	fmt.Println(sum)
}
