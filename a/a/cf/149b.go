package main

import (
	"fmt"
	// "strings"
	"strconv"
)

/* func conv(s string, b int) (int, bool) {
	v := 0
	for _, c := range s {
		v *= b
		var d int
		if '0' <= c && c <= '9' {
			d = c - '0'
		} else {
			d = c - 'A' + 10
		}

		if d >= b {
			return 0, false
		}

		v += d
	}

	return v, true
} */

func test(h, m string, b int) bool {
	if i, e := strconv.ParseInt(h, b, 0); i >= 24 || e != nil {
		return false
	}

	if i, e := strconv.ParseInt(m, b, 0); i >= 60 || e != nil {
		return false
	}

	return true
}

func main() {
	var s string
	fmt.Scan(&s)

	list := strings.Split(s, ":")
	hs, ms := list[0], list[1]

	if test(hs, ms, 61) {
		fmt.Println("-1")
		return
	}

	f := true
	for b := 2; b < 60; b++ {
		if test(hs, ms, b) {
			fmt.Println(b)
			f = false
		}
	}

	if f {
		fmt.Println("0")
	}
}
