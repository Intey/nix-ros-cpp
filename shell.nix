with import (builtins.fetchTarball https://github.com/lopsided98/nix-ros-overlay/archive/master.tar.gz) {};

# when we try `with rosPackages` and specify dist in paths, we get error:
# with repl we can find needed packages

with rosPackages.noetic;

mkShell {
  buildInputs = [
    gtest
    cmake
    ninja
    (buildEnv { 
      name = "ros";
      paths = [
        rosbash
        roscpp
      ]; 
    })
  ];
}
