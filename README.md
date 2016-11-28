# mmap_sorting

_MMAP SORT_ (test file sort.txt)

_Flat profile:_

Each sample counts as 0.01 seconds.

 %time | cumulative seconds | self seconds | calls    | self s/call | total s/call | name               
-------|--------------------|--------------|----------|-------------|--------------|--------------------
 45.62 |               7.33 |         7.33 |18673875 |        0.00 |         0.00 | comparator         
 23.01 |              11.04 |         3.70 |   999999 |        0.00 |         0.00 | merge              
 18.78 |              14.05 |         3.02 |      N/A |         N/A |          N/A | main               
  6.03 |              15.03 |         0.97 |        1 |        0.97 |        12.01 | merge_sort_recurse 
  5.81 |              15.96 |         0.94 |      N/A |         N/A |          N/A | frame_dummy        
  0.75 |              16.08 |         0.12 |        1 |        0.12 |        12.12 | merge_sort         

_Call graph:_

granularity: each sample hit covers 2 byte(s) for 0.06% of 16.08 seconds
  
  
   index %| time     |     self        |  children       |       called    |       name
   ---   |-----     |-------          |-----------      |------------     |  -------- 
         |          |                 |                  |                 |    <spontaneous>
[1]      |    94.2   |     3.02       |  12.12           |                 |        main [1]
         |           |     0.12       |    12.01         |        1/1      |    merge_sort  [2]
         |           |                |                  |                 |
         |           |      0.12      |12.01             | 1/1             |      main [1]
[2]      |  75.4     |  0.12          | 12.01            |      1          |  merge_sort [2]
         |           |      0.97      | 11.04            |     1/1         |    merge_sort_recurse [3]              |
        |            |                |                  |                 |    
        |            |                |                  |    1999998      |    merge_sort_recurse [3]   
        |            |   0.97         |  11.04           |  1/1            | merge_sort [2]
 [3]    |  74.7      |   0.97         |  11.04           |    1+1999998    |         merge_sort_recurse [3]
        |            |0.00            | 0.97             |   999999/999999 |   merge [4]
        |            | 0.11           |  3.70            |    1999998      |       mergesort_recurse [3]   
       |         |                    |                  |                 | 
       |         |      3.70          | 7.33             |   999999/999999 |       mergesort_recurse [3]
[4]     |   68.6     |  3.70          | 7.88          |    999999       |     merge [4]
       |             |    7.33        |    0.00        | 18673875/18673875 | comparator [5]
       |             |                |                |                   |  
        |        |  7.33      | 0.00  | 18673875/18673875               |   merge [4] 
[5]     |  45.6     | 7.33    |0.00   |18673875 |    comparator [5]
          |     |         |     |                  |     
       |         |                  |                |                  |     <spontaneous> 
[6]    | 5.8   | 0.94 |   0.00|              |   frame_dummy [6]
      
   _Index by function name:_

   [5] comparator              [1] main                    [2] merge_sort
   [6] frame_dummy             [4] merge                   [3] merge_sort_recurse
   
   
   _Valgrind:_

==4658== 
==4658== HEAP SUMMARY:
==4658==     in use at exit: 0 bytes in 0 blocks
==4658==   total heap usage: 3 allocs, 3 frees, 4,001,024 bytes allocated
==4658== 
==4658== All heap blocks were freed -- no leaks are possible
==4658== 
==4658== For counts of detected and suppressed errors, rerun with: -v
==4658== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


