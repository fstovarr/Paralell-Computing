# Blur effect

En la presente carpeta encontrará diferentes implementaciones para aplicarle el filtro de blur effect a una imagen en distintos formatos, basados en un Kernel Gaussiano.

El directorio presenta la siguiente estructura:

```bash
BlurrEfectPOSIX
│   README.md
│   ejecutar_todo.sh # Script para ejecutar test_bench
|   test-bench.sh # Script para ejecutar test_bench
|   plot.py # Script de python para realizar plots
|   plot_seq.py # Script de python para realizar plots de la version secuencial
|   Analysis.ipynb # Notebook de python demostrativo con del funcionamiento programa
│
└───BlurEffectSequential
└───BlurEffectBlock
└───BlurEffectBlockCyclic
└───BlurEffectPool
└───img
└───out
```

En cada una de las carpetas con nombre BlurEffect\*, se encuentra la solución del problema siguiendo un paradigma distinto para la distribución del trabajo en hilos (secuencial, bloques, bloques-ciclos, thread-pool). A su vez, cada una de estas carpetas tiene la siguiente estructura:

```bash
BlurrEfect*
│   README.md
│   Makefile
|   analysis4.txt # análisis realizado con la herramienta GProc
└───bin # Directorio con el ejecutable
└───lib # Directorio con las librerías usadas
└───src # Directorio con el código fuente del programa
```

## Build and run

Each folder has its own Makefile, where there are the necessary steps to make and build the executable. That steps are the following:

```bash
make # Build executable
./bin/blur-effect img/favicon.png out/testing.png 3 8 # Execute the program
```

### Make options

```bash
make clean # Delete objects folder
make fullclean # Delete objects, bin and other non-esencial folders
```

## Run test bench

Perform the test bench for all folders (Sequential, Block, BlockCyclic, Pool)

```
./ejecutar_todo.sh
```

To perfom a test bench for single paradigm, run

```bash
# Run Sequential
./test-bench-sequential.sh $IMG_PATH Results/sequential_data.out

# Run Block
./test-bench.sh BlurEffectBlock/bin/blur-effect $IMG_PATH BlurEffectBlock/out Results/block.out

# Run Block-Cyclic
./test-bench.sh BlurEffectBlockCyclic/bin/blur-effect $IMG_PATH BlurEffectBlockCyclic/out Results/cyclic_data.out

# Runs Pool
./test-bench.sh BlurEffectPool/bin/blur-effect $IMG_PATH BlurEffectPool/out Results/pool_data.out
```
