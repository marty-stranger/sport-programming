package main

import "fmt"

func main() {
	var k int
	fmt.Scan(&k)

	var a [12]int
	for i := 0; i < 12; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < 12; i++ {
		for j := i + 1; j < 12; j++ {
			if a[j] > a[i] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}

	if k == 0 {
		fmt.Println("0")
		return
	}

	for i := 0; i < 12; i++ {
		if k > a[i] {
			k -= a[i]
		} else {
			fmt.Println(i+1)
			return
		}
	}

	fmt.Println("-1")
}
