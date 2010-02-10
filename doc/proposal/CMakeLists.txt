cmake_minimum_required(VERSION 2.6)

include(../../util/cmake/UseLATEX.cmake)

add_latex_document(proposal.tex
	INPUTS includes.tex abstract.tex current_state.tex interaction_scenarios.tex programming_topics.tex
	DEFAULT_PDF
	MANGLE_TARGET_NAMES
)
