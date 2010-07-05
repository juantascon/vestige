cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(mthesis.tex
  INPUTS
  kuthesis.sty
  cover.tex ack.tex abstract.tex
  introduction.tex relatedworks.tex methodology.tex testcases.tex
  evaluation.tex conclusions.tex
  testcases.erl examples.erl
  
  IMAGE_DIRS
  img/diagrams img/survey img/relworks img/iface
  img/p1/rev img/p1/join img/p1/remall img/p1/compress img/p1/isort
  img/p2/rev img/p2/join img/p2/remall img/p2/compress img/p2/isort
  img/p3/rev img/p3/join img/p3/remall img/p3/compress img/p3/isort
  
  BIBFILES recursion.bib tui.bib
  
  DEFAULT_PDF
  MANGLE_TARGET_NAMES
)
