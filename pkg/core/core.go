package honysh

// #cgo LDFLAGS: -framework Carbon
// #cgo CFLAGS: -Wno-deprecated
// #include "honysh.h"
import "C"

type ScreenSize struct {
	width  int
	height int
}

func GetScreenSize() *ScreenSize {

	display := C.CGMainDisplayID()

	return &ScreenSize{
		width:  int(C.CGDisplayPixelsWide(display)),
		height: int(C.CGDisplayPixelsHigh(display)),
	}

}

func GetTopWindowPID() C.int {
	var pid C.int
	var psn C.ProcessSerialNumber

	C.GetFrontProcess(&psn)
	C.GetProcessPID(&psn, &pid)

	return pid
}

func ResizeWindow(pid C.int, gap int, position string) {

	size := GetScreenSize()

	switch position {
	case "left":
		C.resize(
			pid,
			C.float(gap),
			C.float(gap),
			C.float(size.width/2-gap),
			C.float(size.height),
		)
	case "right":
		C.resize(
			C.int(pid),
			C.float(size.width/2+gap/2),
			C.float(gap),
			C.float((size.width/2)-gap-(gap/2)),
			C.float(size.height),
		)
	}
}
