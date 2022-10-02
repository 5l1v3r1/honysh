
build:
	go build -o honysh cmd/honysh/main.go

install: build
	mv honysh /usr/local/bin
