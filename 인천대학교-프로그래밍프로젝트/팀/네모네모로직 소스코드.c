#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>;
#pragma comment(lib,"winmm.lib");


static int mode; //�������� mode
static int level; //�������� level
int a[20][20] = { 0 };
int art[20][20] = { 0 };
int x = 0, y = 0;
int row[20][20] = { 0 };
int col[20][20] = { 0 };
int customrow[20][20] = { 0 };
int customcol[20][20] = { 0 };
//���� �迭�� Q
int easyQcol[20][20] = {
	{ 0,0,0,2,0, },
{ 0, 0, 1, 1, 0, },
{ 5,0,0,0,0, },
{ 0,0,1,1,0, },
{ 0,0,0,2,0, } };
int easyQrow[20][20] = {
	{ 0,0,0,1,5, },
{ 0,0,3,1,0 },
{ 1,1,0,1,0 },
{ 0,0,0,0,0 },
{ 0,0,0,0,0 }, };
int normalQcol[20][20] = {
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 2, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int normalQrow[20][20] = {
	{ 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 6, 1, 6, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 2, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 0, 0, 1, 0, 0, 0, 2, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

};
int hardQcol[20][20] = {
	{ 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 6, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 4, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 4, 2, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 0, 0, 1, 0, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 0, 0, 2, 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 2, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 },
{ 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
{ 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
{ 1, 0, 2, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
{ 2, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 },
{ 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 0, 2, 0, 0, 0, 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 3, 2, 0, 0, 0, 0, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 5, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

};
int hardQrow[20][20] = {
	{ 20, 9, 7, 5, 3, 5, 2, 2, 2, 2, 2, 2, 2, 2, 5, 4, 6, 8, 9, 20 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0 },
{ 0, 9, 0, 0, 0, 0, 3, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 1, 8, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 2, 0, 0, 0, 8, 0, 2, 2, 0, 0, 0, 0, 0, 1, 7, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 6, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 3, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 4, 5, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 4, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int userQcol[20][20] = { 0 };
int userQrow[20][20] = { 0 };

void drawEasy();
void drawNormal();
void drawHard();
void title(); // ���ʷ� �����Ǵ�ȭ��
void customGame(int level); // Ŀ���� ����
void gotoxy(int x, int y); // ��ǥ���̵�
void setCol(); // �Ʒ�������Ǿ��ִ� ����
void setRow(); // �����ʿ�����Ǿ��ִ� ����
void fillLogic(int level); // ����������� �׸�����
void answer(); // �ʱ�ȭ���� ������ ��ȯ�ϴ� �Լ�
void playGame(int level); // Ŀ���Ұ��ӿ� Ŀ���̵�
void playGamecustom();
void playGameforadventure();//��庥�� ���� Ŀ���̵�
void adventure(int level);//��庥�İ���
void selectLevel();//���������Լ�
void selectMode();//��弱���Լ�
void map(int level);//�ʱ׷��ִ� �Լ�
void custommap(int level);//Ŀ���Ҹʱ׷��ֱ�
void run();//��ü���� �����Լ�
void problem(int level);//��庥�Ŀ� ���� �Լ�
void customproblem(int level);
void initRowcol();//�ʱ�ȭ�Լ�
void initcustom();
void savecol();//Ŀ���� Į������
void saverow();//Ŀ���� �ο�����
void initA();

void initA() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			a[i][j] = 0;
		}
	}
}

void drawEasy() {
	for (int i = 0; i < 5; i++) {
		a[2][i] = 1;
		a[i][4] = 1;
	}
	a[1][2] = 1;
	a[3][2] = 1;
	a[0][3] = 1;
	a[4][3] = 1;
}
void drawNormal() {
	a[0][1] = 1;
	a[9][1] = 1;
	a[8][6] = 1;
	a[6][7] = 1;
	a[8][7] = 1;
	a[9][7] = 1;
	for (int i = 0; i < 3; i++) {
		a[i][0] = 1;
		a[i + 7][0] = 1;
		a[i + 2][1] = 1;
		a[i + 5][1] = 1;
		a[i + 2][2] = 1;
		a[i + 5][2] = 1;
		a[i + 2][3] = 1;
		a[i + 5][3] = 1;
		a[i + 2][4] = 1;
		a[i + 5][4] = 1;
		a[i + 2][5] = 1;
		a[i + 5][5] = 1;
		a[i + 2][6] = 1;
		a[i + 5][6] = 1;
		a[i+3][7] = 1;
		a[i+4][8] = 1;
		a[i+7][8] = 1;
		a[i+4][9] = 1;
		a[i+7][9] = 1;

	}
	a[3][3] = 0;
	a[6][3] = 0;
	a[4][5] = 0;
	a[5][8] = 0;
	a[6][8] = 0;
}
void drawHard() {
	for(int j=0;j<20;j++){
		for (int i = 0; i < 20; i++) {
			a[i][j] = 1;
		}
	}//��ĥ

	for (int i = 0; i < 2; i++) {
		a[i + 9][1] = 0;
		a[i + 2][6] = 0;
		a[i + 16][6] = 0;
		a[i + 8][9] = 0;
		a[i + 8][10] = 0;
		a[i + 2][11] = 0;
		a[i + 2][12] = 0;
		a[i + 8][17] = 0;
		a[i + 11][16] = 0;
		a[i + 11][17] = 0;
	}//���麯ȯ2

	for (int i = 0; i < 4; i++) {
		a[i + 5][3] = 0;
		a[i + 2][7] = 0;
		a[i + 14][7] = 0;
		a[i + 2][8] = 0;
		a[i + 6][8] = 0;
		a[i + 2][9] = 0;
		a[i + 2][10] = 0;
		a[i + 6][11] = 0;
		a[i + 6][12] = 0;
		a[i + 6][16] = 0;
		a[i + 14][9] = 0;
		a[i + 14][10] = 0;
		a[i + 11][11] = 0;
		a[i + 11][12] = 0;
		a[i + 11][15] = 0;
	}//���麯ȯ4

	for (int i = 0; i < 5; i++) {
		a[i + 11][4] = 0;
		a[i + 5][5] = 0;
		a[i + 10][5] = 0;
		a[i + 5][13] = 0;
		a[i + 5][14] = 0;
		a[i + 5][14] = 0;
		a[i + 11][14] = 0;
	}//���麯ȯ5

	for (int i = 0; i < 6; i++) {
		a[i+7][2] = 0;
		a[i+11][3] = 0;
		a[i + 3][4] = 0;
		a[i + 7][6] = 0;
		a[i + 11][8] = 0;
		a[i + 4][15] = 0;
		a[i + 11][13] = 0;
		
	}//���麯ȯ6

	a[13][2] = 0;
	a[17][5] = 0;
	a[17][8] = 0;
	a[2][13] = 0;
	a[9][18] = 0;
	a[13][16] = 0;
	a[11][18] = 0;
	a[11][9] = 0;
	a[11][10] = 0;
	a[17][11] = 0;
	a[17][12] = 0;
}
void fillLogic(int level) {
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	x = 0;
	y = 0;
	gotoxy(x, y);
	for (int j = 0; j < level; j++) {
		for (int i = 0; i < level; i++) {
			gotoxy(j * 2, i);
			if (a[j][i] == 1)
				printf("��");
			else if (a[j][i] == 0 || a[j][i] == 3) {
				printf("��");
			}
		}
	}
}
void answer() {
	//test ������  �Ʒ� Į��, �ο� ǥ�ø� �����
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			gotoxy(40 + 2 * j, i);
			printf("                                 ");
			gotoxy(2 * j, 20 + i);
			printf("  ");
		}
	}
	//row,col �迭 �ʱ�ȭ
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			row[i][j] = 0;
			col[i][j] = 0;
		}
	}
	setRow();
	setCol();
}
void setRow() {
	int count = 0;//�������� 1�̸� count++
	int temp = 0;//col���� �ߺ����� ������� �ʰ�
	for (int i = 0; i < 20; i++) {
		count = 0;
		for (int j = 0; j < 20; j++) {
			//������ ĭ�϶�
			if (j == 19) {
				if (a[j][i] == 1) {
					row[temp][i] = ++count;
				}
				else
					row[temp][i] = count;
			}
			else if (a[j][i] == 1) {
				count++;
			}
			else {
				row[temp][i] = count;
				temp++;
				count = 0;
			}
		}
		temp = 0;
	}
	//row ��� ���
	if (level == 20 && mode == 2) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (row[j][i] != 0) {
					gotoxy(62 + (3 * temp), i);
					printf("%d ", row[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
	}
	else if (level == 20 && mode == 1) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (row[j][i] != 0) {
					gotoxy(82 + (3 * temp), i);
					printf("%d ", row[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (row[j][i] != 0) {
					gotoxy(42 + (3 * temp), i);
					printf("%d ", row[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
	}
}
void setCol() {
	int count = 0;//�������� 1�̸� count
	int temp = 0;//row���� �ߺ����� ������� �ʰ�
	for (int i = 0; i < 20; i++) {
		count = 0;
		for (int j = 0; j < 20; j++) {
			//������ ĭ�϶�
			if (j == 19) {
				if (a[i][j] == 1)
					col[i][temp] = ++count;
				else
					col[i][temp] = count;
			}
			else if (a[i][j] == 1) {
				count++;
			}
			else {
				col[i][temp] = count;
				temp++;
				count = 0;
			}
		}
		temp = 0;
	}
	//col ���
	if (level == 20) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (col[i][j] != 0) {
					gotoxy(i * 2, 27 + temp);
					printf("%2d", col[i][j]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (col[i][j] != 0) {
					gotoxy(i * 2, 21 + temp);
					printf("%2d", col[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
}
void initRowcol() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			row[i][j] = 0;
			col[i][j] = 0;
			a[i][j] = 0;
		}
	}
}
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void customGame(int level) {
	custommap(level);
	playGame(level);
}
void adventure(int level) {
	system("cls");
	initRowcol();
	map(level);
	playGameforadventure();
}
void map(int level) {
	system("cls");
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	int i;
	int j;
	x = 0, y = 0;
	gotoxy(x, y);
	for (j = 0; j < level; j++) {
		for (i = 0; i < level; i++) {
			printf("��");
		}
		y++;
		gotoxy(x, y);
	}
	gotoxy(60, 20);
	printf("�׸�׸���� ver 1.0");
	gotoxy(60, 22);
	printf("[a�� ������ ������ �����մϴ�.]");
	gotoxy(60, 24);
	printf("[r�� ������ ������ �����մϴ�.]");
	gotoxy(60, 26);
	printf("[x�� ������ ����� ���� �� �ֽ��ϴ�.]");
	gotoxy(60, 28);
	if (level == 5) {
		printf("[Easy Mode]");
	}
	else if (level == 10) {
		printf("[Normal Mode]");
	}
	else if (level == 20) {
		printf("[Hard Mode]");
	}

}
void custommap(int level) {
	system("cls");
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	int i;
	int j;
	x = 0, y = 0;
	gotoxy(x, y);
	for (j = 0; j < level; j++) {
		for (i = 0; i < level; i++) {
			printf("��");
		}
		y++;
		gotoxy(x, y);
	}
	gotoxy(60, 20);
	printf("�׸�׸���� ver 1.0");
	gotoxy(60, 22);
	printf("[a�� ������ ������ �����մϴ�.]");
	gotoxy(60, 24);
	printf("[r�� ������ ������ �����մϴ�.]");
	gotoxy(60, 26);
	printf("[x�� ������ ����� ���� �� �ֽ��ϴ�.]");
	gotoxy(60, 28);
	printf("[z�� ������ ����ȭ ��ų �� �ֽ��ϴ�.]");
	gotoxy(60, 30);
	if (level == 5) {
		printf("[Easy Mode]");
	}
	else if (level == 10) {
		printf("[Normal Mode]");
	}
	else if (level == 20) {
		printf("[Hard Mode]");
	}

}
void playGame(int level) {
	char curser;
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	while (1) {
		curser = _getch();
		switch (curser) {
		case 72:
			if (y - 1 != -1)
				y -= 1;
			break;
		case 75:
			if (x - 1 != -1)
				x -= 1;
			break;
		case 80:
			if (y + 1 != level)
				y += 1;
			break;
		case 77:
			if (x + 1 != level)
				x += 1;
			break;
		case 32:
			if (a[x][y] == 0 || a[x][y] == 3) {
				printf("��");
				a[x][y] = 1;
			}
			else if (a[x][y] == 1) {
				printf("��");
				a[x][y] = 0;
			}
			break;
		case 'x':
			if (a[x][y] == 0 || a[x][y] == 1) {
				printf("��");
				a[x][y] = 3;
			}
			else if (a[x][y] == 3) {
				printf("��");
				a[x][y] = 0;
			}
			break;

		case 'a':
			answer();
			break;

		case 'r':
			initRowcol();
			run();
			break;

		case 'z':
			savecol();
			saverow();
			map(level);
			initA();
			customproblem(level);
			playGamecustom();
			_getch();
			break;
		}
		gotoxy(x * 2, y);
	}
}
void problem(int level) {
	int temp = 0;
	if (level == 5) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (easyQrow[j][i] != 0) {
					gotoxy(12 + (3 * temp), i);
					printf("%d ", easyQrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (easyQcol[i][j] != 0) {
					gotoxy(i * 2, 6 + temp);
					printf("%2d", easyQcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
	else if (level == 10) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (normalQrow[j][i] != 0) {
					gotoxy(22 + (3 * temp), i);
					printf("%d ", normalQrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (normalQcol[i][j] != 0) {
					gotoxy(i * 2, 11 + temp);
					printf("%2d", normalQcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
	else if (level == 20) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (hardQrow[j][i] != 0) {
					gotoxy(42 + (3 * temp), i);
					printf("%d ", hardQrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (hardQcol[i][j] != 0) {
					gotoxy(i * 2, 21 + temp);
					printf("%2d", hardQcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
}
void customproblem(int level) {
	int temp = 0;
	if (level == 5) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customrow[j][i] != 0) {
					gotoxy(12 + (3 * temp), i);
					printf("%d ", customrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customcol[i][j] != 0) {
					gotoxy(i * 2, 6 + temp);
					printf("%2d", customcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
	else if (level == 10) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customrow[j][i] != 0) {
					gotoxy(22 + (3 * temp), i);
					printf("%d ", customrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customcol[i][j] != 0) {
					gotoxy(i * 2, 11 + temp);
					printf("%2d", customcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
	else if (level == 20) {
		//������easy ���� ���row
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customrow[j][i] != 0) {
					gotoxy(42 + (3 * temp), i);
					printf("%d ", customrow[j][i]);
					temp++;
				}
			}
			temp = 0;
			printf("\n");
		}
		//�Ʒ� easy ���� ��� col
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (customcol[i][j] != 0) {
					gotoxy(i * 2, 21 + temp);
					printf("%2d", customcol[i][j]);
					temp++;
				}
			}
			temp = 0;
		}
	}
}
void playGameforadventure() {
	int temp = 0;
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	problem(level);

	char curser;
	while (1) {
		curser = _getch();
		switch (curser) {
		case 72:
			if (y - 1 != -1)
				y -= 1;
			break;
		case 75:
			if (x - 1 != -1)
				x -= 1;
			break;
		case 80:
			if (y + 1 != level)
				y += 1;
			break;
		case 77:
			if (x + 1 != level)
				x += 1;
			break;
		case 32:
			if (a[x][y] == 0 || a[x][y] == 3) {
				printf("��");
				a[x][y] = 1;
			}
			else if (a[x][y] == 1) {
				printf("��");
				a[x][y] = 0;
			}
			break;
		case 'x':
			if (a[x][y] == 0 || a[x][y] == 1) {
				printf("��");
				a[x][y] = 3;
			}
			else if (a[x][y] == 3) {
				printf("��");
				a[x][y] = 0;
			}
			break;

		case 'a':
			answer();
			int judgeans = 0;//�������� Ȯ���ϴ� �Լ�.
			if (level == 5) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						if (row[i][j] != easyQrow[i][j] || col[i][j] != easyQcol[i][j]) {
							gotoxy(48, 24);
							printf("[X]");
							gotoxy(43, 25);
							printf("������ �ƴմϴ�.");
							judgeans++;
						}
					}
				}
			}

			if (level == 10) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						if (row[i][j] != normalQrow[i][j] || col[i][j] != normalQcol[i][j]) {
							gotoxy(48, 24);
							printf("[X]");
							gotoxy(43, 25);
							printf("������ �ƴմϴ�.");
							judgeans++;
						}
					}
				}
			}

			if (level == 20) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						if (row[i][j] != hardQrow[i][j] || col[i][j] != hardQcol[i][j]) {
							gotoxy(48, 24);
							printf("[X]");
							gotoxy(43, 25);
							printf("������ �ƴմϴ�.");
							judgeans++;
						}
					}
				}
			}

			if (judgeans == 0) {
				gotoxy(48, 24);
				printf("[O]");
				gotoxy(43, 25);
				printf(" ���� �Դϴ�.   ");
			}

			problem(level);

			break;

		case 'r':
			initA();
			if (level == 5) {
				drawEasy();
			}
			else if (level == 10) {
				drawNormal();
			}
			else if (level == 20) {
				drawHard();
			}
			
			fillLogic(level);
			Sleep(3000);
			run();
			break;



		}
		gotoxy(x * 2, y);
	}
}
void playGamecustom() {
	int temp = 0;
	if (level == 1) {
		level = 5;
	}
	else if (level == 2) {
		level = 10;
	}
	else if (level == 3) {
		level = 20;
	}
	customproblem(level);

	char curser;
	while (1) {
		curser = _getch();
		switch (curser) {
		case 72:
			if (y - 1 != -1)
				y -= 1;
			break;
		case 75:
			if (x - 1 != -1)
				x -= 1;
			break;
		case 80:
			if (y + 1 != level)
				y += 1;
			break;
		case 77:
			if (x + 1 != level)
				x += 1;
			break;
		case 32:
			if (a[x][y] == 0 || a[x][y] == 3) {
				printf("��");
				a[x][y] = 1;
			}
			else if (a[x][y] == 1) {
				printf("��");
				a[x][y] = 0;
			}
			break;
		case 'x':
			if (a[x][y] == 0 || a[x][y] == 1) {
				printf("��");
				a[x][y] = 3;
			}
			else if (a[x][y] == 3) {
				printf("��");
				a[x][y] = 0;
			}
			break;

		case 'a':
			answer();
			int judgeans = 0;//�������� Ȯ���ϴ� �Լ�.
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (row[i][j] != customrow[i][j] || col[i][j] != customcol[i][j]) {
						gotoxy(48, 24);
						printf("[X]");
						gotoxy(43, 25);
						printf("������ �ƴմϴ�.");
						judgeans++;
					}
				}
			}

			if (judgeans == 0) {
				gotoxy(48, 24);
				printf("[O]");
				gotoxy(43, 25);
				printf(" ���� �Դϴ�.   ");
			}

			customproblem(level);

			break;

		case 'r':
			initcustom();
			run();
			break;

		}
		gotoxy(x * 2, y);
	}
}
void selectLevel() {
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("�������������̵��� �������ּ���.\n����������1: 5 X 5    2: 10 X 10    3: 20 X 20 >>");
	scanf_s("%d", &level);
}
void title() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("�����������ࡡ���������ࡡ�ࡡ�������ࡡ�������ࡡ�����ࡡ�ࡡ\n");
	printf("�����������ࡡ���������ࡡ�ࡡ���ࡡ�����ࡡ����������ࡡ�����ࡡ�����ࡡ\n");
	printf("�����������ࡡ���������ࡡ�ࡡ�������ࡡ�������ࡡ������  �ࡡ���ࡡ\n");
	printf("�����������ࡡ������ࡡ�ࡡ�������ࡡ�����������ࡡ�������������ࡡ\n");
	printf("�����������ࡡ���������ࡡ�ࡡ�������ࡡ�����������ࡡ�����������ࡡ\n");
	printf("��������������ࡡ����  �ࡡ�������ࡡ�������ࡡ�������������ࡡ\n");
	printf("\n");
	printf("��������������������������������Ϸ��� �ƹ�Ű�� �����ʽÿ�.������������������\n");
	_getch();
}
void selectMode() {

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("������������带 �����ϼ���\n����������1:Custom    2:Adventure >> ");
	scanf_s("%d", &mode);
}
void run() {
	system("cls");
	selectMode();
	selectLevel();
	if (mode == 1) {
		customGame(level);
	}
	else if (mode == 2) {
		adventure(level);
	}
}
void savecol() {
	int count = 0;//�������� 1�̸� count
	int temp = 0;//row���� �ߺ����� ������� �ʰ�
	for (int i = 0; i < 20; i++) {
		count = 0;
		for (int j = 0; j < 20; j++) {
			//������ ĭ�϶�
			if (j == 19) {
				if (a[i][j] == 1)
					customcol[i][temp] = ++count;
				else
					customcol[i][temp] = count;
			}
			else if (a[i][j] == 1) {
				count++;
			}
			else {
				customcol[i][temp] = count;
				temp++;
				count = 0;
			}
		}
		temp = 0;
	}
}
void saverow() {
	int count = 0;//�������� 1�̸� count++
	int temp = 0;//col���� �ߺ����� ������� �ʰ�
	for (int i = 0; i < 20; i++) {
		count = 0;
		for (int j = 0; j < 20; j++) {
			//������ ĭ�϶�
			if (j == 19) {
				if (a[j][i] == 1) {
					customrow[temp][i] = ++count;
				}
				else
					customrow[temp][i] = count;
			}
			else if (a[j][i] == 1) {
				count++;
			}
			else {
				customrow[temp][i] = count;
				temp++;
				count = 0;
			}
		}
		temp = 0;
	}
}
void initcustom() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			customrow[i][j] = 0;
			customcol[i][j] = 0;
			a[i][j] = 0;
		}
	}
}
int main() {
	PlaySound(TEXT("C:\\Users\\user\\Downloads\\bgm.wav"), NULL, SND_ASYNC | SND_LOOP);
	title();
	run();
	gotoxy(x, y);
	system("pause");
	return 0;
}
