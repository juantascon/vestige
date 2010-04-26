cmake_minimum_required(VERSION 2.6)

include(../../util/cmake/UseLATEX.cmake)

add_latex_document(presentation-short.tex
	INPUTS content.tex reverse.el
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
