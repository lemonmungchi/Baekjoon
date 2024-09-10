/* 프로그램 설명서 tip : 송신자,송신자,목적지주소 입력 시 주소 형식 구분자는 - 또는 . 으로 해야한다.
						 주소를 입력할 때 송신측은 꼭 5번의 구분자를 써야하고 수신측은 꼭 3번의 구분자를 써야한다. */

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 300

struct L1 {  // 계층 1
	int saddr[4];
	int daddr[4];
	int length;
	char L1_data[MAX_SIZE]; //data영역
};

struct L2 {  // 계층 2
	int saddr[6];
	int daddr[6];
	int length;
	char L2_data[MAX_SIZE]; //data영역
};

void L1_send(char* input, int length);
void L2_send(char* input, int length);
void L3_send(char* data, int length);
char* L1_receive(int*);
char* L2_receive(int*);
char* L3_receive(int*);
void Parse(char*, int*);

static char L1_saddr[40] = { 0 };
static char L1_daddr[40] = { 0 };
static char L2_saddr[50] = { 0 };
static char L2_daddr[50] = { 0 };
static char L1_dest[40] = { 0 };
static char L2_dest[50] = { 0 };

int main(void)
{
	char input[MAX_SIZE];
	char output[MAX_SIZE];
	int length;
	int i = 0;
	int c;

	while (1) {
		printf("Select menu : \n");
		printf("1. Set L1 address\n");
		printf("2. Set L2 address\n");
		printf("3. Send Message\n");
		scanf("%d", &c);

		switch (c) {
		case 1:
			printf("Input my L1 address : \n");
			scanf("%s", L1_saddr);
			printf("Input dest L1 address : \n");
			scanf("%s", L1_daddr);
			break;
		case 2:
			printf("Input my L2 address : \n");
			scanf("%s", L2_saddr);
			printf("Input dest L2 address : \n");
			scanf("%s", L2_daddr);
			break;
		case 3:
			printf("Put the dest L1 address :\n");
			scanf("%s", L1_dest);
			printf("Put the dest L2 address :\n");
			scanf("%s", L2_dest);

			printf("Input String to send : ");
			scanf(" %[^\n]s", input);

			L1_send(input, strlen(input));

			strcpy(output, L1_receive(&length));
			output[length] = '\0';

			printf("\nReceived message : ");
			puts(output);
			printf("\n");
			break;
		default:
			printf("input value is incorrect ! \n");
			break;
		}
	}
}

void L1_send(char* input, int length)
{
	struct L1 data;
	char temp[350];
	int size = 0;
	int address[4];
	int i;

	Parse(L1_saddr, address);  // L1 송신자 주소 파싱

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) { // L1 송신자 주소 저장
		data.saddr[i] = address[i];
	}

	Parse(L1_daddr, address); // L1 수신자 주소 파싱

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) { //L1 수신자 주소 저장
		data.daddr[i] = address[i];
	}

	data.length = length;

	memset(data.L1_data, 0x00, MAX_SIZE);
	strcpy(data.L1_data, input);

	size = sizeof(struct L1) - sizeof(data.L1_data) + length;

	memset(temp, 0x00, 350);
	memcpy(temp, (void*)&data, size);

	L2_send(temp, size);
}

void L2_send(char* input, int length)
{
	struct L2 data;
	char temp[350];
	int size = 0;
	int address[6];
	int i;

	Parse(L2_saddr, address); // L2 송신자 주소 파싱 

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) { //L2 송신자 주소 저장
		data.saddr[i] = address[i];
	}

	Parse(L2_daddr, address); // L2 수신자 주소 파싱

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) { //L2 수신자 주소 저장
		data.daddr[i] = address[i];
	}

	data.length = length;

	memset(data.L2_data, 0x00, MAX_SIZE);
	memcpy(data.L2_data, (void*)input, length);

	size = sizeof(struct L2) - sizeof(data.L2_data) + length;

	memset(temp, 0x00, 350);
	memcpy(temp, (void*)&data, size);
	L3_send(temp, size);
}

void L3_send(char* data, int length)
{
	FILE* fp;
	char temp[300];

	memset(temp, 0x00, MAX_SIZE);
	memcpy(temp, (void*)data, length);
	fp = fopen("data.txt", "w");
	for (int i = 0; i < length; i++)
		fputc(temp[i], fp);

	fclose(fp);
}

char* L1_receive(int* length)
{
	struct L1* data;
	static int r_sequence = 0;
	int address[4];
	int i, j;
	char temp;

	data = (struct L1*)L2_receive(length);

	if (*length != 0) {
		*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);
	}

	Parse(L1_dest, address);

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {
		if (data->daddr[i] != address[i]) {
			printf("L1계층의 목적지 주소 불일치, 메시지 discard \n");
			data->L1_data[0] = '\0';
			*length = 0;
			return (char*)data->L1_data;
		}
	}

	return (char*)data->L1_data;
}

char* L2_receive(int* length)
{
	struct L2* data;
	int i, j, len;
	int address[6];
	char temp[MAX_SIZE];

	data = (struct L2*)L3_receive(length);
	*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);

	Parse(L2_dest, address);

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) { 
		if (data->daddr[i] != address[i]) {
			printf("L2계층의 목적지 주소 불일치, 메시지 discard \n");
			len = (sizeof(struct L1) - MAX_SIZE) / sizeof(int); 
			len = len * 4; // *4를 해주는 이유: 메시지가 전송될 때 int형이 char형으로 강제 변환되어 저장되었기 때문에 실제 L2_data배열(메시지)에는 헤더의 내용이 1바이트가 아닌 4바이트씩 차지하고 있다.
			
			for (j = len; data->L2_data[j] != '\0'; j++) {
				data->L2_data[j] = '\0';
			}
			*length = 0;
			return (char*)data->L2_data;
		}
	}

	return (char*)data->L2_data;
}

char* L3_receive(int* length)
{
	static char data[MAX_SIZE];
	char ch;
	int i = 0;
	FILE* fp;

	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("Cannot open\n");
		exit(1);
	}

	while ((ch = fgetc(fp)) != EOF) {
		data[i] = ch;
		i++;
	}
	data[i] = '\n';
	*length = i;

	return data;
}

void Parse(char* data, int* addr) {
	int i, j = 0, c = 0;
	char temp[30];
	for (i = 0; i < strlen(data); i++) { // 주소값에서 주소 구분자 '-' 또는 '.'을 기준으로 주소를 끊어서 파싱해준다.
		while (data[i] != '-' && data[i] != '.' && i < strlen(data)) {
			temp[j++] = data[i++];
		}
		temp[j] = '\0';
		j = 0;
		addr[c++] = atoi(temp);
	}
}
