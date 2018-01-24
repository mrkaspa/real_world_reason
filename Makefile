build:
	jbuilder build --workspace jbuild-workspace.dev @install

run: build
	jbuilder exec --workspace jbuild-workspace.dev real_world

run-demo: build
	jbuilder exec --workspace jbuild-workspace.dev demo

run-csv: build
	jbuilder exec csv_read

test:
	jbuilder runtest

pin:
	opam pin add .

repin: build
	opam upgrade real_world

build-all:
	jbuilder build --workspace jbuild-workspace.dev @install

test-all:
	jbuilder build --workspace jbuild-workspace.dev @runtest

.PHONY: build test pin repin build-all test-all
