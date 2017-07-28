open_project phase_generator_prj
set_top phase_generator
add_files ./src/phase_generator.cpp
add_files ./src/phase_generator.h
add_files -tb ./src/tb_phase_generator.cpp

#Synthesis solution
open_solution "sol_synth"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./phase_generator_prj/sol_synth/directives.tcl"

#Sysgen solution
open_solution "sol_sysgen"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
config_rtl -encoding onehot -reset control -reset_level low
source "./phase_generator_prj/sol_sysgen/directives.tcl"

#csim_design
#csynth_design
#cosim_design -setup -rtl vhdl


close_project