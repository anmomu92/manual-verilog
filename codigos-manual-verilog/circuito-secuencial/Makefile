DUT=mef

all: verilator tb
verilator: $(DUT).v
	verilator -Wall --trace -cc $(DUT).v
	make -C obj_dir -f V$(DUT).mk
debug: %.v
	verilator -Wall --trace --public-flat-rw --vpi -cc $(DUT).v
	make -C obj_dir -f V$(DUT).mk
tb: tb_$(DUT).cpp
	g++ -I /usr/share/verilator/include/ -I obj_dir/ /usr/share/verilator/include/verilated.cpp /usr/share/verilator/include/verilated_vcd_c.cpp tb_$(DUT).cpp obj_dir/V$(DUT)__ALL.a -o V$(DUT)
clean:
	rm -r obj_dir V$(DUT) *.vcd
