{
  description = "cunbidun's competitive programming flake";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    devShells.${system}.default =
      pkgs.mkShell
      {
        packages = with pkgs; [
          clang-tools
          zsh
          cowsay
        ];
        shellHook = ''
          export CP_ENV=1
          cowsay "welcome to cunbidun's competitive programming shell"
          echo "starting Competitive Companion server..."
          pkill cpcli_cc; cpcli_cc --project-config project_config.json -o 2>&1 > /dev/null &
          echo "Competitive Companion server started"
          echo -e "\e]2;Competitive Programming\007"
          exec zsh
        '';
      };
  };
}
