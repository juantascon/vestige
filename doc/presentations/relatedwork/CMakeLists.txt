cmake_minimum_required(VERSION 2.6)

include(UseLATEX)

add_latex_document(relatedwork.tex
	INPUTS content.tex
	IMAGE_DIRS img
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
