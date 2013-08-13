package main

import (
	"fmt"
)

type Interface interface {
	Less(Interface) bool
}

type Heap struct {
	a []Interface
}

func (h *Heap) Insert(v Interface) {
	h.a = append(h.a, nil)

	i := len(h.a) - 1; j := (i - 1) / 2
	for i != 0 && v.Less(h.a[j]) {
		h.a[i] = h.a[j]
		i = j
		j = (i - 1) / 2
	}
	h.a[i] = v
}

func (h *Heap) ExtractMin() Interface {
	if len(h.a) == 0 {
		return nil
	}

	v := h.a[0]
	h.a[0] = h.a[len(h.a) - 1]
	h.a = h.a[:len(h.a) - 1]

	if len(h.a) == 0 {
		return v
	}

	t := h.a[0]
	i := 0

	/*
	j := 2*i+1
	for j < len(h.a) && h.a[j].Less(t) || j+1 < len(h.a) && h.a[j+1].Less(t) {
		if j+1 < n && h.a[j+1].Less(h.a[j]) {
			j++
		}

		h.a[i] = h.a[j]
		i = j
		j = 2*i + 1
	}
	*/

	for {
		j := 2*i + 1

		if !(j < len(h.a)) {
			break
		}

		if j+1 < len(h.a) && h.a[j+1].Less(h.a[j]) {
			j++
		}

		if !h.a[j].Less(h.a[i]) {
			break
		}

		h.a[i] = h.a[j]
		i = j
		j = 2*i+1
	}

	h.a[i] = t

	return v
}

func (h *Heap) Min() Interface {
	if len(h.a) != 0 {
		return h.a[0]
	}

	return nil
}

type Int int

func (i Int) Less(j Interface) bool {
	return i < j.(Int)
}

func main() {
	h := &Heap{}

	for {
		var c string
		fmt.Scanf("%s", &c)

		switch c {
		case "i":
			var v Int
			fmt.Scanf("%d", &v)
			h.Insert(v)
		case "m":
			fmt.Println("min ", h.Min())
		case "e":
			fmt.Println("extract-min ", h.ExtractMin())
		case "p":
			fmt.Println("heap ", h)
		}
	}
}
