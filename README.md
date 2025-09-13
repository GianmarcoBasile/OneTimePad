# OneTimePad

A simple C program to encrypt and decrypt files using the One-Time Pad cipher.

## Features

- **Encryption**: Generates a random key for each byte of the original file and produces an encrypted file.
- **Decryption**: Uses the key file to decrypt the encrypted file and restore the original file.

## Usage

### Compilation

```sh
gcc otp.c -o otp.exe
```

### Encryption

```sh
./otp.exe encrypt <file-to-encrypt>
```

- Output: `encrypted_file.out` (encrypted file), `key.out` (random key)

### Decryption

```sh
./otp.exe decrypt <encrypted-file> <key-file>
```

- Output: `decrypted_file.out` (decrypted file)

## Example

```sh
./otp.exe encrypt test.txt
./otp.exe decrypt encrypted_file.out key.out
```

## Notes

- The security of the OTP cipher depends on the randomness and uniqueness of the key.
- The key must be at least as long as the file to be encrypted and must never be reused.

## Author

Gianmarco Basile
