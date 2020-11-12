
# uiofpga

The Userspace I/O framework (UIO) is part of the Linux kernel and allows device drivers to be written almost entirely in userspace. UIO is suitable for hardware that does not fit into other kernel subsystems (Like special HW like FPGA) and allowing the programmer to write most of the driver in userspace using all standard application programming tools and libraries. This greatly simplifies the development, maintenance, and distribution of device drivers for this kind of hardware. I did a simple project implemented on Xilinx Zynq that shows a response to IRQ that comes from a periodic time that is implemented on the FPGA part of the Zynq. The PL side (ARM) responds to the IRQ at user space and allows a rapid periodic response to IRQ.  It can view the project [here](https://github.com/yairgd/uiofpga).

[continue reding here](https://yairgd.github.io/2020/02/linux-uio-driver-to-handle-with-irq-source/)

## build kernel
Just define the following vaiable
```bash
export KERNEL_SRC=/path/to/zynq/kernel-source/
```

## build FPGA projct
Using Vivado, you have to import a TCL bock design and map the IOs to pinout.
