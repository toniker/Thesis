current_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

b:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main.tex

3b:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest \
	pdflatex -shell-escape -f -interaction=nonstopmode main && \
	bibtex main && \
	pdflatex -shell-escape -f -interaction=nonstopmode main && \
	pdflatex -shell-escape -f -interaction=nonstopmode main

o:
	open main.pdf

c:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c

biber:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest biber main