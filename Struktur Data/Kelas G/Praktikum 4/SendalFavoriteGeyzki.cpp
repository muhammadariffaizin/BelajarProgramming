#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main () {
	int mysandal, N, X, a, b;

	map <int, string> urutan;
	map <string, string> take;

	stack <string> rak;
    string sandal_Geyzki = "Choco Banana";
	string sandal;

	cin>> N;
	for (a=0; a < N; a++)
		getline (cin>> ws, urutan[a]);

	cin >> X;
	for (b=0; b < X; b++) {
		getline (cin >> ws, sandal);
		rak.push(sandal);
	}

	for (a=0; a < N; a++)
    {
		if ((take.count(urutan[a]) == 0))
		{		                                    //Check if the person is not take the sandal
			if(rak.top() == sandal_Geyzki)
            {		                                ///Check if the top of rak is "Choco Banana"
				rak.pop();							//Pop, then Geyzki can take his sandal
				mysandal = 1;

				take[urutan[a]] = rak.top();		//Keep sandal which was took to stack
				rak.pop();
				cout << "Geyzki mengambil sendalnya sebelum " << urutan[a] <<" datang!"<< endl;
			}

			else
			{		       							//Check if the top of rak is "Choco Banana"
				take[urutan[a]] = rak.top();		//Keep sandal which was took to map
				rak.pop();
			}
		}

		else if (take.count(urutan[a]) != 0)
		{
			if (mysandal == 1)
			{					                    //Gezyki will put his sandal again
				rak.push(sandal_Geyzki);			//keep his sandal to stack
				mysandal = 0;
			}
			rak.push(take[urutan[a]]);
			take.erase(urutan[a]);					//remove sandal from map
		}
	}

	return 0;
}
