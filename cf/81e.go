// wrong solution. just sketch
package main

import (
	"fmt"
)

type Vertex struct {
	Index int
	Friend *Vertex
	Sex bool
	Children []*Vertex
	Visited bool
	Pair *Vertex
}

func remove(v *Vertex) {
	c := v.Friend.Children
	for i, u := range c {
		if u == v {
			copy(c[i:], c[i+1:])
			c = c[:len(c)-1]
			break
		}
	}
}

type Count struct {
	Pairs, BoyGirlsPairs int
}

func (c Count) Add(cc Count) Count {
	return Count{c.Pairs + cc.Pairs, c.BoyGirlsPairs + cc.BoyGirlsPairs}
}

func (c Count) Sub(cc Count) Count {
	return Count{c.Pairs - cc.Pairs, c.BoyGirlsPairs - cc.BoyGirlsPairs}
}

func (c Count) Greater(cc Count) bool {
	return c.Pairs > cc.Pairs ||
		c.Pairs == cc.Pairs && c.BoyGirlsPairs > cc.BoyGirlsPairs
}

func (v *Vertex) Count() (freeCount Count, count Count) {
	v.Visited = true

	freeCounts := make([]Count, len(v.Children))
	counts := make([]Count, len(v.Children))
	for i, u := range v.Children {
		freeCounts[i], counts[i] = u.Count()
		freeCount.Add(counts[i])
	}

	count = freeCount
	for i, u := range v.Children {
		c := freeCount.Sub(counts[i]).Add(freeCounts[i])

		c.Pairs++
		if u.Sex != v.Sex {
			c.BoyGirlsPairs++
		}

		if c.Greater(count) {
			count = c
			v.Pair = u
		}
	}

	return
}

var edges []*Vertex

func backtrace(v *Vertex, free bool) {
	if free {
		for _, u := range v.Children {
			if u == v.Pair {
				edges = append(edges, u)
			}

			backtrace(u, u != v.Pair)
		}
	} else {
		for _, u := range v.Children {
			backtrace(u, true)
		}
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	vertices := make([]Vertex, n)
	for i := 0; i < n; i++ {
		var j, s int
		fmt.Scan(&j, &s)
		j--

		vertices[i].Index = i
		vertices[i].Friend = &vertices[j]
		vertices[i].Sex = s == 1
		vertices[j].Children = append(vertices[j].Children, &vertices[i])
	}

	total := Count{}
	for _, v := range vertices {
		v := &v
		if !v.Visited {
			u := v
			for !u.Visited {
				u.Visited = true
				u = u.Friend
			}

			w := u.Friend

			remove(u)
			remove(w)

			uFreeCount, uCount := u.Count()
			wFreeCount, wCount := w.Count()

			pairedCount := uFreeCount.Add(wFreeCount)
			pairedCount.Pairs++
			if u.Sex != w.Sex {
				pairedCount.BoyGirlsPairs++
			}

			nonPairedCount := uCount.Add(wCount)

			if pairedCount.Greater(nonPairedCount) {
				total.Add(pairedCount)
				edges = append(edges, v)
				backtrace(v, false)
				backtrace(w, false)
			} else {
				total.Add(nonPairedCount)
				backtrace(v, true)
				backtrace(w, true)
			}
		}
	}

	fmt.Println(total.Pairs, total.BoyGirlsPairs)
	for _, u := range edges {
		fmt.Println(u.Index+1, u.Friend.Index+1)
	}
}
