package functions

import "testing"

func TestAbsSumPos(t *testing.T) {
	x := []int{12, 14, 16}
	sum := AbsSum(x)
	if sum != 42 {
		t.Error("Expected 42, got", sum)
	}
}

func TestAbsSumNeg(t *testing.T) {
	// Test for negatives too
}

func TestProd(t *testing.T) {
	// Test our product function
}

func TestSub(t *testing.T) {
	// Test our subtraction function
}
