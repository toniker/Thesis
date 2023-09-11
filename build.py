import os

cwd = os.getcwd()

os.system(f"pdflatex -shell-escape -halt-on-error main.tex")

extra_files = [
    "acronyms.aux",
    "acronyms.fdb_latexmk",
    "acronyms.fls",
    "acronyms.log",
    "main.aux",
    "main.bbl",
    "main.bcf",
    "main.blg",
    "main.fdb_latexmk",
    "main.fls",
    "main.git1.tmp",
    "main.git2.tmp",
    "main.idx",
    "main.ilg",
    "main.ind",
    "main.lof",
    "main.log",
    "main.lot",
    "main.out",
    "main.run.xml",
    "main.toc",
]

for file in extra_files:
    try:
        os.remove(os.path.join(cwd, file))
    except FileNotFoundError:
        pass
