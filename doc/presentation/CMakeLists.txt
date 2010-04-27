cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(presentation.tex
	INPUTS content.tex
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
