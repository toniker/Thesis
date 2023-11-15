current_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

b:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -pdf -file-line-error --shell-escape -halt-on-error -interaction=nonstopmode main.tex

o:
	open main.pdf

bo:
	make build
	make open

c:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c