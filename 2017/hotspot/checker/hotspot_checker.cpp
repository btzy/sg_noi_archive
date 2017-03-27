#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
void exitWithCode(int code){
    if (code == 0) printf("100\n");
    else printf("0\n");
    exit(0);
}
int main(int argc, char * argv[])
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[3], "r");
    FILE *testOutput = fopen(argv[2], "r");
	int testAns;
	if(fscanf(testOutput, "%d", &testAns) != 1){
		exitWithCode(1);
	}
	vector<int> allowedAns;
	int ansBuff;
	while(fscanf(output, "%d", &ansBuff) == 1){
		allowedAns.push_back(ansBuff);
	}
	if(find(allowedAns.begin(), allowedAns.end(), testAns) != allowedAns.end())
		exitWithCode(0);
	else exitWithCode(1);
}
