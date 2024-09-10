/* 프로그램 설명서 tip : 송신자,송신자,목적지주소 입력 시 주소 형식 구분자는 - 또는 . 으로 해야한다.
						 주소를 입력할 때 송신측은 꼭 5번의 구분자(MAC)를 써야하고 수신측은 꼭 3번의 구분자(IP)를 써야한다. */

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <string.h>


#define MAX_SIZE 300

struct L0 {  // 계층 0
	int parrity;
	int saddr[4];
	int daddr[4];
	int length;
	char L0_data[MAX_SIZE]; //data영역
};

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

static char L0_saddr[40] = { 0 };			//L0 출발주소
static char L0_daddr[40] = { 0 };			//L0 도착주소
static char L1_saddr[40] = { 0 };			//L1 출발주소
static char L1_daddr[40] = { 0 };			//L1 도착주소
static char L2_saddr[50] = { 0 };			//L2 출발주소
static char L2_daddr[50] = { 0 };			//L2 도착주소

static char L0_dest[40] = { 0 };			//L1 도착지
static char L1_dest[40] = { 0 };			//L1 도착지
static char L2_dest[50] = { 0 };			//L2 도착지

int main(void)
{
	char input[MAX_SIZE];
	char output[MAX_SIZE];
	int length;
	int i = 0;
	int c;

	while (1) {								//메뉴 선택
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

			L0_send(input, strlen(input));		//L1 전송함수 

			strcpy(output, L0_receive(&length));		//상대 L1에서 받은 메세지 받아오기 
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

// 패리티를 추가한 L0 전송 함수
void L0_send(char* input, int length)
{
	struct L0 data;  // L0 구조체 선언
	char temp[350];
	int size = 0;
	int address[4];
	int i;

	Parse(L0_saddr, address);  // L0 송신자 주소 파싱

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) {  // 송신자 주소 저장
		data.saddr[i] = address[i];
	}

	Parse(L0_daddr, address);  // L0 수신자 주소 파싱

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) {  // 수신자 주소 저장
		data.daddr[i] = address[i];
	}

	data.length = length;  // 데이터 길이 설정

	memset(data.L0_data, 0x00, MAX_SIZE);  // 데이터 메모리 초기화
	strcpy(data.L0_data, input);  // 입력 데이터를 L0_data에 복사

	// 패리티 계산 후 헤더에 추가
	bool isParity = getParity(data.L0_data);
	data.parrity = isParity ? 1 : 0;

	size = sizeof(struct L0) - sizeof(data.L0_data) + length;

	memset(temp, 0x00, 350);  // 임시 메모리 초기화
	memcpy(temp, (void*)&data, size);  // 구조체 데이터를 임시 메모리에 복사

	L1_send(temp, size);  // L1 계층으로 전송
}

void L1_send(char* input, int length)
{
	struct L1 data;			//L1 구조체
	char temp[350];
	int size = 0;
	int address[4];
	int i;

	Parse(L1_saddr, address);  // L1 송신자 주소 파싱 후 address 변수에 추가

	for (i = 0; i < sizeof(data.saddr) / sizeof(int); i++) { // L1 송신자 주소 저장
		data.saddr[i] = address[i];
	}

	Parse(L1_daddr, address); // L1 수신자 주소 파싱 후 address 변수에 추가

	for (i = 0; i < sizeof(data.daddr) / sizeof(int); i++) { //L1 수신자 주소 저장
		data.daddr[i] = address[i];
	}

	data.length = length;			//송수신자 주소값이 더해진  구조체 크기

	memset(data.L1_data, 0x00, MAX_SIZE);			//메모리 최대길이만큼 0비트로 초기화
	strcpy(data.L1_data, input);					//메모리에 입력값 전달

	size = sizeof(struct L1) - sizeof(data.L1_data) + length;			//

	memset(temp, 0x00, 350);						//메모리 초기화 
	memcpy(temp, (void*)&data, size);				//구조체 내용을 메모리에 복사

	L2_send(temp, size);					//L2에 구조체 내용저장
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

	memset(data.L2_data, 0x00, MAX_SIZE);			//메모리 초기화
	memcpy(data.L2_data, (void*)input, length);		//메모리에 저장

	size = sizeof(struct L2) - sizeof(data.L2_data) + length;		//헤더길이

	memset(temp, 0x00, 350);				//메모리 초기화
	memcpy(temp, (void*)&data, size);		//메모리에 저장
	L3_send(temp, size);					//L3으로 전달
}

void L3_send(char* data, int length)
{
	FILE* fp;
	char temp[300];

	memset(temp, 0x00, MAX_SIZE);				//메모리 초기화
	memcpy(temp, (void*)data, length);			//메모리에 저장
	fp = fopen("data.txt", "w");
	for (int i = 0; i < length; i++)
		fputc(temp[i], fp);			//txt 쓰기

	fclose(fp);
}

// 패리티 검증이 포함된 L0 수신 함수
char* L0_receive(int* length)
{
	struct L0* data;
	int address[4];
	int i;

	data = (struct L0*)L1_receive(length);  // L1에서 데이터 수신

	if (*length != 0) {
		*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);  // 실제 데이터 길이
	}

	Parse(L0_dest, address);  // L0 목적지 주소 파싱

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {  // 목적지 주소 일치 확인
		if (data->daddr[i] != address[i]) {
			printf("L0계층의 목적지 주소 불일치, 메시지 discard \n");
			data->L0_data[0] = '\0';
			*length = 0;
			return (char*)data->L0_data;
		}
	}

	// 패리티 검사
	bool receivedParity = data->parrity;
	bool calculatedParity = getParity(data->L0_data);

	if (receivedParity != calculatedParity) {
		printf("Parrity Check Result : Error, 메세지 discard \n");
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

	data = (struct L1*)L2_receive(length);			//L2에서 붙은 헤더파일 제거 

	if (*length != 0) {
		*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);			//실제 데이터의 길이 가져오기 
	}

	Parse(L1_dest, address);				//L1 수신 주소 가져오기

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {			// L1 수신 주소 검사
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

	data = (struct L2*)L3_receive(length);				//L3에서 붙은 헤더파일 제거 
	*length = *length - sizeof(data->daddr) - sizeof(data->length) - sizeof(data->saddr);			//실제 데이터의 길이 가져오기 

	Parse(L2_dest, address);

	for (i = 0; i < sizeof(data->daddr) / sizeof(int); i++) {				// 목적지 주소 검사
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

	while ((ch = fgetc(fp)) != EOF) {		//파일 읽어오기
		data[i] = ch;
		i++;
	}
	data[i] = '\n';
	*length = i;

	return data;
}

//구분자를 통해 주소값 int에 저장
void Parse(char* data, int* addr) {
	int i, j = 0, c = 0;
	char temp[30];
	for (i = 0; i < strlen(data); i++) { // 주소값에서 주소 구분자 '-' 또는 '.'을 기준으로 주소를 끊어서 파싱해준다.
		while (data[i] != '-' && data[i] != '.' && i < strlen(data)) {
			temp[j++] = data[i++];
		}
		temp[j] = '\0';
		j = 0;
		addr[c++] = atoi(temp);			//string -> int 
	}
}

// 문자열의 패리티를 계산하는 함수 (L0_data)
bool getParity(const char* data) {
	bool parity = 0;
	for (int i = 0; i < strlen(data); i++) {
		unsigned char byte = data[i];
		// 바이트 내 1의 개수를 세서 패리티 계산
		while (byte) {
			parity = !parity;
			byte &= (byte - 1);  // 가장 오른쪽 1을 제거
		}
	}
	return parity;
}
