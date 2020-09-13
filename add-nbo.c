#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
	
	if (argc == 3){
		FILE *fp;
		FILE *fp2;
		uint32_t n[10];
		uint32_t n2[10];

		fp = fopen( argv[1], "rb");
		fp2 = fopen( argv[2], "rb");

		/*if ((fp2 = fopen(argv[2], "rt")) == NULL) {
			printf("file2 err\n");
			return 0;
		}*/

		fread(n, sizeof(uint32_t), 1, fp);
		fread(n2, sizeof(uint32_t), 1, fp2);

		n[0] = ntohl(n[0]);
		n2[0] = ntohl(n2[0]);

		printf("%d(%x) +  %d(%x) = %d(%x)\n", n[0], n[0], n2[0], n2[0], n[0]+n2[0], n[0]+n2[0]);
			
		fclose(fp);
		fclose(fp2);
	}
	


	return 0;
}
