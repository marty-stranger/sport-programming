package main

import (
	"fmt"
)

type Interface interface {
	Less(Interface) bool
}

const (
	black = false
	red = true
)

type color bool

func (c color) String() string {
	if c {
		return "Red"
	}

	return "Black"
}

type tree struct {
	key	Interface
	left	*tree
	right	*tree
	color
}

func (t *tree) String() string {
	return fmt.Sprintf("k:%v c:%v", t.key, t.color)
}

func (t *tree) RotateLeft() *tree {
	s := t.right
	t.right = s.left
	s.left = t

	s.color = t.color
	t.color = red

	return s
}

func (t *tree) RotateRight() *tree {
	s := t.left
	t.left = s.right
	s.right = t

	s.color = t.color
	t.color = red

	return s
}

func (t *tree) FlipColor() {
	t.color = !t.color
}

func (t *tree) FlipColors() {
	t.FlipColor()
	t.left.FlipColor()
	t.right.FlipColor()
}

func (t *tree) IsRed() bool {
	return t != nil && bool(t.color)
}

func (t *tree) MoveRedLeft() *tree {
	t.FlipColors()

	if t.right.left.IsRed() {
		t.right = t.right.RotateRight()
		t = t.RotateLeft()
		t.FlipColors()
	}

	return t
}

func (t *tree) MoveRedRight() *tree {
	t.FlipColors()

	if t.left.left.IsRed() {
		t = t.RotateLeft()
		t.FlipColors()
	}

	return t
}

func (t *tree) FixUp() *tree {
	if t.right.IsRed() {
		t = t.RotateLeft()
	}
	if t.left.IsRed() && t.left.left.IsRed() {
		t = t.RotateRight()
	}
	if t.left.IsRed() && t.right.IsRed() {
		t.FlipColors()
	}
	return t
}

func (t *tree) Min() Interface {
	for t.left != nil {
		t = t.left
	}

	return t.key
}

func (t *tree) DeleteMin() *tree {
	if t.left == nil {
		return nil
	}

	if !t.left.IsRed() && !t.left.left.IsRed() {
		t = t.MoveRedLeft()
	}

	t.left = t.left.DeleteMin()

	return t.FixUp()
}

func (t *tree) Insert(k Interface) *tree {
	if t == nil {
		return &tree{key: k, color: red}
	}

	if k.Less(t.key) {
		t.left = t.left.Insert(k)
	} else {
		t.right = t.right.Insert(k)
	}

	return t.FixUp()
}

func (t *tree) Delete(k Interface) *tree {
	if k.Less(t.key) {
		if !t.left.IsRed() && !t.left.left.IsRed() {
			t = t.MoveRedLeft()
		}

		t.left = t.left.Delete(k)
	} else {
		if t.left.IsRed() {
			t = t.RotateRight()
		}

		if k == t.key && t.right == nil {
			return nil
		}
		if !t.right.IsRed() && !t.right.left.IsRed() {
			t = t.MoveRedRight()
		}

		if k == t.key {
			t.key = t.right.Min()
			t.right = t.right.DeleteMin()
		} else {
			t.right = t.right.Delete(k)
		}
	}

	return t.FixUp()
}

type Tree struct { root *tree }

func (t *Tree) Insert(k Interface) {
	t.root = t.root.Insert(k)
	t.root.color = black
}

func (t *Tree) Find(k Interface) bool {
	s := t.root
	for s != nil && s.key != k {
		if k.Less(s.key) {
			s = s.left
		} else {
			s = s.right
		}
	}

	return s != nil
}

func (t *Tree) Delete(k Interface) {
	t.root = t.root.Delete(k)
	if t.root != nil {
		t.root.color = black
	}
}

func (t *tree) Print(d int) {
	if t != nil {
		t.left.Print(d + 1)
		fmt.Printf("%v:%d:%v ", t.key, d, t.color)
		t.right.Print(d + 1)
	}
}

func (t *Tree) Print() {
	t.root.Print(1)
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
		case "d":
			t.Delete(v)
		case "f":
			fmt.Println("find: ", t.Find(v))
		case "p":
			t.Print()
			fmt.Println()
		}
	}
}
