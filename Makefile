current_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

build:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -pdf -file-line-error --shell-escape -halt-on-error -interaction=nonstopmode main.tex

open:
	open main.pdf

build-and-open:
	make build
	make open

clean:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c