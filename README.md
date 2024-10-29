# File/Folder Compressor/Decompressor

## About
This project is a file and folder compressor and decompressor implemented in C using the LZSS algorithm. It allows users to compress multiple files and directories into a single compressed file/folder, reducing storage requirements and simplifying data transfer. The tool also supports decompression, allowing users to retrieve the original files from the compressed format. Designed for efficiency, this tool features a command-line interface for straightforward operation.

### Features
- Compress multiple files and folders into a single compressed file.
- Decompress compressed files back to their original state.
- Command-line interface for easy usage.
- Makefile included for streamlined building.

## About LZSS
LZSS (Lempel-Ziv-Storer-Szymanski) is a lossless data compression algorithm derived from LZ77. It efficiently compresses data by replacing repetitive sequences with shorter codes, minimizing data storage without any loss of information.

### Key Characteristics of LZSS:
- **Lossless Compression**: Allows perfect reconstruction of the original data.
- **Dictionary-based Compression**: Uses a sliding window as a dictionary of previously encountered strings to substitute long sequences with shorter references.
- **Efficiency**: Effective for compressing text and binary files, making it suitable for a variety of applications.

### How LZSS Works
1. **Input Data**: LZSS reads input data and detects repeating sequences.
2. **Sliding Window Dictionary**: It uses a sliding window to maintain previously seen data, helping identify repetitions.
3. **Encoding**: When a sequence is detected, LZSS encodes it as a reference (distance and length) instead of storing it repeatedly.
4. **Output**: The compressed data is saved in an output file, optimizing storage and transfer efficiency.

## Usage
Compress using
```bash
./main -c -i input -o output
```
Decompress using
```bash
./main -d -i input -o output
```
Compare file/folders using
```bash
./main -compare file1 file2 file3 ...
```
### Build the Project
To compile the project, use the following command:
```bash
make
```
