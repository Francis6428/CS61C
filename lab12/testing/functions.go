package functions

func AbsSum(n []int) int {
	total := 0
	for _, x := range n {
		total += x
	}
	if total > 0 {
		return total
	}
	return -1 * total
}

func Prod(n []int) int {
	total := 1
	for _, x := range n {
		total *= x
	}
	return total
}

func Sub(n []int) int {
	total := 0
	for _, x := range n {
		total -= x
	}
	return total
}
