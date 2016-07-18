# Razer Drivers

**This repository contains the legacy razer drivers source based on the [razer_chroma_drivers](https://github.com/pez2001/razer_chroma_drivers) project. Due to code quality issues a complete rewrite can be found [here](https://github.com/openrazer/razer-drivers)**

This repository holds the source code for the linux kernel drivers to support various Razer devices.
All notable changes to this project will be documented in the **[CHANGELOG.md](CHANGELOG.md)** file.

## Supported Devices

| NAME                                       | TYPE     | DRIVER SUPPORT                             |
|:-------------------------------------------|:---------|:-------------------------------------------|
| Razer Firefly                              | Mousemat | all lighting modes                         |
| Razer Mamba                                | Mouse    | all lighting modes                         |
| Razer Abyssus                              | Mouse    | all modes bar the refresh rate             |
| Razer Blackwidow Classic                   | Keyboard | all lighting modes                         |
| Razer Blackwidow Ultimate 2012             | Keyboard | all lighting modes                         |
| Razer Blackwidow Ultimate 2013             | Keyboard | all lighting modes                         |
| Razer Blackwidow Chroma                    | Keyboard | all lighting modes                         |
| Razer Blackwidow Chroma Tournament Edition | Keyboard | all lighting modes                         |
| Razer Blackwidow Ultimate 2016             | Keyboard | all bar custom lighting                    |
| Razer Blade Stealth                        | Keyboard | all lighting modes                         |
| Razer Blade 14 2016                        | Keyboard | partially all lighting modes - In Progress |


## Installation

### Automatic installation with DKMS

This requires DKMS to be installed.

```
    make DESTDIR=/ install_dkms
```

### Manual installation

This requires recompilation on every kernel update.

```
    make all
    make DESTDIR=/ install
```

## Authors

Special thanks to Tim Theede, the initial creator of the [razer_chroma_drivers project](https://github.com/pez2001/razer_chroma_drivers) on which this project is based on.

A list of all authors contributed to this project can be found in the **[AUTHORS.md](AUTHORS.md)** file.
