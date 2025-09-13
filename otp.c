#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE *original_file, FILE *encrypted_file, FILE *key_file)
{
	char c, enc;
	int key;

	while((c = fgetc(original_file)) != EOF)
	{
		key = rand();
		printf("%d\n", key);
		enc = c ^ key;
		fputc(enc, encrypted_file);
		fputc(key, key_file);
	}
}

void decrypt(FILE *encrypted_file, FILE *decrypted_file, FILE *key_file)
{
	char c, dec;
	int key;

	while((c = fgetc(encrypted_file)) != EOF && (key = fgetc(key_file)) != EOF)
	{
		dec = c^key;
		fputc(dec, decrypted_file);
	}
}

int main(int argc, char **argv) 
{
	if(argc < 3)
	{
		fprintf(stderr, "Syntax error! Usage: %s encrypt [decrypt) <file-to-encrypt> [<file-to_decrypt> <key_file>]\n", argv[0]);
		return -1;
	}

	if(strcmp(argv[1], "encrypt") == 0) 
	{
		FILE *original_file = fopen(argv[2], "r");
		FILE *encrypted_file = fopen("encrypted_file.out", "w");
		FILE *key_file = fopen("key.out", "w");

		encrypt(original_file, encrypted_file, key_file);

		fclose(original_file);
		fclose(encrypted_file);
		fclose(key_file);
		
		return 0;
	} else if(strcmp(argv[1], "decrypt") == 0) 
	{
		if(argc == 4)
		{
			FILE *encrypted_file = fopen(argv[2], "r");
			FILE *key_file = fopen(argv[3], "r");
			FILE *decrypted_file = fopen("decrypted_file.out", "w");
			
			decrypt(encrypted_file, decrypted_file, key_file);
			
			fclose(encrypted_file);
			fclose(key_file);
			fclose(decrypted_file);
			
			return 0;
		}
	} else 
	{
		fprintf(stderr, "Syntax error! Usage: %s encrypt [decrypt) <file-to-encrypt> [<file-to_decrypt> <key_file>]\n", argv[0]);
		return -1;
	}
}
