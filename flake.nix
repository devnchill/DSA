{
  description = "Dev env for dsa problems.Languages present(g++ for c++,tsx for typescript)";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
	let 
		system = "x86_64-linux";
		pkgs = nixpkgs.legacyPackages.${system};
	in
	{
		devShells.x86_64-linux.default=pkgs.mkShell{
			nativeBuildInputs = with  pkgs;[
				gcc
				tsx
			];
		};
	};
}
