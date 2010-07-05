#! /bin/bash

for dia in ./*.dia
do
	dia -e $dia.png $dia
	convert $dia.png $dia.pdf
done
