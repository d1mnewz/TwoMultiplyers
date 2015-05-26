#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <fstream>
using namespace std;
typedef pair<int, int> MyPair;
bool inFile(map<_int64, int> inputMap)
	{
				ofstream fout("resultFile.txt");
				fout << "Result File starts here..." << endl;
				map<_int64, int >::iterator itCur = inputMap.begin();
				map<_int64, int >::const_iterator itEnd = inputMap.end();
				while( itCur != itEnd )
				{

					fout << "Digit -  " << itCur->first << " :: Count of ways - " << itCur->second << endl;
					++itCur;
				}
				cout << "In!" << endl;
				fout << "Result File finishs here..." << endl;
				fout.close();
				return true;
	}
void showMapInFile(map<_int64, int> inputMap)
	{
			map<_int64, int >::iterator itCur = inputMap.begin();
			map<_int64, int >::const_iterator itEnd = inputMap.end();
			while( itCur != itEnd )
			{

				cout << "Digit -  " << itCur->first << " :: Count of ways - " << itCur->second << endl;
				++itCur;
			}
			inFile(inputMap);
	}

int Result(int K)
	{
		_int64 res = 1;
		float t = clock();
		vector<int> dividers;
		map<_int64, int> resultsMap;

		while (true)
		{
			dividers.clear();

			for(int i = 1; i <= res / 2; ++i)
			{
				if(res % i == 0) 
				{
					dividers.push_back(i);
				}
			}
			dividers.push_back(res);

			resultsMap.insert(MyPair(res, (dividers.size() + 1) / 2));
		

			if((dividers.size() + 1) / 2  == K)
			{
				t = ((clock() - t) ) ;
				showMapInFile(resultsMap);
				cout << "time :  " << (float)t/CLOCKS_PER_SEC << "sec"<< endl;
				

		
			return res;
		}
			res++;
	}
	}


void main()
{
		int k;
		cout << "Enter K: ";
		cin >> k;
		int N = Result(k);
		cout << endl << "Result: " << N << endl;
}




