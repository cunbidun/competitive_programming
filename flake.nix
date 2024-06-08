{
  description = "cunbidun's competitive programming flake";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      # Define the system we are targeting
      system = "x86_64-linux";
    in
    {
      # Define a development shell
      devShells.${system}.default = nixpkgs.lib.mkShell {
        buildInputs = [
          # Specify the cowsay package using the hash notation
          nixpkgs.legacyPackages.${system}.cowsay
          # You can add more packages here, e.g., git, vim, etc.
          # nixpkgs.legacyPackages.${system}.git
          # nixpkgs.legacyPackages.${system}.vim
        ];

        # Optionally, set environment variables or configure other settings
        shellHook = ''
          cowsay "hello"
        '';
      };
    };
}
