package main

func main() {
	n := 100000000

	a := make([]int, n)

	for i := 0; i < n; i++ {
		a[i] = i
	}

	s := 0
	for i := 0; i < n; i++ {
		s += a[i]
	}

	println(s)
}
