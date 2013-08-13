package main

import "fmt"
import "time"
import "os"

var a []int

func Sort(l, r int) {
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

	Sort(l, j); Sort(i, r);
}

func measure(f func()) {
	t := time.Now()
	f()
	fmt.Fprintln(os.Stderr, time.Now().Sub(t))
}

func main() {
	var n int; fmt.Scan(&n)

	measure(func() {
		a = make([]int, n)
		for i := 0; i < n; i++ {
			// fmt.Scan(&a[i])
			fmt.Scanf("%d", &a[i])
		}
	})

	measure(func() {
		Sort(0, n-1)
	})

	measure(func() {
		for _, v := range a {
			fmt.Println(v)
		}
	})
}
