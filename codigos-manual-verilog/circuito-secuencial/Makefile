DUT=mef

all: verilator tb
verilator: $(DUT).sv
	verilator -Wall --trace -cc $(DUT).sv
	make -C obj_dir -f V$(DUT).mk
debug: %.v
	verilator -Wall --trace -cc $(DUT).v
	make -C obj_dir -f V$(DUT).mk
tb: tb_$(DUT).cpp
	g++ -I /usr/share/verilator/include/ -I obj_dir/ -I /usr/share/verilator/include/vltstd/ /usr/share/verilator/include/verilated.cpp /usr/share/verilator/include/verilated_vcd_c.cpp /usr/share/verilator/include/verilated_dpi.cpp tb_$(DUT).cpp obj_dir/V$(DUT)__ALL.a -o V$(DUT)
clean:
	rm -r obj_dir V$(DUT) *.vcd
