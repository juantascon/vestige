#! /bin/bash

for f in ./orig/*.png
do
	convert -scale 50% $f ./$(basename $f)
done
