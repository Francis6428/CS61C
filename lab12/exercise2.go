package main

import (
	"fmt"
)

func main() {
	print_squares(10)
	fmt.Println()
	print_even_squares(10)
	fmt.Println()
	print_fibonacci(10)
	fmt.Println()
}

func square(n int) int {
	return n * n
}

func print_squares(n int) {
	for i := 1; i <= n; i += 1 {
		fmt.Print(square(i), " ")
	}
	print("\n")
}

func print_even_squares(n int) {
	for i := 2; i <= n; i += 2 {
		fmt.Print(square(i), " ")
	}
	fmt.Print("\n")
}

func print_fibonacci(n int) {
	a := 1
	b := 1
	if (n >= 1) {
		fmt.Print(a, " ")
	}
	if (n >= 2) {
		fmt.Print(b, " ")
	}
	for i := 3; i <= n; i += 1 {
		t := a + b
		a = b
		b = t
		fmt.Print(t, " ")
	}
	fmt.Print("\n")
}
