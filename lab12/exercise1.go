// Put package name here
package main
// Put imported packages here
import "fmt"
import "math/rand"

func main() {
	// Put our function calls here
	fmt.Println("Hello World!")
	random()
}

// Put Random function here
func random() {
	fmt.Println("Your random number of the day is", rand.Intn(10))
}
