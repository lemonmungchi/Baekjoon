/* ���α׷� ���� tip : �۽���,�۽���,�������ּ� �Է� �� �ּ� ���� �����ڴ� - �Ǵ� . ���� �ؾ��Ѵ�.
						 �ּҸ� �Է��� �� �۽����� �� 5���� ������(MAC)�� ����ϰ� �������� �� 3���� ������(IP)�� ����Ѵ�. */

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <string.h>


#define MAX_SIZE 300

struct L0 {  // ���� 0
	int parrity;
	int saddr[4];
	int daddr[4];
	int length;
	char L0_data[MAX_SIZE]; //data����
};

struct L1 {  // ���� 1
	int saddr[4];
	int daddr[4];
	int length;
	char L1_data[MAX_SIZE]; //data����
};

struct L2 {  // ���� 2
	int saddr[6];
	int daddr[6];
	int length;
	char L2_data[MAX_SIZE]; //data����
};

void L0_send(char* input, int length);
void L1_send(char* input, int length);
void L2_send(char* input, int length);
void L3_send(char* data, int length);
char* L0_receive(int*);
char* L1_receive(int*);
char* L2_receive(int*);
char* L3_receive(int*);
void Parse(char*, int*);
bool getParity(unsigned int n);

static char L0_saddr[40] = { 0 };			//L0 ����ּ�
static char L0_daddr[40] = { 0 };			//L0 �����ּ�
static char L1_saddr[40] = { 0 };			//L1 ����ּ�
static char L1_daddr[40] = { 0 };			//L1 �����ּ�
static char L2_saddr[50] = { 0 };			//L2 ����ּ�
static char L2_daddr[50] = { 0 };			//L2 �����ּ�

static char L0_dest[40] = { 0 };			//L1 ������
static char L1_dest[40] = { 0 };			//L1 ������
static char L2_dest[50] = { 0 };			//L2 ������

int main(void)
{
	char input[MAX_SIZE];
	char output[MAX_SIZE];
	int length;
	int i = 0;
	int c;

	while (1) {								//�޴� ����
		printf("Select menu : \n");
		printf("1. Set L0 address\n");
		printf("2. Set L1 address\n");
		printf("3. Set L2 address\n");
		printf("4. Send Message\n");
		scanf("%d", &c);				

		switch (c) {
		case 1:
			printf("Input my L0 address : \n");
			scanf("%s", L0_saddr);
			printf("Input dest L0 address : \n");
			scanf("%s", L0_daddr);
			break;
		case 2:
			printf("Input my L1 address : \n");
			scanf("%s", L1_saddr);
			printf("Input dest L1 address : \n");
			scanf("%s", L1_daddr);
			break;
		case 3:
			printf("Input my L2 address : \n");
			scanf("%s", L2_saddr);
			printf("Input dest L2 address : \n");
			scanf("%s", L2_daddr);
			break;
		case 4:
			printf("Put the dest L0 address :\n");
			scanf("%s", L0_dest);
			printf("Put the dest L1 address :\n");
			scanf("%s", L1_dest);
			printf("Put the dest L2 address :\n");
			scanf("%s", L2_dest);

			printf("Input String to send : ");
			scanf(" %[^\n]s", input);

			L0_send(input, strlen(input));		//L1 �����Լ� 

			strcpy(output, L0_receive(&length));		//��� L1���� ���� �޼��� �޾ƿ��� 
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

// �и�Ƽ�� �߰��� L0 ���� �Լ�
void L0_send(char* input, int length)
{
	struct L0 data;  // L0 ����ü ����
	char temp[350];
	int size = 0;
	int address[4];
	int i;

	Parse(L0_saddr, address);  // L0 �۽��� �ּ� �Ľ�

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) {  // �۽��� �ּ� ����
		data.saddr[i] = address[i];
	}

	Parse(L0_daddr, address);  // L0 ������ �ּ� �Ľ�

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) {  // ������ �ּ� ����
		data.daddr[i] = address[i];
	}

	data.length = length;  // ������ ���� ����

	memset(data.L0_data, 0x00, MAX_SIZE);  // ������ �޸� �ʱ�ȭ
	strcpy(data.L0_data, input);  // �Է� �����͸� L0_data�� ����

	// �и�Ƽ ��� �� ����� �߰�
	bool isParity = getParity(data.L0_data);
	data.parrity = isParity ? 1 : 0;

	size = sizeof(struct L0) - sizeof(data.L0_data) + length;

	memset(temp, 0x00, 350);  // �ӽ� �޸� �ʱ�ȭ
	memcpy(temp, (void*)&data, size);  // ����ü �����͸� �ӽ� �޸𸮿� ����

	L1_send(temp, size);  // L1 �������� ����
}

void L1_send(char* input, int length)
{
	struct L1 data;			//L1 ����ü
	char temp[350];
	int size = 0;
	int address[4];
	int i;

	Parse(L1_saddr, address);  // L1 �۽��� �ּ� �Ľ� �� address ������ �߰�

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) { // L1 �۽��� �ּ� ����
		data.saddr[i] = address[i];
	}

	Parse(L1_daddr, address); // L1 ������ �ּ� �Ľ� �� address ������ �߰�

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) { //L1 ������ �ּ� ����
		data.daddr[i] = address[i];
	}

	data.length = length;			//�ۼ����� �ּҰ��� ������  ����ü ũ��

	memset(data.L1_data, 0x00, MAX_SIZE);			//�޸� �ִ���̸�ŭ 0��Ʈ�� �ʱ�ȭ
	strcpy(data.L1_data, input);					//�޸𸮿� �Է°� ����

	size = sizeof(struct L1) - sizeof(data.L1_data) + length;			//

	memset(temp, 0x00, 350);						//�޸� �ʱ�ȭ 
	memcpy(temp, (void*)&data, size);				//����ü ������ �޸𸮿� ����

	L2_send(temp, size);					//L2�� ����ü ��������
}

void L2_send(char* input, int length)
{
	struct L2 data;
	char temp[350];
	int size = 0;
	int address[6];
	int i;

	Parse(L2_saddr, address); // L2 �۽��� �ּ� �Ľ� 

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) { //L2 �۽��� �ּ� ����
		data.saddr[i] = address[i];
	}

	Parse(L2_daddr, address); // L2 ������ �ּ� �Ľ�

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) { //L2 ������ �ּ� ����
		data.daddr[i] = address[i];
	}

	data.length = length;

	memset(data.L2_data, 0x00, MAX_SIZE);			//�޸� �ʱ�ȭ
	memcpy(data.L2_data, (void*)input, length);		//�޸𸮿� ����

	size = sizeof(struct L2) - sizeof(data.L2_data) + length;		//�������

	memset(temp, 0x00, 350);				//�޸� �ʱ�ȭ
	memcpy(temp, (void*)&data, size);		//�޸𸮿� ����
	L3_send(temp, size);					//L3���� ����
}

void L3_send(char* data, int length)
{
	FILE* fp;
	char temp[300];

	memset(temp, 0x00, MAX_SIZE);				//�޸� �ʱ�ȭ
	memcpy(temp, (void*)data, length);			//�޸𸮿� ����
	fp = fopen("data.txt", "w");
	for (int i = 0; i < length; i++)
		fputc(temp[i], fp);			//txt ����

	fclose(fp);
}

// �и�Ƽ ������ ���Ե� L0 ���� �Լ�
char* L0_receive(int* length)
{
	struct L0* data;
	int address[4];
	int i;

	data = (struct L0*)L1_receive(length);  // L1���� ������ ����

	if (*length != 0) {
		*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);  // ���� ������ ����
	}

	Parse(L0_dest, address);  // L0 ������ �ּ� �Ľ�

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {  // ������ �ּ� ��ġ Ȯ��
		if (data->daddr[i] != address[i]) {
			printf("L0������ ������ �ּ� ����ġ, �޽��� discard \n");
			data->L0_data[0] = '\0';
			*length = 0;
			return (char*)data->L0_data;
		}
	}

	// �и�Ƽ �˻�
	bool receivedParity = data->parrity;
	bool calculatedParity = getParity(data->L0_data);

	if (receivedParity != calculatedParity) {
		printf("Parrity Check Result : Error, �޼��� discard \n");
		data->L0_data[0] = '\0';
		*length = 0;
		return (char*)data->L0_data;
	}

	return (char*)data->L0_data;
}


char* L1_receive(int* length)
{
	struct L1* data;
	static int r_sequence = 0;
	int address[4];
	int i, j;
	char temp;

	data = (struct L1*)L2_receive(length);			//L2���� ���� ������� ���� 

	if (*length != 0) {
		*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);			//���� �������� ���� �������� 
	}

	Parse(L1_dest, address);				//L1 ���� �ּ� ��������

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {			// L1 ���� �ּ� �˻�
		if (data->daddr[i] != address[i]) {
			printf("L1������ ������ �ּ� ����ġ, �޽��� discard \n");
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

	data = (struct L2*)L3_receive(length);				//L3���� ���� ������� ���� 
	*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);			//���� �������� ���� �������� 

	Parse(L2_dest, address);

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {				// ������ �ּ� �˻�
		if (data->daddr[i] != address[i]) {
			printf("L2������ ������ �ּ� ����ġ, �޽��� discard \n");
			len = (sizeof(struct L1) - MAX_SIZE) / sizeof(int); 
			len = len * 4; // *4�� ���ִ� ����: �޽����� ���۵� �� int���� char������ ���� ��ȯ�Ǿ� ����Ǿ��� ������ ���� L2_data�迭(�޽���)���� ����� ������ 1����Ʈ�� �ƴ� 4����Ʈ�� �����ϰ� �ִ�.
			
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

	while ((ch = fgetc(fp)) != EOF) {		//���� �о����
		data[i] = ch;
		i++;
	}
	data[i] = '\n';
	*length = i;

	return data;
}

//�����ڸ� ���� �ּҰ� int�� ����
void Parse(char* data, int* addr) {
	int i, j = 0, c = 0;
	char temp[30];
	for (i = 0; i < strlen(data); i++) { // �ּҰ����� �ּ� ������ '-' �Ǵ� '.'�� �������� �ּҸ� ��� �Ľ����ش�.
		while (data[i] != '-' && data[i] != '.' && i < strlen(data)) {
			temp[j++] = data[i++];
		}
		temp[j] = '\0';
		j = 0;
		addr[c++] = atoi(temp);			//string -> int 
	}
}

// ���ڿ��� �и�Ƽ�� ����ϴ� �Լ� (L0_data)
bool getParity(const char* data) {
	bool parity = 0;
	for (int i = 0; i < strlen(data); i++) {
		unsigned char byte = data[i];
		// ����Ʈ �� 1�� ������ ���� �и�Ƽ ���
		while (byte) {
			parity = !parity;
			byte &= (byte - 1);  // ���� ������ 1�� ����
		}
	}
	return parity;
}
