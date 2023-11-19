current_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

b:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main.tex

o:
	open main.pdf

c:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c