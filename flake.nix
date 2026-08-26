{
  description = "Temporary QMK firmware development environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "aarch64-darwin";
      pkgs = import nixpkgs { inherit system; };
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = [
          pkgs.pkgsCross.avr.buildPackages.gcc
          pkgs.pkgsCross.avr.buildPackages.binutils
          pkgs.pkgsCross.avr.libc
          pkgs.dfu-programmer
          pkgs.qmk
          pkgs.python3
        ];
      };
    };
}
