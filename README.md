"# CS-416-P1" 

What is needed to run:
  - A file of size 512MB for timeRead.c

Grade: 95/100

Reasons for deductions:
  - Calling gettimeofday() within loop; causing inaccurate average time

Improvements for next time:
  - Instead of calculating the time each iteration, get the time before
entering loop and then divide by total iterations.
