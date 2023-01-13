#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int composition, m, sentenceNum;

int classified[100];
double Begin[501];

double T[501][501];
double M[501][501];

int choice[102][502];
double cache[102][502];

string word[501]; 

double recognize(int segment, int previousMatch){
    if (segment == composition) return 0;
    double  &result = cache[segment][previousMatch];
    if (result != 1.0)return result;

    result = -1e200; 

    int &choose = choice[segment][previousMatch];

    for (int thisMatch = 1; thisMatch <= m; thisMatch++){
        double candidate = T[previousMatch][thisMatch] 
                           + M[thisMatch][classified[segment]]
                           + recognize(segment + 1, thisMatch);

        if (result < candidate){
                result = candidate;
                choose = thisMatch;        
        }    

    }
    return result;
}


string reconstruct(int segment, int previousMatch){
    int choose = choice[segment][previousMatch];
    string result = word[choose];
    if (segment < composition - 1) result += " " + reconstruct(segment + 1, choose);
    return result;
}


void initialize(){
    for (int i = 0; i < composition; i++){
        memset(cache[i] , 1.0,502);
    }   
}

 

int main(void){
    FASTIO;
    cin >> m >> sentenceNum;

    for (int i = 1; i <= m; i++) cin >> word[i];
    

    for (int i = 1; i <= m; i++){
        cin >> Begin[i];
        Begin[i] = log(Begin[i]); 
    }    

    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if (i == 0) T[i][j] = Begin[j];
            else {
                  cin >> T[i][j];
                  T[i][j] = log(T[i][j]);       
                }                           
        }
    }    

    for(int i=1; i<= m; i++){
        for (int j = 1; j <= m; j++){
            cin >> M[i][j];
            M[i][j] = log(M[i][j]);                 
        }                   
    }
    
    for (int i = 0; i < sentenceNum; i++){
        cin >> composition;

        if (composition < 1 || composition>100) exit(-1);

        initialize();

        for (int i = 0; i < composition; i++){
            string input;
            cin >> input;

            for (int j = 1; j <= m; j++){

                if (input == word[j]){
                    classified[i] = j;
                    break;
                }
            }           

        }
        recognize(0, 0);
        cout << reconstruct(0, 0) << endl;            
    }
    return 0;
}