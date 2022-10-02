package main

import (
	"os"

	honysh "github.com/traumatism/honysh/pkg/core"
)

func main() {
	if len(os.Args) < 2 || (os.Args[1] != "left" && os.Args[1] != "right") {
		println("honysh <left/right>")
		os.Exit(1)
	}

	honysh.ResizeWindow(honysh.GetTopWindowPID(), 15, os.Args[1])
}
