package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type Reader struct {
	*bufio.Scanner
}

func NewReader(r io.Reader) Reader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return Reader{scanner}
}

func (r Reader) String() string {
	b := r.Scan()
	if !b {
		panic(nil)
	}

	return r.Text()
}

func (r Reader) Int() int {
	b := r.Scan()
	if !b {
		panic(nil)
	}

	v, e := strconv.Atoi(r.Text())
	if e != nil {
		panic(e)
	}
	return v
}

func main() {
	in := NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := 5 * 100000
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.Int()
	}

	b := make([]int, n)
	m := make(map[int]int)
	for i, x := range a {
		if j, y := m[x]; y {
			b[i] = j
		} else {
			b[i] = -1
		}
		m[x] = i
	}

	s := 0
	for _, x := range b {
		s += (x + 1)
	}

	fmt.Println(s)
}
