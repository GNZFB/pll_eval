open_project abc2alphaBeta2dq_prj
set_top abc2alphaBeta2dq
add_files ./src/abc2alphaBeta2dq.cpp -cflags "-DDQTRANSF_FLAG_1"
add_files ./src/abc2alphaBeta2dq.h
add_files -tb ./src/tb_abc2alphaBeta2dq.cpp

#Synthesis solution
open_solution "sol_synth"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./abc2alphaBeta2dq_prj/sol_synth/directives.tcl"

#Sysgen solution
open_solution "sol_sysgen"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./abc2alphaBeta2dq_prj/sol_sysgen/directives.tcl"

#csim_design
#csynth_design
#cosim_design -setup -rtl vhdl


close_project