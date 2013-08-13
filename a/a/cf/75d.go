package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type subarray struct {
	t, l, r, m int
}

func main() {
	var n, m int; fmt.Scan(&n, &m)

	var subarrays [50]subarray
	for i := 0; i < n; i++ {
		var k int; fmt.Scan(&k)

		t, l, r := 0, 0, 0
		s := 0
		var m int = -1e9
		for j := 0; j < k; j++ {
			var a int; fmt.Scan(&a)

			t += a
			m = max(m, a)
			l = max(l, t)
			r = min(r, t)

			s += a

			if s < 0 {
				s = 0
			} else {
				m = max(m, s)
			}
		}

		r = t - r

		subarrays[i] = subarray{t, l, r, m}
		// fmt.Println(subs[i])
	}

	s := 0
	var r int = -1e9
	for i := 0; i < m; i++ {
		var j int; fmt.Scan(&j); j--

		a := subarrays[j];
		r = max(r, a.m)
		if s > 0 {
			r = max(r, s + a.l)
		}
		s = max(0, max(a.r, s + a.t))
	}

	fmt.Println(r)
}
