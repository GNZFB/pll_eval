open_project pll_int_prj
set_top pll_int
add_files ./src/pll_int.cpp
add_files ./src/pll_int.h
add_files -tb ./src/tb_pll_int.cpp

#Synthesis solution
open_solution "sol_synth"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./pll_int_prj/sol_synth/directives.tcl"

#Sysgen solution
open_solution "sol_sysgen"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./pll_int_prj/sol_sysgen/directives.tcl"

#csim_design
#csynth_design
#cosim_design -setup -rtl vhdl


close_project