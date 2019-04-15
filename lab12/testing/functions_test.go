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
	x := []int{-100, 1, 2}
	sum := AbsSum(x)
	if sum != 97 {
		t.Error("Expected 97, got", sum)
	}
}

func TestProd(t *testing.T) {
	// Test our product function
	x := []int{1, 2, 3}
	prod := Prod(x)
	if prod != 6 {
		t.Error("Expected 6, got", prod)
	}
}

func TestSub(t *testing.T) {
	// Test our subtraction function
	x := []int{1, 2, 3}
	sub := Sub(x)
	if sub != -6 {
		t.Error("Expected -6, got", sub)
	}
}
