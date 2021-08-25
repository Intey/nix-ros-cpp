let pkgs = import (builtins.fetchTarball {
      name = "nixos-21.20";
      url = "https://github.com/NixOS/nixpkgs/archive/refs/tags/21.05.tar.gz";
      sha256 = "1ckzhh24mgz6jd1xhfgx0i9mijk6xjqxwsshnvq789xsavrmsc36";
    }) {};
    ue4_4_27 = pkgs.ue4.override { requireFile = unused_args: pkgs.fetchFromGitHub { 
        owner = "EpicGames";
        repo = "UnrealEngine";
        rev = "4.27.0-release";
        sha256 = "0b43239621fe8d7d536b02be79e17a41036805bf0426ebb98f3ec93d17c2c3e9";
    }; };
in 

with import (builtins.fetchTarball https://github.com/lopsided98/nix-ros-overlay/archive/master.tar.gz) {};

# when we try `with rosPackages` and specify dist in paths, we get error:
# with repl we can find needed packages

with rosPackages.noetic;

mkShell {
  buildInputs = with pkgs; [
    clang_12
    ue4_4_27
    ninja
    gtest
    cmake
    gdb
    (buildEnv { 
      name = "ros";
      paths = [
        rosbash
        roscpp
      ]; 
    })
  ];
}
