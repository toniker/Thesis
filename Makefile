current_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

b:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c
	rm main.git1.tmp
	rm main.git2.tmp
	rm main.run.xml
	rm main.pdf
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest pdflatex -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest biber main
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest pdflatex -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest pdflatex -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main

o:
	open main.pdf

c:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest latexmk -c

biber:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest biber main

pdflatex:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest pdflatex -pdf -file-line-error --shell-escape -f -interaction=nonstopmode main

checkcites:
	docker run --rm -it -v $(current_dir):/src -w /src zydou/texlive:latest checkcites --unused main.aux