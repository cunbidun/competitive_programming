{
  description = "cunbidun's competitive programming flake";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs =
    { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          clang-tools
          gcc # wrapper provides cc/c++ commands
          gcc-unwrapped # real toolchain for headers (bits/stdc++.h)
          zsh
          cowsay
        ];
        shellHook = ''
          export CP_ENV=1

          # Make libstdc++ headers visible to clang/clangd (fixes missing bits/stdc++.h)
          # Only keep the two paths that provide the C++ standard library headers
          base_inc="${pkgs.gcc-unwrapped}/include/c++/${pkgs.gcc-unwrapped.version}:${pkgs.gcc-unwrapped}/include/c++/${pkgs.gcc-unwrapped.version}/${pkgs.stdenv.hostPlatform.config}"

          if [ -n "$CPLUS_INCLUDE_PATH" ]; then
            export CPLUS_INCLUDE_PATH="$base_inc:$CPLUS_INCLUDE_PATH"
          else
            export CPLUS_INCLUDE_PATH="$base_inc"
          fi

          cowsay "welcome to cunbidun's competitive programming shell"
          echo "starting Competitive Companion server..."
          pkill cpcli_cc; cpcli_cc --project-config project_config.json -o 2>&1 > /dev/null &
          echo "Competitive Companion server started"
          echo -e "\e]2;Competitive Programming\007"
          # Only drop into zsh for interactive shells; allow nix develop -c to run commands
          if [ -n "$PS1" ] && [ -z "$NIX_SKIP_EXEC_ZSH" ]; then
            exec zsh
          fi
        '';
      };
    };
}
