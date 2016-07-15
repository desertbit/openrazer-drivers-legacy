# Razer Drivers

This repository holds the source code for the linux kernel drivers to support various Razer Chroma devices.
All notable changes to this project will be documented in the [CHANGELOG.md](CHANGELOG.md) file.


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
