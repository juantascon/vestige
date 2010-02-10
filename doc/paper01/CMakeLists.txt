cmake_minimum_required(VERSION 2.6)

include(../../util/cmake/UseLATEX.cmake)

add_latex_document(paper01.tex
	INPUTS abstract.tex
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)

