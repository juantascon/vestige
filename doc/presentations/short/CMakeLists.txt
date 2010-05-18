cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(short.tex
	INPUTS content.tex reverse.el
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
