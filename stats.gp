stats 'data.txt' using 1 name 'STATS'
segmentname = sprintf( "%s" , "`echo $SEGMENTNAME`" )
filename = sprintf( "%s.pdf" , segmentname )
#set terminal pdfcairo
#set output filename
set title font ",10"
set key font ",10"
set xlabel font ",10"
set ylabel font ",10"
set xtics font ",10"
set ytics font ",10"
set y2tics font ",10"
titletext = sprintf( "%s(%d latencies)" , segmentname , STATS_records/2 )
statsrange = STATS_max - STATS_min
binwidth = statsrange / statsrange
set title titletext
set ytics nomirror
set y2tics nomirror
xlabeltext = sprintf( "std dev %d" , STATS_stddev )
set xlabel xlabeltext
set ylabel "Cumulative distribution %" rotate parallel
set y2label "Frequency" rotate parallel
set xtics rotate
set xrange [STATS_min:STATS_max]
set style line 13 lc rgb 'orange' lt 1 lw 1
set grid xtics ytics front ls 13
set grid mxtics mytics front ls 13
mintext = sprintf( "min %d" , STATS_min )
maxtext = sprintf( "max %d" , STATS_max )
mediantext = sprintf( "med %d" , STATS_median )
set xtics add ( mintext STATS_min , maxtext STATS_max , mediantext STATS_median )
bin(x,width)=width*floor(x/width)
set style fill solid border -1
set boxwidth 0.5*binwidth
plot 'data.txt' using (bin($1,binwidth)):(1.0) smooth freq title 'Histogram' with boxes axes x1y2 , \
     'data.txt' using 1:(1.0) smooth cnormal title "Cumulative distribution" axes x1y1
