#! /bin/bash

for f in ./orig/*.png
do
	convert -scale 19% $f ./$(basename $f)
done
