Testing Notes: All tests run from the MiniProject3_Higgins directory with 1 iteration.

Test 1: Small Matrix (manual verify)
Input is a 4x5 matrix with base values around 120-140 and spike noise values of 0 and 255.
After mean filter, spike values should be averaged out and blend closer to surrounding pixels.
Succesful!

Test 2: Salt and Pepper Noise
Input has random 0 and 255 values scattered across a uniform background.
Mean filter smoothed the extreme values toward surrounding pixel values, output looks more uniform.
Succesful!

Test 3: Border/Edge Test
Input is a 3x3 matrix with 255 on all edges and 10 in the center.
Border pixels were copied unchanged, only the interior pixel was filtered and averaged.
Succesful!