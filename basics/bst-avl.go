package main

import (
	"fmt"
)

type Interface interface {
	Less(Interface) bool
}

type tree struct {
	key	Interface
	left	*tree
	right	*tree
	diff	int
}


func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

/*
// possible shortcut, d = 0 - left, d = 1 - right
func (t *tree) rotate(d int) *tree {
	s := t.c[d]
	t.c[d] = s.c[1 - d]
	s.c[1 - d] = t

	f := 1 - 2*d
	t.diff -= f * (1 + max(0, f * s.diff)
	t.diff += f * (1 + max(0, f * t.diff)
}
*/

func (t *tree) rotateLeft() *tree {
	s := t.left
	t.left = s.right
	s.right = t

	t.diff += 1 + max(0, -s.diff)
	s.diff += 1 + max(0, t.diff)

	return s
}

func (t *tree) rotateRight() *tree {
	s := t.right
	t.right = s.left
	s.left = t

	t.diff -= 1 + max(0, s.diff)
	s.diff -= 1 + max(0, -t.diff)

	return s
}

// returns true if height was decreased
func (t *tree) balance() (*tree, bool) {
	var b bool
	switch t.diff {
	case -2:
		s := t.left
		b = s.diff != 0
		if s.diff == 1 {
			t.left = t.left.rotateRight()
		}
		t = t.rotateLeft()
	case 2:
		s := t.right
		b = s.diff != 0
		if s.diff == -1 {
			t.right = t.right.rotateLeft()
		}
		t = t.rotateRight()
	}

	return t, b
}

// returns true if height was increased
func (t *tree) Insert(k Interface) (*tree, bool) {
	if t == nil {
		return &tree{key: k}, true
	}

	var b bool
	if k.Less(t.key) {
		t.left, b = t.left.Insert(k)
		if b {
			b = t.diff != 1
			t.diff--
		}
	} else {
		t.right, b = t.right.Insert(k)
		if b {
			b = t.diff != -1
			t.diff++
		}
	}

	if b {
		var d bool
		t, d = t.balance()
		b = !d
	}

	return t, b
}

type Tree struct { root *tree }

func (t *Tree) Insert(k Interface) {
	t.root, _ = t.root.Insert(k)
}

func (t *tree) Print(d int) {
	if t != nil {
		t.left.Print(d + 1)

		s := ""
		for i := 0; i < d; i++ { s += "\t" }
		fmt.Printf("%s%v(%d)\n", s, t.key, t.diff)
		t.right.Print(d + 1)
	}
}

func (t *Tree) Print() {
	t.root.Print(0)
}

type Int int

func (i Int) Less(j Interface) bool {
	return i < j.(Int)
}

func main() {
	t := &Tree{}

	for {
		var c string
		fmt.Scanf("%s", &c)

		var v Int
		if c != "p" {
			fmt.Scanf("%d", &v)
		}

		switch c {
		case "i":
			t.Insert(v)
		/* case "d":
			t.Delete(v)
		case "f":
			fmt.Println("find: ", t.Find(v)) */
		case "p":
			fmt.Println("print: ")
			t.Print()
		}
	}
}
