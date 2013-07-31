package main

import "fmt"

func reverse(s string) string {
	b := []byte(s)

	for l, r := 0, len(b) - 1; l < r; l, r = l+1, r-1 {
		b[l], b[r] = b[r], b[l]
	}

	return string(b)
}

func match(s, p string) ([]int, bool) {
	// fmt.Println("match", s, p)
	l := make([]int, len(p))
	l[0] = 0

	k := 0
	for i := 1; i < len(p); i++ {
		for k > 0 && p[k] != p[i] {
			k = l[k-1]
		}

		if p[k] == p[i] {
			k++
		}

		l[i] = k
	}
	// fmt.Println("l =", l)

	ends := make([]int, len(p))
	for i := 0; i < len(p); i++ {
		ends[i] = -1
	}

	k = 0
	for i := 0; i < len(s); i++ {
		for k > 0 && p[k] != s[i] {
			k = l[k-1]
		}

		if p[k] == s[i] {
			k++
		}

		if k == len(p) {
			return nil, true
		}

		if ends[k] == -1 || i < ends[k] {
			ends[k] = i
		}
	}

	// fmt.Println("ends", ends)

	return ends, false
}

func matchBeauty(s, t string) bool {
	ends, f := match(s, t)
	if f {
		return true
	}

	revEnds, f := match(reverse(s), reverse(t))
	if f {
		return true
	}

	for i := 1; i < len(t); i++ {
		if i1, i2 := ends[i], revEnds[len(t)-i]; i1 != -1 && i2 != -1 && i1 < len(s)-1-i2 {
			return true
		}
	}

	return false
}

func main() {
	var s string; fmt.Scan(&s)
	var m int; fmt.Scan(&m)

	c := 0
	for i := 0; i < m; i++ {
		var t string; fmt.Scan(&t)

		if len(t) == 1 {
			continue
		}

		if matchBeauty(s, t) {
			c++
		}
	}

	fmt.Println(c)
}
