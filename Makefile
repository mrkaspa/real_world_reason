build:
	dune build

run: build
	dune exec real_world

run-demo: build
	dune exec demo

run-csv: build
	dune exec csv_read

test:
	dune runtest

pin:
	opam pin add .

repin: build
	opam upgrade real_world

build-all:
	dune build

test-all:
	dune build  @runtest

.PHONY: build test pin repin build-all test-all
