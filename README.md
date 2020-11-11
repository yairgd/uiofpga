
# uiofpga

The Userspace I/O framework (UIO) is part of the linux kernel and allows device drivers to be written almost entirely in userspace. UIO is suitable for hardware that does not fit into other kernel subsystems (Like special HW like FPGA) and allowing the programmer to write most of the driver in userspace using all standard application programming tools and libraries. This greatly simplifies development, maintenance, and distribution of device drivers for this kind of hardware. I did a simple project implemenetd on Xilinx Zynq that shows response to IRQ that come from perioic time that impelented on the FPGA part of the zynq. The PL side (ARM) responsed to the IRQ at user space ans allows versy quick periodic response to IRQ.

[continue reding here](https://yairgd.github.io/2020/02/linux-uio-driver-to-handle-with-irq-source/)

## build kernel
Just define the following vaiable
```bash
export KERNEL_SRC=/path/to/zynq/kernel-source/
```
