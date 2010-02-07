cmake_minimum_required(VERSION 2.6)

include(UseLATEX.cmake)
add_latex_document(main.tex INPUTS header.tex content.tex BIBFILES master.bib DEFAULT_PDF)

