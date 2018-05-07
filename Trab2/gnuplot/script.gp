#!/usr/bin/gnuplot
#
# Plotting the data of file plotting_data1.dat
#
# AUTHOR: Hagen Wierstorf

reset

# color definitions
unset border
set grid
set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5 # --- blue
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1.5 # --- red

unset key

plot 'gnuplot/data.txt' index 0 with linespoints ls 1, \
     ''                   index 1 with linespoints ls 2
