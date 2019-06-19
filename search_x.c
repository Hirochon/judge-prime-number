#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define T 200000000 /*2億をTとマクロ定義(Tの由来はtwoから)*/

int main(int argc, char **argv) 
{
	int i, j, pri/*素数*/, del=2/*候補削除*/, *pri_list/*素数リスト*/, *num_list/*素数候補リスト*/;
	int sq_t = sqrt(T)/*2億の平方根(整数)*/;
	int N = atoi(argv[1]);
	num_list = (int *)calloc(T + 1, sizeof(int)); /*➀:０と１～2億までの素数候補リスト(素数候補は0、違うなら１)*/
	pri_list = (int *)malloc(12000000 * sizeof(int)); /*素数リスト*/

	num_list[0] = num_list[1] = 1; /*０と１が素数でないのは自明*/

	j = 0; /*素数の個数 - 1*/
	pri_list[j] = 2; /*➁:２が素数であるのは自明*/
	for (i = 4; i <= T; i += 2) num_list[i] = 1; /*☆速度上昇のため2以降の2の倍数は先に素数リストから除外*/

	pri = 3; /*３が素数であるのは自明*/

	while (pri <= sq_t) /*エラトステネスの篩より平方根まで素数でない数を篩い落とす*/
	{
		del = pri * 2; /*上の☆にて２の倍数を削除済み。速度上昇のために素数の2倍を代入*/
		++j; /*素数の個数 - 1*/
		pri_list[j] = pri; /*➁'と➃:素数リストに素数を代入*/
		
		for (i = pri + del; i <= T; i += del) /*素数の2倍の倍数を使って、篩い落とす*/
		{
			num_list[i] = 1; /*➂:篩い落とし中*/
		}

		for (i = pri + 2; num_list[i] != 0; i += 2); /*素数探し*/
		pri = i; /*素数発見により代入*/
	}


	for (i = sq_t + 1; j < N - 1; i += 2) /*Nの平方根以降で、素数判定のものを素数リストに代入*/
	{
		if (num_list[i] == 0)
		{
			++j;
			pri_list[j] = i;
		}
	}

	printf("%d番目の素数は%dです。\n", N, pri_list[N-1]);

	free(num_list); 
	free(pri_list);

	return 0;
}