#!/bin/zsh

# create_macos_package.zsh
#
# Script to create a macOS Installer Package
# for the Bacon Programming Language
#
# Written by AIR, BinaryMagic.net (Armando I. Rivera)


# Check if script is running under macOS, abort if not
[[ $(uname) != "Darwin" ]] && echo "This script only works on macOS." && exit 1

# Current Directory Name, for Name and version of package
CUR_DIR="$(basename $PWD)"

# Split the Directory name into an Array
SPLIT=("${(s:-:)CUR_DIR}")

# NAME OF PACKAGE
NAME=$SPLIT[1]

# VERSION
VERSION=$SPLIT[2]

# Temporary Directory
PKG_SRC_ROOT="$PWD/pkgsrc"

# Package Identifier
IDENTIFIER="org.basic-converter.Bacon.$VERSION"

# Create Temporary Directory Tree, and final package folder
mkdir -p $PKG_SRC_ROOT/usr/local/{bin,lib,share/pixmaps,man/man1}
mkdir -p "$PWD/Bacon-MACOS"

# Copy the files to be installed to Temporary Directory
cp bacon.sh build/bacon $PKG_SRC_ROOT/usr/local/bin
cp bacon.1 $PKG_SRC_ROOT/usr/local/man/man1
cp icons/*.png $PKG_SRC_ROOT/usr/local/share/pixmaps


# Build the Installer Package
/usr/bin/pkgbuild \
 --root "$PKG_SRC_ROOT/" \
 --install-location "/" \
 --identifier "$IDENTIFIER" \
 --version "$VERSION" \
 "$PWD/Bacon-MACOS/$NAME-$VERSION.pkg"

# Remove the Temporary Directory
if [[ -d $PKG_SRC_ROOT ]]; then
 rm -r $PKG_SRC_ROOT
fi
