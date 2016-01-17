#!/usr/bin/gnuplot

# set terminal and output, use input filename as base for new filename
set terminal pngcairo size 1920,1080 enhanced font 'Verdana,30'

# set a grid for the graph
set grid

# set labels
set xlabel "q_1"
set ylabel "q_2"

# set ranges
set xr [-2:1]
set yr [-1:1]

set output "q12_dt_0.05.png"
plot "data_dt_0.05" u 3:4 w l lw 2 t "dt 0.05"

set output "q12_dt_0.0005.png"
plot "data_dt_0.0005" u 3:4 w l lw 2 t "dt 0.0005"

set xr [0:62.83]
set yr [-0.58:-0.36]

set xlabel "Time t"
set ylabel "H"

set output "H_dt_0.05.png"
plot "data_dt_0.05" u 1:2 w l lw 2 t "dt 0.05"

set yr[-0.501:-0.499]
set output "H_dt_0.0005.png"
plot "data_dt_0.0005" u 1:2 w l lw 2 t "dt 0.0005"