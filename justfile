set windows-shell := ["powershell.exe", "-c"]

build:
	mkdir -Force build
	clang -Llibs\allocators\build -Ilibs\allocators -o build/length_aware_string.o length_aware_string.c
	clang -Llibs\allocators\build -Ilibs\allocators -c -o build/length_aware_string.dll build/length_aware_string.o