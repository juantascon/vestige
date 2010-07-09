cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(isuvr2010.tex
	INPUTS content.tex
	IMAGE_DIRS img/survey img/actions
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
