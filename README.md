# File Compression Tool (RLE)

This is a C command-line utility to compress and decompress `.txt` files using the Run-Length Encoding (RLE) algorithm.

## 📦 Features
- Compress `.txt` files to `.rle`
- Decompress `.rle` files to `.txt`
- Automatically avoids overwriting files
- Handles large file paths
- Modular, well-structured C code

## 🚀 Build Instructions

### Requirements:
- GCC
- CMake

### Compile:

```bash
mkdir build
cd build
cmake ..
make
```


### 🛠️ Usage
- ./fileCompressor -c <path/to/file.txt>  # Compress
- ./fileCompressor -d <path/to/file.rle>  # Decompress
- ./fileCompressor -h                     # Help

### 📁 Example
- ./fileCompressor -c ../test_files/test.txt
- ./fileCompressor -d ../test_files/test.rle

### FileCompressionTool/
├── src/              # Source files
├── header_files/     # Header files
├── test_files/       # Test inputs/outputs
├── build/            # Build directory (ignored)
├── CMakeLists.txt    # Build config
├── README.md
└── .gitignore

smart-inference-ai-fusion/
├── main.py                      # Ponto de entrada principal para execução dos experiments
├── run.sh                       # Script utilitário para execução rápida
├── datasets/                    # Arquivos CSV utilizados por loaders do tipo CSVDatasetLoader
├── experiments/                 # Experimentos organizados por dataset (ex: iris/, wine/)
│   └── iris/
│       ├── knn_iris.py          # KNN aplicado ao dataset Iris
│       ├── svm_iris.py          # SVM aplicado ao dataset Iris
│       ├── run_all.py           # Executa todos os experimentos do Iris
│       └── ...
├── results/                     # Resultados e logs de inferência (ex: parâmetros perturbados)
├── src/                         # Código-fonte principal do framework
│   ├── core/                    # Classes base para Experiment, Model e Dataset
│   ├── datasets/                # Factory e loaders de datasets (sklearn, csv, etc.)
│   ├── inference/               # Módulo de inferência
│   │   ├── engine/              # Orquestradores de inferência (InferenceEngine, LabelRunner, etc.)
│   │   ├── pipeline/            # Pipeline unificada que aplica todas as inferências
│   │   ├── transformations/
│   │   │   ├── data/            # Técnicas aplicadas aos dados de entrada (X)
│   │   │   ├── label/           # Técnicas aplicadas aos rótulos (y)
│   │   │   └── params/          # Estratégias de perturbação nos parâmetros
│   ├── models/                  # Implementações dos modelos de IA (KNN, SVM, Tree, etc.)
│   ├── utils/                   # Relatórios, enums, tipos e métricas
│   │   └── types.py             # Tipos pydantic e enums como DatasetSourceType, ReportMode
└── requirements.txt             # Lista de dependências do projeto

