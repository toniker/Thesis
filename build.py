import os

cwd = os.getcwd()

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

os.system(f"pdflatex -shell-escape -f -interaction=nonstopmode main")
os.system(f"bibtex main")
os.system(f"pdflatex -shell-escape -f -interaction=nonstopmode main")
os.system(f"pdflatex -shell-escape -f -interaction=nonstopmode main")

for file in extra_files:
    try:
        os.remove(os.path.join(cwd, file))
    except FileNotFoundError:
        pass