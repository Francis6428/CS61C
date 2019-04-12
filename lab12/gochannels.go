package main

import "fmt"

func send_int(n int, c chan int) {
	c <- n
}

func main() {
	c := make(chan int)
	go send_int(20, c)
	go send_int(30, c)
	fmt.Println(<-c, <-c)

	c1 := make(chan int, 2)
	c1 <- 1
	c1 <- 2
	// c1 <- 3 // UNCOMMENT THIS LINE TO SEE WHAT HAPPENS
	fmt.Println(<-c1, <-c1)
}
