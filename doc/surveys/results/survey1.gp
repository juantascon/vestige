set title "Answers of survey for experiment 1"

set terminal postscript enhanced color "Helvetica" 11
set border 3
set key out

set style data histogram
set style histogram clustered gap 5
set style fill solid border -1

set xlabel "Questions"
set xtics rotate by -60 scale 0
#set xrange [-1:14]

set ylabel "Anwsers"
set ytics ( "Strongly Disagree" -2, "Disagree" -1, "Neutral" 0, "Agree" 1, "Strongly Agree" 2 )
set yrange [-1.3:2.3]
set grid y

plot 'survey.dat' using 2:xtic(1) title columnheader(2), \
     '' using 3 title columnheader(3), \
     '' using 4 title columnheader(4), \
     '' using 5 title columnheader(5), \
     '' using 6 title columnheader(6), \
     '' using 7 title columnheader(7), \
     '' using 8 title columnheader(8), \
     '' using 9 title columnheader(9) with points lt 9 pt 6
