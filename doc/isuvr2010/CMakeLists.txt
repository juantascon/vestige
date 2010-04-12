cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(isuvr2010.tex
  INPUTS abstract.tex introduction.tex methodology.tex conclusion.tex
  BIBFILES isuvr2010.bib
  IMAGE_DIRS img
  DEFAULT_PDF
  MANGLE_TARGET_NAMES
)
