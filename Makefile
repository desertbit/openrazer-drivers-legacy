# The project version
VERSION=1.0.0

# DESTDIR is used to install into a different root directory
DESTDIR?=/

# Specify the kernel directory to use
KERNELDIR?=/lib/modules/$(shell uname -r)/build

# Need the absolute directory do the driver directory to build kernel modules
DRIVERDIR?=$(shell pwd)/src

# Where kernel drivers are going to be installed
MODULEDIR?=/lib/modules/$(shell uname -r)/kernel/drivers/usb/misc

# Where the DKMS files will be installed
DKMSDIR?=/usr/src/razer-drivers-$(VERSION)

# Specify the udev rules directory
UDEVRULESDIR?=/lib/udev/rules.d


# Build all target
all: driver

# Driver compilation
driver:
	@echo "\n::\033[32m Compiling Razer kernel modules\033[0m"
	@echo "========================================"
	make -C $(KERNELDIR) SUBDIRS=$(DRIVERDIR) modules

# Clean target
clean:
	make -C $(KERNELDIR) SUBDIRS=$(DRIVERDIR) clean

# Install kernel modules
install: udev_install
	@echo "\n::\033[34m Installing Razer kernel modules\033[0m"
	@echo "====================================================="
	@install -v -D -m 644 -g root -o root $(DRIVERDIR)/razerkbd.ko $(DESTDIR)/$(MODULEDIR)/razerkbd.ko
	@install -v -D -m 644 -g root -o root $(DRIVERDIR)/razermouse.ko $(DESTDIR)/$(MODULEDIR)/razermouse.ko
	@install -v -D -m 644 -g root -o root $(DRIVERDIR)/razerfirefly.ko $(DESTDIR)/$(MODULEDIR)/razerfirefly.ko

# Remove kernel modules
uninstall: udev_uninstall
	@echo "\n::\033[34m Uninstalling Razer kernel modules\033[0m"
	@echo "====================================================="
	@rm -f $(DESTDIR)/$(MODULEDIR)/razerkbd.ko
	@rm -f $(DESTDIR)/$(MODULEDIR)/razermouse.ko
	@rm -f $(DESTDIR)/$(MODULEDIR)/razerfirefly.ko

# DKMS
install_dkms: udev_install
	@echo "\n::\033[34m Installing DKMS files\033[0m"
	@echo "====================================================="
	install -m 644 -v -D Makefile $(DESTDIR)/$(DKMSDIR)/Makefile
	install -m 644 -v -D dkms/dkms.conf $(DESTDIR)/$(DKMSDIR)/dkms.conf
	install -m 755 -v -d src $(DESTDIR)/$(DKMSDIR)/src
	install -m 644 -v -D src/Makefile $(DESTDIR)/$(DKMSDIR)/src/Makefile
	install -m 644 -v src/*.c $(DESTDIR)/$(DKMSDIR)/src/
	install -m 644 -v src/*.h $(DESTDIR)/$(DKMSDIR)/src/
	rm -fv $(DESTDIR)/$(DKMSDIR)/src/*.mod.c
	sed -i -e 's/VERSION_SET_BY_MAKEFILE/$(VERSION)/g' $(DESTDIR)/$(DKMSDIR)/dkms.conf

uninstall_dkms: udev_uninstall
	@echo "\n::\033[34m Uninstalling DKMS files\033[0m"
	@echo "====================================================="
	rm -rfv $(DESTDIR)/$(DKMSDIR)

# UDEV
udev_install:
	@echo "\n::\033[34m Installing Razer udev rules\033[0m"
	@echo "====================================================="
	install -m 644 -v -D udev/99-razer.rules $(DESTDIR)/$(UDEVRULESDIR)/99-razer.rules

udev_uninstall:
	@echo "\n::\033[34m Uninstalling Razer udev rules\033[0m"
	@echo "====================================================="
	rm -fv $(DESTDIR)/$(UDEVRULESDIR)/99-razer.rules
