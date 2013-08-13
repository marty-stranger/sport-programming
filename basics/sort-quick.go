package main

import "fmt"

var a []int

func s(l, r int) {
	if l >= r {
		return
	}

	i, j, p := l, r, a[(l + r) / 2]
	for i <= j {
		if a[i] < p {
			i++
		} else if a[j] > p {
			j--
		} else {
			a[i], a[j] = a[j], a[i]
			i++; j--
		}
	}

	s(l, j); s(i, r);
}

func main() {
	var n int; fmt.Scan(&n)

	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	s(0, n - 1)

	fmt.Println(a)
}
