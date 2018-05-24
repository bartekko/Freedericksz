python3 init.py >temps.txt
rm plot.dat
cat temps.txt | parallel --colsep ' ' --verbose ./run.sh >plot.dat



