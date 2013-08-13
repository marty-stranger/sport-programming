package main

import "fmt"
import "time"
import "os"

type Interface interface {
	Less(Interface) bool
}

func Sort(a []Interface, l, r int) {
	if l >= r {
		return
	}

	i, j, p := l, r, a[(l + r) / 2]
	for i <= j {
		if a[i].Less(p) {
			i++
		} else if p.Less(a[j]) {
			j--
		} else {
			a[i], a[j] = a[j], a[i]
			i++; j--
		}
	}

	Sort(a, l, j); Sort(a, i, r)
}

type Int int

func (a Int) Less(b Interface) bool {
	return a < b.(Int)
}

func measure(f func()) {
	t := time.Now()
	f()
	fmt.Fprintln(os.Stderr, time.Now().Sub(t))
}

func main() {
	var n int; fmt.Scan(&n)

	var a []Interface
	measure(func() {
		a = make([]Interface, n)
		for i := 0; i < n; i++ {
			var b Int
			fmt.Scan(&b)
			a[i] = b
		}
	})

	measure(func() {
		Sort(a, 0, n-1)
	})

	measure(func() {
		fmt.Println(a)
	})
}
