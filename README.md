
# uiofpga

The Userspace I/O framework (UIO) is part of the Linux kernel and allows device drivers to be written almost entirely in userspace. UIO driver is suitable for hardware that does not fit into other kernel subsystems (Like special HW like FPGA) and allows the programmer to write most of the driver in userspace using all standard application programming tools libraries. It can also dramatically simplify the development, maintenance, and distribution of device drivers for this kind of hardware. I implemented a simple project on Xilinx Zynq that shows the IRQ response for a periodic timer implemented on the PL (FPGA) side of the Zynq. The PS side (ARM) responds to the IRQ at user space and allows a rapid IRQ response.

[continue reding here](https://yairgd.github.io/2020/02/linux-uio-driver-to-handle-with-irq-source/)

## build kernel
Just define the following vaiable
```bash
export KERNEL_SRC=/path/to/zynq/kernel-source/
```

## build FPGA projct
Using Vivado, you have to import a TCL bock design and map the IOs to pinout.
