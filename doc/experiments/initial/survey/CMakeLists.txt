cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(survey1.tex
  INPUTS eqexam.sty
  DEFAULT_PDF
  MANGLE_TARGET_NAMES
)
