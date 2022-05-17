#include <stdio.h>
#include <string.h>
//����ü: ������ ��Ƽ� ���ο� Ÿ���� ������.
struct Status //12
{
	int nHP;
	int nStr;
	int nDef;
};
//����ü�� �޸𸮸� �Ҵ��Ҷ� ũ�Ⱑ 4�� �Ҵ�ǹǷ� ũ�⸦ ������ 4�� ����� �̿��ؾ��Ѵ�.
//�� ���� �޸𸮸� ����� �޸𸮿� ������� ���� ��뷮�� ����. EX) 9,10,11,12 -> 32
struct RPGPlayer //28
{
	char strName[8]; //8
	Status sStatus; //12
	int nExp; //4
	int nLv; //4
};
//���������� �ʱ�ȭ�ϰ� �����Ͽ� ������ ���� ������.
RPGPlayer InitRPGPlayer(const char* name, int hp, int str, int def, int exp)
{
	RPGPlayer player;
	strcpy(player.strName, name);
	player.sStatus.nHP = hp;
	player.sStatus.nStr = str;
	player.sStatus.nDef = def;
	player.nLv = 1;
	player.nExp = exp;
	return player;
}
//������ �����Ͽ� ����� ���� �����Ѵ�.
void InitRPGPlayerRef(RPGPlayer& player, const char* name, int hp, int str, int def, int exp)
{
	strcpy(player.strName, name);
	player.sStatus.nHP = hp;
	player.sStatus.nStr = str;
	player.sStatus.nDef = def;
	player.nLv = 1;
	player.nExp = exp;
}
void InitRPGPlayerPtr(RPGPlayer* pPlayer, const char* name, int hp, int str, int def, int exp)
{
	strcpy(pPlayer->strName, name);
	pPlayer->sStatus.nHP = hp;
	pPlayer->sStatus.nStr = str;
	pPlayer->sStatus.nDef = def;
	pPlayer->nLv = 1;
	pPlayer->nExp = exp;
}
void PrintRPGPlayer(RPGPlayer& player)
{
	printf("########### %s ##########\n", player.strName);
	printf("HP:%d\n", player.sStatus.nHP);
	printf("STR:%d\n", player.sStatus.nStr);
	printf("DEF:%d\n", player.sStatus.nDef);
	printf("Lv/Exp:%d/%d\n", player.nLv, player.nExp);
}
void RPGPlayerDataSaveText(RPGPlayer& player)
{
	FILE* pFile;
	char strFileName[1024];
	sprintf(strFileName, "%s.txt", player.strName);
	pFile = fopen(strFileName, "w+");

	if (pFile)
	{
		fprintf(pFile, "%s\n", player.strName);
		fprintf(pFile, "%d\n", player.sStatus.nHP);
		fprintf(pFile, "%d\n", player.sStatus.nStr);
		fprintf(pFile, "%d\n", player.sStatus.nDef);
		fprintf(pFile, "%d/%d\n", player.nLv, player.nExp);
		fclose(pFile);
	}
}
void RPGPlayerDataLoadText(RPGPlayer& player)
{
	FILE* pFile;
	char strFileName[1024];
	sprintf(strFileName, "%s.txt", player.strName);
	pFile = fopen(strFileName, "r+");

	if (pFile)
	{
		fscanf(pFile, "%s\n", player.strName);
		fscanf(pFile, "%d\n", &player.sStatus.nHP);
		fscanf(pFile, "%d\n", &player.sStatus.nStr);
		fscanf(pFile, "%d\n", &player.sStatus.nDef);
		fscanf(pFile, "%d/%d\n", &player.nLv, &player.nExp);
		fclose(pFile);
	}
}
void RPGPlayerDataSaveBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "wb");

	if (pFIle)
	{
		fwrite((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGPlayerDataLoadBinary(RPGPlayer& player)
{
	FILE* pFIle;
	char strFileName[1024];
	sprintf(strFileName, "%s.dat", player.strName);
	pFIle = fopen(strFileName, "rb");

	if (pFIle)
	{
		fread((void*)&player, sizeof(player), 1, pFIle);
		fclose(pFIle);
	}
}
void RPGDataSaveLoadTestMain()
{
	RPGPlayer sPlayer;
	//InitRPGPlayer(sPlayer, "Player", 100, 10, 5, 0);
	//sPlayer = InitRPGPlayer("Player", 100, 10, 5, 0);
	InitRPGPlayerPtr(&sPlayer, "Player", 100, 10, 5, 0);
	printf("### Init ####\n");
	PrintRPGPlayer(sPlayer);
	printf("### Save ####\n");
	//RPGPlayerDataSaveText(sPlayer);
	RPGPlayerDataSaveBinary(sPlayer);
	printf("### Inc Def ####\n");
	sPlayer.sStatus.nDef += 10;
	PrintRPGPlayer(sPlayer);
	printf("### Load ####\n");
	RPGPlayerDataLoadBinary(sPlayer);
	//RPGPlayerDataLoadText(sPlayer);
	PrintRPGPlayer(sPlayer);
}
//�ؽ�Ʈ����: ����ڰ� �ؽ�Ʈ�� ������ ������ Ȯ���Ҽ��ִ� ����.
void TextFileWriteMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "w+"); //���Ͽ��� ������
	if (pOpenFile)
	{
		fprintf(pOpenFile, "Gamp14WriteFile");
		fprintf(pOpenFile, "Test");
		fclose(pOpenFile);
	}
}
void TextFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.txt", "r+"); //���Ͽ��� �б���
	char filestream[1024];
	if (pOpenFile)
	{
		fscanf(pOpenFile, "%s", filestream);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}
void BinaryFileWriteMain()
{
	char strBuffer[1024] = "Gamp14TestBinaryFile";
	FILE* pOpenFile = fopen("test.dat", "wb");

	if (pOpenFile)
	{
		fwrite(strBuffer, sizeof(char), 1024, pOpenFile);
		fclose(pOpenFile);
	}
}
void BinaryFileReadMain()
{
	FILE* pOpenFile;
	pOpenFile = fopen("test.dat", "rb"); //���Ͽ��� ���̳ʸ�
	char filestream[1024];
	if (pOpenFile)
	{
		fread(filestream, sizeof(char), 1024, pOpenFile);
		printf("file stream:%s\n", filestream);
		fclose(pOpenFile);
	}
}
void StructSizeTestMain()
{
	printf("StatusSize:%d\n", sizeof(Status));
	printf("RPGPlayerSize:%d\n", sizeof(RPGPlayer));
}
void main()
{
	//StructSizeTestMain();
	//TextFileWriteMain();
	//TextFileReadMain();
	//BinaryFileWriteMain();
	//BinaryFileReadMain();
	RPGDataSaveLoadTestMain();
}