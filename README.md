# mmap_sorting

*MMAP SORT* (test file sort.txt)
Flat profile:

Each sample counts as 0.01 seconds.
 %time | cumulative seconds | self seconds | calls    | self s/call | total s/call | name               
-------|--------------------|--------------|----------|-------------|--------------|--------------------
 45.62 |               7.33 |         7.33 | 18673875 |        0.00 |         0.00 | comparator         
 23.01 |              11.04 |         3.70 |   999999 |        0.00 |         0.00 | merge              
 18.78 |              14.05 |         3.02 |      N/A |         N/A |          N/A | main               
  6.03 |              15.03 |         0.97 |        1 |        0.97 |        12.01 | merge_sort_recurse 
  5.81 |              15.96 |         0.94 |      N/A |         N/A |          N/A | frame_dummy        
  0.75 |              16.08 |         0.12 |        1 |        0.12 |        12.12 | merge_sort         

Call graph:



