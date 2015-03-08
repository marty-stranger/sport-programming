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

func reverse(s string) string {
	b := []byte(s)

	for l, r := 0, len(b)-1; l < r; l, r = l+1, r-1 {
		b[l], b[r] = b[r], b[l]
	}

	return string(b)
}

type Fenwick []int64

func MakeFenwick(n int) Fenwick {
	return Fenwick(make([]int64, n))
}

func (f Fenwick) Update(i int, d int64) {
	for i < len(f) {
		f[i] += d
		i = i | (i + 1)
	}
}

func (f Fenwick) Query(i int) int64 {
	s := int64(0)

	for i >= 0 {
		s += f[i]
		i = i&(i+1) - 1
	}

	return s
}

type Hashs struct {
	fenwick Fenwick
	bytes   []byte
	coefs   []int64
	rev     bool
}

const (
	base   = 13
	modulo = 1000000000 + 7
)

func MakeHashs(s string, rev bool) *Hashs {
	coefs := make([]int64, len(s))
	coefs[0] = 1
	for i := 1; i < len(s); i++ {
		coefs[i] = (coefs[i-1] * base) % modulo
	}

	if rev {
		s = reverse(s)
	}

	fenwick := MakeFenwick(len(s))

	for i := 0; i < len(s); i++ {
		d := int64(s[i]-'a') * coefs[i] % modulo
		fenwick.Update(i, d)
	}

	return &Hashs{
		fenwick,
		[]byte(s),
		coefs,
		rev,
	}

}

func (h Hashs) Update(i int, v byte) {
	if h.rev {
		i = len(h.bytes) - 1 - i
	}

	vv := int64(v-'a') * h.coefs[i] % modulo
	p := (h.fenwick.Query(i) - h.fenwick.Query(i-1) + modulo) % modulo
	h.bytes[i] = v
	h.fenwick.Update(i, vv-p)
}

func (h Hashs) Query(l, r int) int64 {
	if h.rev {
		l, r = len(h.bytes)-1-r, len(h.bytes)-1-l
	}

	v := (h.fenwick.Query(r) - h.fenwick.Query(l-1) + modulo) % modulo

	if l <= len(h.bytes)-1-r {
		v = v * h.coefs[len(h.bytes)-1-r-l] % modulo
	}

	return v
}

func main() {
	in := NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var s string
	fmt.Scan(&s)

	lr := MakeHashs(s, false)
	rl := MakeHashs(s, true)

	n := in.Int()
	for i := 0; i < n; i++ {
		cmd := in.String()

		if cmd[0] == 'c' {
			i, c := in.Int()-1, in.String()

			lr.Update(i, c[0])
			rl.Update(i, c[0])
		} else {
			i, j := in.Int()-1, in.Int()-1

			if lr.Query(i, j) == rl.Query(i, j) {
				out.WriteString("Yes\n")
			} else {
				out.WriteString("No\n")
			}
		}
	}
}
